#ifndef MOTOR_COMMANDS_H
#define MOTOR_COMMANDS_H

#include "commands.h"
#include "stdlib.h"

int discrete_ADC(int val);
Command_t gen_command(int val_x, int val_y, int turbo);

#endif
