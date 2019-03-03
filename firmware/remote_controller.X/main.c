#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC30F__)
        #include <p30Fxxxx.h>
    #endif
#endif

#include <stdint.h>
#include "system.h"
#include <libpic30.h>

/* #include "input_periphs.h" */
/* #include "uart_debug.h" */
/* #include "rf_tx.h" */

void WriteUART1(unsigned int data){

  while(!U1STAbits.TRMT);

  if(U1MODEbits.PDSEL == 3)
    U1TXREG = data;
  else
    U1TXREG = data & 0xFF;
}

void UART1_putst(char *str){
  while((*str)!=0) {
    WriteUART1(*str);
    if (*str==13) WriteUART1(10);
    if (*str==10) WriteUART1(13);
    str++;
  }
}

int16_t main(void)
{
    ConfigureOscillator();

    U1BRG = 0x0022; // 9600 baud rate on 16MHz
    /* U1BRG = 0x0120; // 1200 baud rate on 16MHz */
    /* U1BRG = 0x080; // 1200 baud rate on 16MHz */
    IEC0bits.U1RXIE=1;
    U1STA&=0xfffc;
    U1MODEbits.ALTIO=0;// RF2, RF3
    U1MODEbits.UARTEN=1;
    U1STAbits.UTXEN=1;

    TRISFbits.TRISF2 = 1;
    TRISFbits.TRISF3 = 0;

    /* sw_init(); */
    /* initUART2(); */
    /* joystick_init(); */
    /* joystick_ADC_start(); */


    /* initRF(); */
    /* int x; */
    /* int y; */

    while(1)
    {
      UART1_putst("asdasd");
      /* set_sanity(1); */
      /* UART2_putst("bdcbdcd"); */
      /* y = get_joystickY(); */
      /* x = get_joystickX(); */
      /* UART1_putst("x: "); */
      /* WriteUART1dec2string(x); */
      /* UART1_putst("\n"); */
      /* UART1_putst("y: "); */
      /* WriteUART1dec2string(y); */
      /* UART1_putst("\n"); */
      /* UART1_putst("------------------\n"); */

      __delay_ms(63);
      /* UART1_putst("asdasd"); */
      /* /\* set_sanity(0); *\/ */
      /* __delay_ms(63); */

    }
}
