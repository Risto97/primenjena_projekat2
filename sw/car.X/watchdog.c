#ifndef WATCHDOG_C
#define WATCHDOG_C

#include "watchdog.h"

void __attribute__((__interrupt__, no_auto_psv )) _T4Interrupt(void)
{
  TMR4 =0;
  Watchdog_stop();
  sanity_set(1);
  mot1_stop();
  mot2_stop();

	IFS1bits.T4IF = 0;
}

#define TMR4_period 10500 //  Fosc = 16MHz, FOSC/4, prescaler = 256, 1s => PR2 = ~21000
void Watchdog_init()  // watchdog interrupt on 0.5s
{
	TMR4 = 0;
	PR4 = TMR4_period;

	T4CONbits.TCS = 0; // 0 = Internal clock (FOSC/4)
  T4CONbits.TCKPS = 3; // 1/256 prescaler
	IFS1bits.T4IF = 0; // clear interrupt flag
	IEC1bits.T4IE = 1; // enable interrupt

	T4CONbits.TON = 0; // T4 on
}

void Watchdog_start(){
  if(T4CONbits.TON == 0)
    T4CONbits.TON = 1; // T4 on
}

void Watchdog_stop(){
	T4CONbits.TON = 0; // T4 on
}

void Watchdog_reset(){
  Watchdog_stop();
  TMR4 = 0;
  Watchdog_start();
}

#endif
