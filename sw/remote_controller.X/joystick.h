#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include<p30Fxxxx.h>
#include <libpic30.h>

#define TRIS_TURBO TRISBbits.TRISB9
#define ADPCFG_TURBO ADPCFGbits.PCFG9
#define TURBO PORTBbits.RB9

#define ADPCFG_JOYSTICK_X ADPCFGbits.PCFG0
#define TRIS_JOYSTICK_X TRISBbits.TRISB0
#define ADPCFG_JOYSTICK_Y ADPCFGbits.PCFG1
#define TRIS_JOYSTICK_Y TRISBbits.TRISB1

void joystick_init();
void joystick_ADC_start();
void joystick_ADC_stop();
int get_joystickX();
int get_joystickY();
void ADCinit_Joystick(void);
int get_Turbo();

#endif
