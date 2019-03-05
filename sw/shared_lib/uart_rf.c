#ifndef UART_RF_C
#define UART_RF_C

#include "uart_rf.h"

static char tempRX;
static unsigned int wordReceived = 0;
static char buff[32];
static unsigned int len = 0;
static int n = 0;
static int preamble_received = 0;
void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void) {
  IFS0bits.U1RXIF = 0;
  tempRX = U1RXREG;
  if(tempRX == (char)PREAMBLE){
    preamble_received = 1;
  }
  if(preamble_received == 1){
    WriteUART1(tempRX);
    buff[n] = tempRX;
    n++;
  }
  if(tempRX == (char)TRAILER){
    wordReceived = 1;
    len = n;
    n = 0;
    preamble_received = 0;
  }
}

int RF_buff_status(){
  unsigned int len_tmp = len;
  if(wordReceived == 1){
    len = 0;
    wordReceived = 0;
    return len_tmp;
  }
  else
    return -1;
}

char *RF_rbuff(){
  return buff;
}

void initRF()
{
  /* U1BRG = 0x0022; // 9600 baud rate on 16MHz */
  U1BRG = 0x0120; // 1200 baud rate on 16MHz
  IEC0bits.U1RXIE=1;
  U1STA&=0xfffc;
  U1MODEbits.ALTIO=0;// RF2, RF3
  U1MODEbits.UARTEN=1;
  U1STAbits.UTXEN=1;

  TRISFbits.TRISF2 = 1;
  TRISFbits.TRISF3 = 0;
}

void UART1_putst(char *str){
  while((*str)!=0) {
    WriteUART1(*str);
    if (*str==13) WriteUART1(10);
    if (*str==10) WriteUART1(13);
    str++;
  }
}

void WriteUART1(unsigned int data){

  while(!U1STAbits.TRMT);

  if(U1MODEbits.PDSEL == 3)
    U1TXREG = data;
  else
    U1TXREG = data & 0xFF;
}

void WriteUART1dec2string(int data)
{
	unsigned char temp;
  if(data < 0){
    WriteUART1('-');
    data = -data;
  }

	temp=data/1000;
  if(temp != 0)
    WriteUART1(temp+'0');
	data=data-temp*1000;
	temp=data/100;
  if(temp != 0)
    WriteUART1(temp+'0');
	data=data-temp*100;
	temp=data/10;
  if(temp != 0)
    WriteUART1(temp+'0');
	data=data-temp*10;
	WriteUART1(data+'0');
}


#endif
