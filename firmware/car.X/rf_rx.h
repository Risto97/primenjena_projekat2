#ifndef RF_RX_H
#define RF_RX_H

#include <p30Fxxxx.h>

void initRF();
int RF_RX_buff_status();
char *RX_rbuff();

// unused
void UART1_putst(char *str);
void WriteUART1(unsigned int data);
void WriteUART1dec2string(int data);

#endif
