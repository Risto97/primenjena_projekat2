#ifndef UART_DEBUG_H
#define UART_DEBUG_H

#include <p30Fxxxx.h>

void initUART2();
void UART2_putst(char *str);
void WriteUART2(unsigned int data);
void WriteUART2dec2string(int data);
int UART2_buff_status();
char *UART2_rbuff();

#endif
