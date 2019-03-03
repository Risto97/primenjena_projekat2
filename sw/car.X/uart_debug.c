#ifndef UART_DEBUG_C
#define UART_DEBUG_C

#include "uart_debug.h"

static char tempRX;
static unsigned int wordReceived = 0;
static char buff[32];
static unsigned int len = 0;
static int n = 0;
void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void) {
  IFS1bits.U2RXIF = 0;
  tempRX = U2RXREG;
  buff[n] = tempRX;
  n++;
  if(buff[n-1] == 13){  // 13 is ascii for carriage return
    buff[n-1] = '\0';
    wordReceived = 1;
    len = n;
    n = 0;
  }
}

int UART2_buff_status(){
  unsigned int len_tmp = len;
  if(wordReceived == 1){
    len = 0;
    wordReceived = 0;
    return len_tmp;
  }
  else
    return -1;
}

char *UART2_rbuff(){
  return buff;
}

void initUART2()
{
  U2BRG = 0x0022;
  /* U2BRG = 0x0067; */
  /* U2BRG = 0x000B; */
  IEC1bits.U2RXIE=1;
  U2STA&=0xfffc;
  U2MODEbits.UARTEN=1;
  U2STAbits.UTXEN=1;
  TRISFbits.TRISF4 = 1;
  TRISFbits.TRISF5 = 0;
}


void UART2_putst(char *str){
  while((*str)!=0) {
    WriteUART2(*str);
    if (*str==13) WriteUART2(10);
    if (*str==10) WriteUART2(13);
    str++;
  }
}

void WriteUART2(unsigned int data){

  while(!U2STAbits.TRMT);

  if(U2MODEbits.PDSEL == 3)
    U2TXREG = data;
  else
    U2TXREG = data & 0xFF;
}

void WriteUART2dec2string(int data)
{
	unsigned char temp;
  if(data < 0){
    WriteUART2('-');
    data = -data;
  }

	temp=data/1000;
  if(temp != 0)
    WriteUART2(temp+'0');
	data=data-temp*1000;
	temp=data/100;
  if(temp != 0)
    WriteUART2(temp+'0');
	data=data-temp*100;
	temp=data/10;
  if(temp != 0)
    WriteUART2(temp+'0');
	data=data-temp*10;
	WriteUART2(data+'0');
}

#endif
