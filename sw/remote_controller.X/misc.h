#ifndef MISC_H
#define MISC_H

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include<p30Fxxxx.h>
#include <libpic30.h>

#define TRIS_SANITY TRISCbits.TRISC13
#define SANITY LATCbits.LATC13

#define TRIS_USR1 TRISCbits.TRISC14
#define USR1 PORTCbits.RC14

#define TRIS_USR2 TRISAbits.TRISA11
#define USR2 PORTCbits.RA11

#define TRIS_USR3 TRISDbits.TRISD9
#define USR3 PORTDbits.RD9

void sanity_set(int value);
void sanity_init();
void usr1_init();
void usr2_init();
void usr3_init();

#endif
