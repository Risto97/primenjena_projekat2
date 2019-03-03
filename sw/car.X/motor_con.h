#ifndef MOTOR_CON_H
#define MOTOR_CON_H

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include<p30Fxxxx.h>
#include <libpic30.h>
#include "commands.h"

#define TRIS_MOT1_DIR_A TRISBbits.TRISB12
#define ADPCFG_MOT1_DIR_A ADPCFGbits.PCFG12
#define MOT1_DIR_A LATBbits.LATB12

#define TRIS_MOT1_DIR_B TRISDbits.TRISD0
#define MOT1_DIR_B LATDbits.LATD0

#define TRIS_MOT2_DIR_A TRISDbits.TRISD8
#define MOT2_DIR_A LATDbits.LATD8

#define TRIS_MOT2_DIR_B TRISFbits.TRISF6
#define MOT2_DIR_B LATFbits.LATF6

#define TRIS_MOT1_EN TRISDbits.TRISD2
#define MOT1_EN LATDbits.LATD2

#define TRIS_MOT2_EN TRISDbits.TRISD1
#define MOT2_EN LATDbits.LATD1

#define TRIS_LIMIT_SW1 TRISCbits.TRISC14
#define LIMIT_SW1 PORTCbits.RC14

#define TRIS_LIMIT_SW2 TRISCbits.TRISC13
#define LIMIT_SW2 PORTCbits.RC13

#define PWM_TIMER_MAX 2500 // ~2khz

void mot1_init();
void mot1_pwm_init();
void mot1_set_duty(unsigned int duty);
void mot1_start(int dir, unsigned int duty);
void _mot1_start();
void mot1_stop();
void mot1_ch_dir(int dir);

void mot2_init();
void mot2_pwm_init();
void mot2_set_duty(unsigned int duty);
void _mot2_start();
void mot2_start(int dir, unsigned int duty);
void mot2_stop();
void mot2_ch_dir(int dir);

void limit_init();

void set_motors(Command_t command);
int speed_to_duty(int speed);

#endif
