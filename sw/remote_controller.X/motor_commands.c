#ifndef MOTOR_COMMANDS_C
#define MOTOR_COMMANDS_C

#include "motor_commands.h"

Command_t gen_command(int val_x, int val_y){
  Command_t command;
  int x = discrete_ADC(val_x);
  int y = discrete_ADC(val_y);

  if(x != 0)
    command.MOT1_status = 1;
  else
    command.MOT1_status = 0;

  if(y != 0)
    command.MOT2_status = 1;
  else
    command.MOT2_status = 0;

  if(x >= 0)
    command.MOT1_dir = 1;
  else if(x < 0)
    command.MOT1_dir = 0;

  if(y >= 0)
    command.MOT2_dir = 1;
  else if(y < 0)
    command.MOT2_dir = 0;

  command.MOT1_speed = abs(x);
  command.MOT2_speed = abs(y);

  return command;
}

int discrete_ADC(int val){
  int speed;
  if(val >= 0){
    if(val < 100)
      speed = 0;
    else if(val >= 100 && val < 300)
      speed = 1;
    else if(val >= 300 && val < 500)
      speed = 2;
    else if(val >= 500 && val < 700)
      speed = 3;
    else if(val >= 700 && val < 900)
      speed = 4;
    else if(val >= 900 && val < 1100)
      speed = 5;
    else if(val >= 1100 && val < 1300)
      speed = 6;
    else if(val >= 1300 && val < 1500)
      speed = 7;
    else if(val >= 1500 && val < 1700)
      speed = 8;
    else if(val >= 1700 && val < 2000)
      speed = 9;
    else if(val >= 2000)
      speed = 10;
  }
  else if(val < 0){
    if(val > -100)
      speed = 0;
    else if(val <= -100 && val > -300)
      speed = -1;
    else if(val <= -300 && val > -500)
      speed = -2;
    else if(val <= -500 && val > -700)
      speed = -3;
    else if(val <= -700 && val > -900)
      speed = -4;
    else if(val <= -900 && val > -1100)
      speed = -5;
    else if(val <= -1100 && val > -1300)
      speed = -6;
    else if(val <= -1300 && val > -1500)
      speed = -7;
    else if(val <= -1500 && val > -1700)
      speed = -8;
    else if(val <= -1700 && val > -2000)
      speed = -9;
    else if(val <= -2000)
      speed = -10;
  }
  return speed;
}


#endif
