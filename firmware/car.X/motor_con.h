#ifndef MOTOR_CON_H
#define MOTOR_CON_H

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include<p30Fxxxx.h>
#include <libpic30.h>

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

#endif
