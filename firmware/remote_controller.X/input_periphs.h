#ifndef INPUT_PERIHPS_H
#define INPUT_PERIHPS_H

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include<p30Fxxxx.h>
#include <libpic30.h>

#define TRIS_TURBO TRISBbits.TRISB9
#define ADPCFG_TURBO ADPCFGbits.PCFG9
#define TURBO PORTBbits.RB9

#define TRIS_SANITY TRISCbits.TRISC13
#define SANITY LATCbits.LATC13

#define TRIS_USR1  TRISCbits.TRISC14
#define USR1 PORTCbits.RC14
#define TRIS_USR2  TRISAbits.TRISA11
#define USR2 PORTAbits.RA11
#define TRIS_USR3  TRISDbits.TRISD9
#define USR3 PORTDbits.RD9

#define ADPCFG_JOYSTICK_X ADPCFGbits.PCFG0
#define TRIS_JOYSTICK_X TRISBbits.TRISB0
#define ADPCFG_JOYSTICK_Y ADPCFGbits.PCFG1
#define TRIS_JOYSTICK_Y TRISBbits.TRISB1

void sw_init();
void joystick_init();
void joystick_ADC_start();
void joystick_ADC_stop();
int get_joystickX();
int get_joystickY();
void ADCinit_Joystick(void);

int get_Turbo();
int get_USR1();
int get_USR2();
int get_USR3();

#endif
