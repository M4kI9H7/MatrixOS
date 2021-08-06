#include "MatrixOS.h"

namespace MatrixOS::USB
{
    void Init()
    {
        tusb_init();
    }

    bool Inited()
    {
        return tusb_inited();
    }

    bool Connected()
    {
        return tud_ready();
    }

    void Poll()
    {
        tud_task();
    }

    namespace CDC
    {
        uint32_t Available()
        {
            return tud_cdc_n_write_available(0);
        }

        void Poll(void)
        {
            //TODO
        }

        void Print(char const* str)
        {
            tud_cdc_n_write_str(0, str);
            tud_cdc_n_write_flush(0);
        }

        void Println(char const* str)
        {
            tud_cdc_n_write_str(0, str);
            tud_cdc_n_write_str(0, "\r");
            tud_cdc_n_write_flush(0);
        }

        // void (*handler)(char const*) = nullptr;

        // void Read() //Prob won't work, implentation need work
        // {
        //     if (tud_cdc_n_available(0))
        //     {
        //         char buf[256];
        //         uint32_t count = tud_cdc_n_read(itf, buf, sizeof(buf));
        //         if(handler)
        //         {
        //             handler(buf); 
        //         }
        //     }
        // }

        // void SetHandler(void (*handler)(char const*))
        // {
        //     CDC::handler = handler;
        // }
    }

    namespace MIDI
    {
        void Init(void)
        {
            ClearAllHandler();
        }

        void Poll(void)
        {
            uint8_t packet[4];
            while(tud_midi_available())
            {
                tud_midi_packet_read(packet);
                DispatchPacket(packet);
            }
        }

        void (* handlers[HandlerCount])() = {nullptr};

        void SetHandler(Status status, void (*handler)())
        {
            handlers[status] = handler;
        }

        void ClearHandler(Status status)
        {
            handlers[status] = nullptr;
        }

        void ClearAllHandler(void)
        {
            for(uint16_t i = 0; i < HandlerCount; i++)
            {
               handlers[i] = nullptr;  
            }
        }

        void CallHandler(Status status, uint32_t value1, uint32_t value2, uint32_t value3)
        {
            if(handlers[status])
            {
                switch(status)
                {
                    case NoteOn:
                    case NoteOff:
                    case AfterTouch:
                    case ControlChange:
                        ((void (*)(uint8_t, uint8_t, uint8_t))(handlers[status]))(value1, value2, value3);
                        break;
                    case ProgramChange:
                    case ChannelPressure:
                        ((void (*)(uint8_t, uint8_t))(handlers[status]))(value1, value2);
                        break;
                    case PitchChange:
                        ((void (*)(uint8_t, uint16_t))(handlers[status]))(value1, value2);
                        break;
                    case SongSelect:
                        ((void (*)(uint8_t))(handlers[status]))(value1);
                        break;
                    case SongPosition:
                        ((void (*)(uint16_t))(handlers[status]))(value1);
                        break;
                    case TuneRequest:
                    case Sync:
                    case Start:
                    case Continue:
                    case Stop:
                    case ActiveSense:
                    case Reset:
                        ((void (*)())(handlers[status]))();
                        break;
                    case SysexData:
                    case SysexEnd:
                        //TODO: Need to determain if sysex is system level or application level
                        break;
                }
            }
        }

        void DispatchPacket(uint8_t packet[4])
        {
            switch (packet[0]) 
            {
                case CIN_SYSEX:
                    CallHandler(SysexData, packet[1]);
                    CallHandler(SysexData, packet[2]);
                    CallHandler(SysexData, packet[3]);
                break;
                case CIN_SYSEX_ENDS_IN_1:
                    CallHandler(SysexData, packet[1]);
                    CallHandler(SysexEnd);
                    break;
                case CIN_SYSEX_ENDS_IN_2:
                    CallHandler(SysexData, packet[1]);
                    CallHandler(SysexData, packet[2]);
                    break;
                case CIN_SYSEX_ENDS_IN_3:
                    CallHandler(SysexData, packet[1]);
                    CallHandler(SysexData, packet[2]);
                    CallHandler(SysexData, packet[3]);
                    CallHandler(SysexEnd);
                    break;
                case CIN_3BYTE_SYS_COMMON:
                    if (packet[1] == MIDIv1_SONG_POSITION_PTR) 
                        CallHandler(SongPosition, ((uint16_t)packet[3])<<7|((uint16_t)packet[2]));
                    break;

                case CIN_2BYTE_SYS_COMMON:
                    switch (packet[1]) {
                        case MIDIv1_SONG_SELECT:
                            CallHandler(SongSelect, packet[2]);
                            break;
                        case MIDIv1_MTC_QUARTER_FRAME:
                            // reference library doesnt handle quarter frame.
                            break;
                    }
                    break;
                case CIN_NOTE_OFF:
                    CallHandler(NoteOff, MIDIv1_VOICE_CHANNEL(packet[1]), packet[2], packet[3]);
                    break;
                case CIN_NOTE_ON:
                    CallHandler(NoteOn, MIDIv1_VOICE_CHANNEL(packet[1]), packet[2], packet[3]);
                    break;
                case CIN_AFTER_TOUCH:
                    CallHandler(AfterTouch, MIDIv1_VOICE_CHANNEL(packet[1]), packet[2], packet[3]);
                    break;
                case CIN_CONTROL_CHANGE:
                    CallHandler(ControlChange, MIDIv1_VOICE_CHANNEL(packet[1]), packet[2], packet[3]);
                    break;
                case CIN_PROGRAM_CHANGE:
                    CallHandler(ProgramChange, MIDIv1_VOICE_CHANNEL(packet[1]), packet[2]);
                    break;
                case CIN_CHANNEL_PRESSURE:
                    CallHandler(ChannelPressure, MIDIv1_VOICE_CHANNEL(packet[1]), packet[2]);
                    break;
                            
                case CIN_PITCH_WHEEL:
                    CallHandler(PitchChange, MIDIv1_VOICE_CHANNEL(packet[1]), ((uint16_t)packet[3])<<7|((uint16_t)packet[2]));
                    break;
                case CIN_1BYTE:
                    switch (packet[1]) 
                    {
                        case MIDIv1_CLOCK:
                            CallHandler(Sync);
                            break;
                        case MIDIv1_TICK:
                            break;
                        case MIDIv1_START:
                            CallHandler(Start);
                            break;
                        case MIDIv1_CONTINUE:
                            CallHandler(Continue);
                            break;
                        case MIDIv1_STOP:
                            CallHandler(Stop);
                            break;
                        case MIDIv1_ACTIVE_SENSE:
                            CallHandler(ActiveSense);
                            break;
                        case MIDIv1_RESET:
                            CallHandler(Reset);
                            break;
                        case MIDIv1_TUNE_REQUEST:
                            CallHandler(TuneRequest);
                            break;
                        default:
                            break;
                    }
                    break;
            }
        }

        void SendNoteOff(uint8_t channel, uint8_t note, uint8_t velocity)
        {

        }

        void SendNoteOn(uint8_t channel, uint8_t note, uint8_t velocity)
        {

        }
    }
}