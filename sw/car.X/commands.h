#ifndef COMMANDS_H
#define COMMANDS_H

/* Command format
   =========================
   Payload: 2 bytes
     - Action:    1 byte
     - Intensity: 1 byte

   Action: 1 byte
     - MOT1: 1 bit     // LSB
     - MOT2: 1 bit
     - MOT1_DIR: 1 bit
     - MOT2_DIR: 1 bit

   Intensity: 1 byte   // ignore when stop
     - MOT1: 4 bits
     - MOT2: 4 bits
   ====================== */

typedef struct CommandTag{
  unsigned int MOT1_status;
  unsigned int MOT2_status;
  unsigned int MOT1_dir;
  unsigned int MOT2_dir;
  unsigned int MOT1_speed;
  unsigned int MOT2_speed;
} Command_t;

void decode_command(char* message, Command_t *command);
void encode_command(Command_t command, char* message);

#endif
