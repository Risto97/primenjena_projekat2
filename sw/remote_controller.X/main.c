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
  ConfigureOscillator();

  sanity_init();
  initRF();
  initUART2();
  joystick_init();
  joystick_ADC_start();
  int x;
  int y;

    while(1)
      {
        sanity_set(0);
        x = get_joystickX();
        y = get_joystickY();

        command = gen_command(x, y);
        encode_command(command, message);
        package_message(message, packet);

        WriteUART1(packet[0]);
        WriteUART1(packet[1]);
        WriteUART1(packet[2]);
        WriteUART1(packet[3]);
        WriteUART1(packet[4]);
        UART1_putst("\n");

        __delay_ms(100);
        sanity_set(1);
        __delay_ms(100);

    }
}
