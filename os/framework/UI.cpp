#include "UI.h"

UI::UI(string name, Color color)
{
    this->name = name;
    this->nameColor = color;
}

//TODO, make new led layer
void UI::Start()
{
    MatrixOS::KEYPAD::Clear();
    Setup();
    while(status != -1)
    {   
        LoopTask();
        Loop();
        RenderUI();
    }
    End();
    MatrixOS::LED::Fill(0);
}

void UI::Exit()
{
    status = -1;
}

void UI::LoopTask()
{
    GetKey();
    GetMidi();
}

void UI::RenderUI()
{   
    if(uiTimer.Tick(uiFps))
    {
        MatrixOS::LED::Fill(0);
        for (auto const& uiElementPair : uiElementMap)
        {   
            Point xy = uiElementPair.first;
            UIElement* uiElement = uiElementPair.second;
            uiElement->Render(xy);
        }
        Render();
        MatrixOS::LED::Update();
    }
}

void UI::GetKey()
{
    while(MatrixOS::KEYPAD::Available())
    {   
        uint16_t keyID = MatrixOS::KEYPAD::Get();
        KeyInfo keyInfo = MatrixOS::KEYPAD::GetKey(keyID);
        // MatrixOS::Logging::LogDebug("UI", "Key Event %d %d", keyID, keyInfo.state);
        bool action = KeyEvent(keyID, keyInfo);
        if(!action)
            UIKeyEvent(keyID, keyInfo);
        else
            MatrixOS::Logging::LogDebug("UI", "KeyEvent Skip: %d", keyID);
    }
}

void UI::UIKeyEvent(uint16_t keyID, KeyInfo keyInfo)
{
    MatrixOS::Logging::LogDebug("UI Key Event", "%d - %d", keyID, keyInfo.state);
    if(keyID == FUNCTION_KEY)
    {
        if(!disableExit && keyInfo.state == ((func_hold_callback == nullptr) ? PRESSED : RELEASED))
        {
            MatrixOS::Logging::LogDebug("UI", "Function Key Exit");
            Exit();
            return;
        }

        if(keyInfo.state == HOLD)
        {
            MatrixOS::Logging::LogDebug("UI", "Function Hold");
            func_hold_callback();
            PostCallbackCleanUp();
            return;
        }
    }
    Point xy = MatrixOS::KEYPAD::ID2XY(keyID);
    if(xy)
    {
        MatrixOS::Logging::LogDebug("UI", "UI Key Event X:%d Y:%d", xy.x, xy.y);
    }
    if(xy && uiElementMap.count(xy)) //Key Found
    {   
        if(keyInfo.state == RELEASED && keyInfo.hold == false) 
        {
            if(uiElementMap[xy]->Callback())
            {
                MatrixOS::Logging::LogDebug("UI", "Key Event Callback");
                PostCallbackCleanUp();
                return;
            }
        }
        else if(keyInfo.state == HOLD)
        {
            if(uiElementMap[xy]->HoldCallback())
            {
                PostCallbackCleanUp();
                return;
            }
            else
            {
                MatrixOS::UIComponent::TextScroll(uiElementMap[xy]->GetName(), uiElementMap[xy]->GetColor());
            }
        }
    }
    else
    {
        // MatrixOS::Logging::LogDebug("UI", "Key Event %d", keyID);
    }
}

void UI::GetMidi()
{
    while(MatrixOS::MIDI::Available())
    {
        MidiEvent(MatrixOS::MIDI::Get());
    }
}

void UI::AddUIElement(UIElement* uiElement, Point xy)
{
    ESP_LOGI("Add UI Element", "%d %d %s", xy.x, xy.y, uiElement->GetName().c_str());
    // uiElements.push_back(uiElement);
    uiElementMap[xy] = uiElement;
}

void UI::AddUIElement(UIElement* uiElement, uint16_t count, ...)
{
    // uiElements.push_back(uiElement);
    va_list valst;
    va_start(valst, count);
    for(uint8_t i = 0; i < count; i ++)
    {
        uiElementMap[(Point)va_arg(valst, Point)]  = uiElement;
    }
}

void UI::AddFuncKeyHold(std::function<void()> callback)
{
    func_hold_callback = callback;
}

void UI::ClearUIElements()
{
    uiElementMap.clear();
}

void UI::PostCallbackCleanUp()
{
    MatrixOS::KEYPAD::Clear();
}
