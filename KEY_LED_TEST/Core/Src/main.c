/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
  LED1 = 1,
  LED2 = 2,
  LED3 = 3,
  LED4 = 4
} LED_t;

typedef enum
{
  KEY1 = 1,
  KEY2 = 2,
  KEY3 = 3,
  KEY4 = 4
} KEY_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
bool led_state = false; // flase == off,true == on 
const uint32_t KEY_DEBOUNCE_MS = 20; // Debounce time in milliseconds
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void BSP_LED_Control(LED_t led, bool flag);
void BSP_Led_On(LED_t led);
void BSP_Led_Off(LED_t led);
bool BSP_KEY_IsPress(KEY_t key);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  // BSP_Led_On(LED1);
  // HAL_Delay(1000);

  // BSP_Led_On(LED2);
  // HAL_Delay(1000);

  // BSP_Led_On(LED3);
  // HAL_Delay(1000);

  // BSP_Led_On(LED4);
  // HAL_Delay(1000);
  HAL_Delay(5000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // version 3
    BSP_KEY_IsPress(KEY1) ? BSP_Led_On(LED1) : BSP_Led_Off(LED1);
    BSP_KEY_IsPress(KEY2) ? BSP_Led_On(LED2) : BSP_Led_Off(LED2);
    BSP_KEY_IsPress(KEY3) ? BSP_Led_On(LED3) : BSP_Led_Off(LED3);
    BSP_KEY_IsPress(KEY4) ? BSP_Led_On(LED4) : BSP_Led_Off(LED4);


    // // version 2-2
    // if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET)
    // {
    //   // Debonce
    //   HAL_Delay(50);
    //   if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET)
    //   {
    //     led_state = !led_state;
    //     HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, (led_state ? GPIO_PIN_RESET : GPIO_PIN_SET));
    //   }

    //   // Not only consider the action of the user pressing the button,but also the outcome of the user releasing it;
    //   while (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET)
    //   {
    //     // Wait for the user to release the button
    //   }
    // }

    // version 2-1
    //  if(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_10)==GPIO_PIN_RESET)
    //  {
    //    led_state = !led_state;
    //    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,(led_state ? GPIO_PIN_RESET : GPIO_PIN_SET));
    //  }

    // version 1
    //  //The switch has been pressed,turn on the LED
    //  if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET)
    //  {
    //    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);//Open-Drain mode,write 0 to turn on the LED
    //  }
    //  else
    //  {
    //    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
    //  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
    Error_Handler();
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
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10|GPIO_PIN_11, GPIO_PIN_SET);

  /*Configure GPIO pins : PF8 PF9 PF10 PF11 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PG6 PG7 PG8 PG10 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

// flag:true->turn on,false->turn off
void BSP_LED_Control(LED_t led, bool flag)
{
  GPIO_PinState state = flag ? GPIO_PIN_RESET : GPIO_PIN_SET;
  switch(led)
  {
    case LED1:
    {
      HAL_GPIO_WritePin(GPIOF,GPIO_PIN_8,state);
      break;
    }
    case LED2:
    {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, state);
      break;
    }
    case LED3:
    {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, state);
      break;
    }
    case LED4:
    {
      HAL_GPIO_WritePin(GPIOF, GPIO_PIN_11, state);
      break;
    }
  }
}

// The function of LED on,
// BSP: Board Support Package
void BSP_Led_On(LED_t led)
{
  BSP_LED_Control(led, true);
}

void BSP_Led_Off(LED_t led)
{
  BSP_LED_Control(led, false);
}

//About Key function
//When the key is pressed, the function returns true, otherwise it returns false.
//No debounce Version1
// bool BSP_KEY_IsPress(KEY_t key)
// {
//   bool ret=false;
//   switch(key)
//   {
//     case KEY1://PG10
//     {
//       ret = (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET);
//       break;
//     }
//     case KEY2://PG6
//     {
//       ret = (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6) == GPIO_PIN_RESET);
//       break;
//     }
//     case KEY3://PG8
//     {
//       ret = (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_8) == GPIO_PIN_RESET);
//       break;
//     }
//     case KEY4://PG7
//     {
//       ret = (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_7) == GPIO_PIN_RESET);
//       break;
//     }
//     default:
//       break;
//   }
//   return ret;
// }

//Debounce Version2
bool BSP_KEY_IsPress(KEY_t key)
{
  bool ret = false;
  switch (key)
  {
    case KEY1: // PG10
    {
      if(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET)
      {
        // Debounce
        HAL_Delay(KEY_DEBOUNCE_MS);
        if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_10) == GPIO_PIN_RESET)
        {
          ret = true;
        }
      }
      break;
    }
    case KEY2: // PG6
    {
      if(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6) == GPIO_PIN_RESET)
      {
        // Debounce
        HAL_Delay(KEY_DEBOUNCE_MS);
        if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6) == GPIO_PIN_RESET)
        {
          ret = true;
        }
      }
      break;
    }
    case KEY3: // PG8
    {
      if(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_8) == GPIO_PIN_RESET)
      {
        // Debounce
        HAL_Delay(KEY_DEBOUNCE_MS);
        if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_8) == GPIO_PIN_RESET)
        {
          ret = true;
        }
      }
      break;
    }
    case KEY4: // PG7
    {
      if(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_7) == GPIO_PIN_RESET)
      {
        // Debounce
        HAL_Delay(KEY_DEBOUNCE_MS);
        if (HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_7) == GPIO_PIN_RESET)
        {
          ret = true;
        }
      }
      break;
    }
    default:
      break;
  }
  return ret;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
