#include "BSP_LED.h"

bool led_state = false;              // flase == off,true == on
const uint32_t KEY_DEBOUNCE_MS = 20; // Debounce time in milliseconds

void BSP_LED_Control(LED_t led, bool flag)
{
  GPIO_PinState state = flag ? GPIO_PIN_RESET : GPIO_PIN_SET;
  switch (led)
  {
  case LED1:
  {
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, state);
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
  default:
  {
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

void LED_Link(LED_t led)
{
  if (led == ALL)
  {
    LED_t leds[] = {LED1, LED2, LED3, LED4};
    // 同时点亮
    int leds_num = sizeof(leds) / sizeof(leds[0]);
    int cnt = 3;
    do
    {
      for (int i = 0; i < leds_num; i++)
      {
        BSP_Led_On(leds[i]);
      }
      HAL_Delay(500);
      for (int i = 0; i < leds_num; i++)
      {
        BSP_Led_Off(leds[i]);
      }
      HAL_Delay(500);
    } while (cnt--);
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      BSP_Led_On(led);
      HAL_Delay(500);
      BSP_Led_Off(led);
      HAL_Delay(500);
    }
  }
}
