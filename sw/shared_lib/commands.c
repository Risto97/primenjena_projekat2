#ifndef COMMANDS_C
#define COMMANDS_C

#include "commands.h"

void decode_command(char* message, Command_t *command){
  command->MOT1_status = message[0] & 0x01;
  command->MOT2_status = (message[0] & 0x02) >> 1;
  command->MOT1_dir = (message[0] & 0x04) >> 2;
  command->MOT2_dir = (message[0] & 0x08) >> 3;
  command->MOT1_turbo = (message[0] & 0x10) >> 4;

  command->MOT1_speed = message[1] & 0x0F;
  command->MOT2_speed = (message[1] & 0xF0) >> 4;
}

void encode_command(Command_t command, char* message){
  message[0] = 0;
  message[1] = 0;

  message[0] = message[0] | (command.MOT1_status & 0x01);
  message[0] = message[0] | ((command.MOT2_status & 0x01) << 1);
  message[0] = message[0] | ((command.MOT1_dir & 0x01) << 2);
  message[0] = message[0] | ((command.MOT2_dir & 0x01) << 3);
  message[0] = message[0] | ((command.MOT1_turbo & 0x01) << 4);

  message[1] = message[1] | (command.MOT1_speed & 0x0F);
  message[1] = message[1] | ((command.MOT2_speed & 0x0F) << 4);
}


#endif
