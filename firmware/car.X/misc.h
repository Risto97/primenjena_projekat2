#ifndef MISC_H
#define MISC_H

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include<p30Fxxxx.h>
#include <libpic30.h>

#define TRIS_SANITY TRISDbits.TRISD9
#define SANITY LATDbits.LATD9

void set_sanity(int value);
void sanity_init();

#endif
