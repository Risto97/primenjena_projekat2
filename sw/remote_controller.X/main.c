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
#include "joystick.h"
#include "message.h"
#include "commands.h"
#include "motor_commands.h"

int16_t main(void)
{
  Command_t command;
  char message[PAYLOAD_LEN+1];
  char packet[PACKET_LEN+1];
  int x;
  int y;
  int i;
  int turbo;
  ConfigureOscillator();

  initRF();
  /* initUART2(); */
  joystick_init();
  joystick_ADC_start();

  while(1){
    x = get_joystickX();
    y = get_joystickY();
    turbo = get_Turbo();

    command = gen_command(x, y, turbo);
    encode_command(command, message);
    package_message(message, packet);

    for(i=0; i<PACKET_LEN; i++){
      WriteUART1(packet[i]);
    }
  }
}
