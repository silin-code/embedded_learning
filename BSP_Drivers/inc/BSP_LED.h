#ifndef __BSP_LED_H
#define __BSP_LED_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <string.h>

#include "stm32f1xx_hal.h"

    typedef enum
    {
        LED1 = 1,
        LED2 = 2,
        LED3 = 3,
        LED4 = 4,
        ALL = 5
    } LED_t;

    typedef enum
    {
        KEY1 = 1,
        KEY2 = 2,
        KEY3 = 3,
        KEY4 = 4
    } KEY_t;

    void BSP_LED_Control(LED_t led, bool flag);
    void BSP_Led_On(LED_t led);
    void BSP_Led_Off(LED_t led);
    void LED_Link(LED_t led);

#ifdef __cplusplus
}
#endif

#endif