#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <p30Fxxxx.h>

void Watchdog_init();
void Watchdog_start();
void Watchdog_stop();
void Watchdog_reset();

#endif
