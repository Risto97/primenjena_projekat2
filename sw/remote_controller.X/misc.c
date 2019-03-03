#ifndef MISC_C
#define MISC_C

#include "misc.h"


void sanity_init(){
  TRIS_SANITY = 0;
}

void sanity_set(int value){
  SANITY = value;
}

void usr1_init(){
  TRIS_USR1 = 1;
}

void usr2_init(){
  TRIS_USR2 = 1;
}

void usr3_init(){
  TRIS_USR3 = 1;
}

#endif
