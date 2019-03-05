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
#include "watchdog.h"

void print_command(Command_t command);

int16_t main(void)
{
  char *rbuff_rx;
  char message[PAYLOAD_LEN+1];
  Command_t command;

  ConfigureOscillator();

  sanity_init();
  initRF();
  initUART2();
  mot1_init();
  mot2_init();
  limit_init();
  Watchdog_init();
  Watchdog_start();

  sanity_set(0);

  while(1)
    {
      if(RF_buff_status() > 0){
        rbuff_rx = RF_rbuff();

        if(decode_message(rbuff_rx, message) == 1){
          decode_command(message, &command);
          set_motors(command);
          Watchdog_reset();
          sanity_set(0);
        }
      }
      /* __delay_ms(100); */
    }
}


void print_command(Command_t command){
  UART1_putst("\nMOT1_start: ");
  WriteUART1dec2string(command.MOT1_status);
  UART1_putst("\nMOT2_start: ");
  WriteUART1dec2string(command.MOT2_status);
  UART1_putst("\nMOT1_dir: ");
  WriteUART1dec2string(command.MOT1_dir);
  UART1_putst("\nMOT2_dir: ");
  WriteUART1dec2string(command.MOT2_dir);
  UART1_putst("\nMOT1_speed: ");
  WriteUART1dec2string(command.MOT1_speed);
  UART1_putst("\nMOT2_speed: ");
  WriteUART1dec2string(command.MOT2_speed);
  UART1_putst("\n");
}
