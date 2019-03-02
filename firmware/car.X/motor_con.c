#ifndef MOTOR_CON_C
#define MOTOR_CON_C

#include "motor_con.h"

void mot1_init(){
  TRIS_MOT1_DIR_A = 0;
  ADPCFG_MOT1_DIR_A = 1;
  TRIS_MOT1_DIR_B = 0;

  MOT1_DIR_A = 0;
  MOT1_DIR_B = 0;

  mot1_pwm_init();
}

void mot1_pwm_init(){
  TRIS_MOT1_EN = 0;

  PR2=2500;  // ~ 2khz
  OC3RS=1250;
  OC3R=1000;
  OC3CONbits.OCSIDL = 1; // disable in cpu idle
  OC3CONbits.OCFLT = 0; // clear pwm fault condition
  OC3CONbits.OCTSEL = 0;  // use timer2
  OC3CONbits.OCM = 0b110; // pwm mode without fault protection
}

void mot1_set_duty(unsigned int duty){
  OC3RS=duty;
}

void _mot1_start(){
  OC3CONbits.OCM = 0b110; // pwm mode without fault protection
  T2CONbits.TON=1;
}

void mot1_start(int dir, unsigned int duty){
  mot1_ch_dir(dir);
  mot1_set_duty(duty);
  _mot1_start();
}

void mot1_stop(){
  T2CONbits.TON=0;
  OC3CONbits.OCM = 0b000; // disable oc
  MOT1_EN = 0;
}

void mot1_ch_dir(int dir){
  if(dir == 1){
    MOT1_DIR_A = 1;
    MOT1_DIR_B = 0;
  }
  else if(dir == -1){
    MOT1_DIR_A = 0;
    MOT1_DIR_B = 1;
  }
}

void mot2_init(){
  TRIS_MOT2_DIR_A = 0;
  TRIS_MOT2_DIR_B = 0;

  MOT2_DIR_A = 0;
  MOT2_DIR_B = 0;

  mot2_pwm_init();
}

void mot2_pwm_init(){
  TRIS_MOT2_EN = 0;

  PR3=2500;  // ~ 2khz
  OC2RS=1250;
  OC2R=1000;
  OC2CONbits.OCSIDL = 1; // disable in cpu idle
  OC2CONbits.OCFLT = 0; // clear pwm fault condition
  OC2CONbits.OCTSEL = 1;  // use timer3
  OC2CONbits.OCM = 0b110; // pwm mode without fault protection
}

void mot2_set_duty(unsigned int duty){
  OC2RS=duty;
}

void _mot2_start(){
  OC2CONbits.OCM = 0b110; // pwm mode without fault protection
  T3CONbits.TON=1;
}

void mot2_start(int dir, unsigned int duty){
  mot2_ch_dir(dir);
  mot2_set_duty(duty);
  _mot2_start();
}


void mot2_stop(){
  T3CONbits.TON=0;
  OC2CONbits.OCM = 0b000; // disable oc
  MOT2_EN = 0;
}

void mot2_ch_dir(int dir){
  if(dir == 1){
    MOT2_DIR_A = 1;
    MOT2_DIR_B = 0;
  }
  else if(dir == -1){
    MOT2_DIR_A = 0;
    MOT2_DIR_B = 1;
  }
}

#endif
