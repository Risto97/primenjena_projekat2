#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC30F__)
        #include <p30Fxxxx.h>
    #endif
#endif

#include <stdint.h>
#include "system.h"
#include <libpic30.h>

#include "uart_debug.h"
#include "misc.h"
#include "uart_rf.h"
#include "motor_con.h"
#include "message.h"
#include "commands.h"

void print_command(Command_t command);

int16_t main(void)
{
  char *rbuff_rx;
  char message[3];
  int sanity = 0;
  Command_t command;

  ConfigureOscillator();

  sanity_init();
  initRF();
  initUART2();
  mot1_init();
  mot2_init();

  UART2_putst("starting\n");
  while(1)
    {
      if(RF_buff_status() > 0){
        rbuff_rx = RF_rbuff();
        /* UART2_putst(rbuff_rx); */
        /* UART1_putst(rbuff_rx); */

        if(decode_message(rbuff_rx, message) == 1){
          UART2_putst("valid message: ");
          decode_command(message, &command);
          print_command(command);
          set_motors(command);
        }
        else{
          UART2_putst("not valid message: ");
        }
        UART2_putst("\n");


      }
      else{
        sanity_set(sanity);
        sanity = !sanity;
      }
      __delay_ms(100);

    }
}


void print_command(Command_t command){
  UART2_putst("\nMOT1_start: ");
  WriteUART2dec2string(command.MOT1_status);
  UART2_putst("\nMOT2_start: ");
  WriteUART2dec2string(command.MOT2_status);
  UART2_putst("\nMOT1_dir: ");
  WriteUART2dec2string(command.MOT1_dir);
  UART2_putst("\nMOT2_dir: ");
  WriteUART2dec2string(command.MOT2_dir);
  UART2_putst("\nMOT1_speed: ");
  WriteUART2dec2string(command.MOT1_speed);
  UART2_putst("\nMOT2_speed: ");
  WriteUART2dec2string(command.MOT2_speed);
  UART2_putst("\n");
}
