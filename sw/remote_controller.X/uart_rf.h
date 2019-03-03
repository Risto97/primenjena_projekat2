#ifndef UART_RF_H
#define UART_RF_H

#include <p30Fxxxx.h>

void initRF();
void UART1_putst(char *str);
void WriteUART1(unsigned int data);
void WriteUART1dec2string(int data);
int RF_buff_status();
char *RF_rbuff();

#endif
