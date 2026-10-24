#ifndef __BSP_USART_REDIR_H
#define __BSP_USART_REDIR_H //防止头文件重复包含

#ifdef __cplusplus
extern "C" {//extern "C", 告诉编译器，头⽂件⾥的函数是⽤C语⾔规则编译的，这样代码才能正确找到并调⽤这些函数。
#endif

#include <stdio.h>
#include"stm32f1xx_hal.h"

extern UART_HandleTypeDef *ghusart;

void BSP_Usart_Init(UART_HandleTypeDef* husart);


#ifdef __cplusplus
}
#endif

#endif