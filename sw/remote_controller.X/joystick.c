#ifndef JOYSTICK_C
#define JOYSTICK_C

#include "joystick.h"

static int adcbuf0, adcbuf1;
void __attribute__((__interrupt__, no_auto_psv)) _ADCInterrupt(void)
{
	adcbuf0=ADCBUF0;//0
	adcbuf1=ADCBUF1;//1

  IFS0bits.ADIF = 0;
}

void joystick_init(){
  ADPCFG_JOYSTICK_X = 0;
  ADPCFG_JOYSTICK_Y = 0;
  TRIS_JOYSTICK_X = 1;
  TRIS_JOYSTICK_Y = 1;

  TRIS_TURBO = 1;
  ADPCFG_TURBO = 1;

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

void ADCinit_Joystick(void)
{
  ADCON1bits.ADSIDL=1;
  ADCON1bits.FORM=0b01; //signed representation
  ADCON1bits.SSRC=7;
  ADCON1bits.SAMP=1;

  ADCON2bits.VCFG=0; // AVdd and AVss references
  ADCON2bits.CSCNA=1;
  ADCON2bits.SMPI=15; // oversampling
  ADCON2bits.BUFM=0;
  ADCON2bits.ALTS=0;

  ADCON3bits.SAMC=31;
  ADCON3bits.ADRC=1;
  ADCON3bits.ADCS=31;

  ADCHSbits.CH0NB=0;
  ADCHSbits.CH0NA=0;

  ADCHSbits.CH0SA=0;
  ADCHSbits.CH0SB=0;

  ADCSSL=0b0000000000000011;
  ADCON1bits.ASAM=1;

  IFS0bits.ADIF=1;
  IEC0bits.ADIE=1;
}

#endif
