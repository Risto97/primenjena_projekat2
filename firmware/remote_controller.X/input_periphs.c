#ifndef INPUT_PERIHPS_C
#define INPUT_PERIHPS_C

#include "input_periphs.h"

unsigned int adcbuf0, adcbuf1;
void __attribute__((__interrupt__, no_auto_psv)) _ADCInterrupt(void)
{
	adcbuf0=ADCBUF0;//0
	adcbuf1=ADCBUF1;//1

  IFS0bits.ADIF = 0;
}

void sw_init(){
  TRIS_TURBO = 1;
  ADPCFG_TURBO = 1;
  TRIS_USR1 = 1;
  TRIS_USR2 = 1;
  TRIS_USR3 = 1;
  TRIS_SANITY = 0;
  SANITY = 0;
}

void joystick_init(){
  ADPCFG_JOYSTICK_X = 0;
  ADPCFG_JOYSTICK_Y = 0;
  TRIS_JOYSTICK_X = 1;
  TRIS_JOYSTICK_Y = 1;

  ADCinit_Joystick();
}

void joystick_ADC_start(){
	ADCON1bits.ADON=1;
}

void joystick_ADC_stop(){
	ADCON1bits.ADON=0;
}

int get_joystickX(){

  return adcbuf0;
}

int get_joystickY(){

  return adcbuf1;
}

int get_Turbo(){
  __delay_ms(30);
  return !TURBO;
}
int get_USR1(){
  __delay_ms(30);
  return !USR1;
}
int get_USR2(){
  __delay_ms(30);
  return !USR2;
}
int get_USR3(){
  __delay_ms(30);
  return !USR3;
}

void ADCinit_Joystick(void)
{
  ADCON1bits.ADSIDL=0;
  ADCON1bits.FORM=0;
  ADCON1bits.SSRC=7;
  ADCON1bits.SAMP=1;

  ADCON2bits.VCFG=0;
  ADCON2bits.CSCNA=0;
  ADCON2bits.SMPI=1;
  ADCON2bits.BUFM=0;
  ADCON2bits.ALTS=0;

  ADCON3bits.SAMC=31;
  ADCON3bits.ADRC=1;
  ADCON3bits.ADCS=31;

  ADCHSbits.CH0NB=0;
  ADCHSbits.CH0NA=0;

  ADCHSbits.CH0SA=1;
  ADCHSbits.CH0SB=0;

  ADCSSL=0b0000000000000011;
  ADCON1bits.ASAM=1;

  IFS0bits.ADIF=1;
  IEC0bits.ADIE=1;
}

#endif
