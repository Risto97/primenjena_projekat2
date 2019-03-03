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
#include "rf_rx.h"
/* #include "uart_debug.h" */
/* #include "motor_con.h" */

int16_t main(void)
{
  int duty = 100;
  int dir = 1;
  int cnt = 0;
  char *rbuff_rx;
  ConfigureOscillator();

  sanity_init();
  /* initUART2(); */
  initRF();
  sanity_init();

  /* mot1_init(); */
  /* mot1_start(dir, 1000); */
  /* mot2_init(); */

  /* UART2_putst("Pocinjem \n"); */
  /* UART1_putst("asdasd"); */
  while(1)
    {

      UART1_putst("nesto");
      set_sanity(1);
      if(RF_RX_buff_status() > 0){
        rbuff_rx = RX_rbuff();
        UART1_putst(rbuff_rx);
      }
      __delay_ms(50);
      UART1_putst("nesto");
      set_sanity(0);
      if(RF_RX_buff_status() > 0){
        rbuff_rx = RX_rbuff();
        UART1_putst(rbuff_rx);
      }
      __delay_ms(50);

      /* __delay_ms(1000); */
      /* mot1_stop(); */
      /* __delay_ms(1000); */

      /* cnt++; */
      /* mot1_set_duty(duty + cnt*100); */

      /* if(cnt == 22){ */
      /*   cnt = 0; */
      /*   dir = -dir; */
      /* } */
    }
}
