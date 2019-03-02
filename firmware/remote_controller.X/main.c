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

#include "input_periphs.h"
#include "uart_debug.h"

int16_t main(void)
{
    ConfigureOscillator();

    sw_init();
    initUART2();
    joystick_init();

    joystick_ADC_start();

    int x;
    int y;
    int turbo;

    while(1)
    {
      /* x = get_joystickX(); */
      /* y = get_joystickY(); */
      turbo = get_Turbo();

      /* UART2_putst("x: "); */
      /* WriteUART2dec2string(x); */
      /* UART2_putst("\n"); */
      /* UART2_putst("y: "); */
      /* WriteUART2dec2string(y); */
      /* UART2_putst("\n"); */
      UART2_putst("turbo: ");
      WriteUART2dec2string(turbo);
      UART2_putst("\n");
      UART2_putst("USR1: ");
      WriteUART2dec2string(get_USR1());
      UART2_putst("\n");
      UART2_putst("USR2: ");
      WriteUART2dec2string(get_USR2());
      UART2_putst("\n");
      UART2_putst("USR3: ");
      WriteUART2dec2string(get_USR3());
      UART2_putst("\n");
      UART2_putst("---------------------\n");
      __delay_ms(400);

    }
}
