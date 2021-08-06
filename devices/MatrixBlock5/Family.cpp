#include "Device.h"

namespace Device
{
    void DeviceInit()
    {
        HAL_Init();
        SystemClock_Config();

        GPIO_Init();
        LED_Init();
    }

    void DeviceTask()
    {
        
    }

    void Bootloader()
    {
        
    }

    void Reboot()
    {
        NVIC_SystemReset();
    }

    void Delay(uint32_t interval)
    {
        HAL_Delay(interval);
    }

    uint32_t Millis()
    {
        return HAL_GetTick();
    }

    /**
     * @brief  System Clock Configuration
     *         The system Clock is configured as follow :
     *            System Clock source            = PLL (HSE)
     *            SYSCLK(Hz)                     = 72000000
     *            HCLK(Hz)                       = 72000000
     *            AHB Prescaler                  = 1
     *            APB1 Prescaler                 = 2
     *            APB2 Prescaler                 = 1
     *            HSE Frequency(Hz)              = 8000000
     *            HSE PREDIV1                    = 1
     *            PLLMUL                         = 9
     *            Flash Latency(WS)              = 2
     * @param  None
     * @retval None
     */
    void SystemClock_Config(void)
    {
        RCC_OscInitTypeDef RCC_OscInitStruct = {0};
        RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
        RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

        /** Initializes the RCC Oscillators according to the specified parameters
         * in the RCC_OscInitTypeDef structure.
         */
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
        RCC_OscInitStruct.HSIState = RCC_HSI_ON;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
        RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
        if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
        {
            ErrorHandler();
        }
        /** Initializes the CPU, AHB and APB buses clocks
         */
        RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                    |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
        RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
        RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
        RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

        if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
        {
            ErrorHandler();
        }
        PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
        PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
        if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
        {
            ErrorHandler();
        }
    }

    void ErrorHandler()
    {
        
    }
}

extern "C" {
    void USB_HP_IRQHandler(void)
    {
    tud_int_handler(0);
    }

    void USB_LP_IRQHandler(void)
    {
    tud_int_handler(0);
    }

    void USBWakeUp_IRQHandler(void)
    {
    tud_int_handler(0);
    }

    void SysTick_Handler(void)
    {
        HAL_IncTick();
    }

    void _init(void) {;}

    void NMI_Handler (void)
    {
        while(true){

        }
    }

    void HardFault_Handler (void)
    {
        while(true){

        }
    }

    void MemManage_Handler (void)
    {
        while(true){

        }
    }

    void BusFault_Handler (void)
    {
        while(true){

        }
    }

    void UsageFault_Handler (void)
    {
        while(true){

        }
    }

    void SVC_Handler (void)
    {
        while(true){

        }
    }

    void DebugMon_Handler (void)
    {
        while(true){

        }
    }

    void PendSV_Handler (void)
    {
        while(true){

        }
    }
    
}


