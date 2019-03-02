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

#include "misc.h"
#include "uart_debug.h"
#include "motor_con.h"

int16_t main(void)
{
  int duty = 100;
  int dir = 1;
  int cnt = 0;
  ConfigureOscillator();

  sanity_init();
  initUART2();

  mot1_init();
  mot2_init();

  while(1)
    {
      mot1_start(dir, duty);
      __delay_ms(1000);
      mot1_stop();
      __delay_ms(1000);

      cnt++;
      mot1_set_duty(duty + cnt*100);

      if(cnt == 22){
        cnt = 0;
        dir = -dir;
      }
    }
}
