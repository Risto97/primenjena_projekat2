#ifndef MOTOR_CON_C
#define MOTOR_CON_C

#include "motor_con.h"

void __attribute__((__interrupt__, no_auto_psv)) _CNInterrupt(void)
{
  IFS0bits.CNIF = 0; // clear flag
  if(LIMIT_SW1 == 1 || LIMIT_SW2 == 1){
    mot2_stop();
  }
}

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

  PR2=PWM_TIMER_MAX;  // ~ 2khz
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
  else if(dir == 0){
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

  PR3=PWM_TIMER_MAX;  // ~ 2khz
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
  /* if(!LIMIT_SW1 && !LIMIT_SW2){   // check if limit switches are pressed */
    OC2CONbits.OCM = 0b110;       // pwm mode without fault protection
    T3CONbits.TON=1;
  /* } */
}

void mot2_start(int dir, unsigned int duty){
  /*
    If limit switch is not pressed steering motor is allowed to work.
    If limit switch is pressed, enable steering motor only if requested direction is opposite.
   */
  if((!LIMIT_SW1 && !LIMIT_SW2) || (LIMIT_SW1 && dir == 1) || ( LIMIT_SW2 && dir == 0)){
    mot2_ch_dir(dir);
    mot2_set_duty(duty);
    _mot2_start();
  }
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
  else if(dir == 0){
    MOT2_DIR_A = 0;
    MOT2_DIR_B = 1;
  }
}

void limit_init(){
  TRIS_LIMIT_SW1 = 1;
  TRIS_LIMIT_SW2 = 1;

  CNEN1bits.CN0IE = 1; // enable interupts for CN0
  CNEN1bits.CN1IE = 1; // enable interupts for CN1
  CNPU1bits.CN0PUE = 1; // enable weak pull-up
  CNPU1bits.CN1PUE = 1; // enable weak pull-up
  IFS0bits.CNIF = 0; // clear flag
  IPC3bits.CNIP = 7; // set max priority
  IEC0bits.CNIE = 1; // enable CN interrupt
}

void set_motors(Command_t command){
  int mot1_duty, mot2_duty;
  int mot1_dir, mot2_dir;

  if(command.MOT1_turbo == 1)
    mot1_duty = PWM_TIMER_MAX;
  else if(command.MOT1_turbo == 0)
    mot1_duty = speed_to_duty(command.MOT1_speed);

  mot2_duty = speed_to_duty(command.MOT2_speed);

  mot1_dir = command.MOT1_dir;
  mot2_dir = command.MOT2_dir;

  if(command.MOT1_status == 1)
    mot1_start(mot1_dir, mot1_duty);
  else
    mot1_stop();

  if(command.MOT2_status == 1)
    mot2_start(mot2_dir, mot2_duty);
  else
    mot2_stop();

}

int speed_to_duty(int speed){
  switch(speed){
  case 1: return 220; break;
  case 2: return 440; break;
  case 3: return 660; break;
  case 4: return 880; break;
  case 5: return 1100; break;
  case 6: return 1320; break;
  case 7: return 1540; break;
  case 8: return 1760; break;
  case 9: return 1980; break;
  case 10: return 2200; break;
  }

}

#endif
