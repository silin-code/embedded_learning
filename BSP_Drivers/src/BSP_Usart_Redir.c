#include "BSP_Usart_Redir.h"

extern UART_HandleTypeDef *ghusart = NULL;

void BSP_Usart_Init(UART_HandleTypeDef *husart)
{
    ghusart = husart;
}

int fputc(int ch, FILE *fp)
{
    UNUSED(fp);
    if (NULL != ghusart)
    {

        if (HAL_UART_Transmit(ghusart, (uint8_t *)&ch, 1, HAL_MAX_DELAY) == HAL_OK)
        {
            return ch;
        }
        return EOF;
    }
    else
        return EOF;
}

int fgetc(FILE *fp)
{
    UNUSED(fp);
    static uint8_t last_was_cr = 0;
    uint8_t ch;

    if (NULL != ghusart)
    {
        while (1)
        {
            if (HAL_UART_Receive(ghusart, &ch, 1, HAL_MAX_DELAY) != HAL_OK)
            {
                return EOF;
            }

            if (last_was_cr)
            {
                last_was_cr = 0;
                if (ch == '\n')
                {
                    continue;
                }
            }

            if (ch == '\r')
            {
                last_was_cr = 1;
                return '\n';
            }

            return (int)ch;
        }
    }
    else
        return EOF;
}