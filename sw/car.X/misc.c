#ifndef MISC_C
#define MISC_C

#include "misc.h"


void sanity_init(){
  TRIS_SANITY = 0;
}

void sanity_set(int value){
  SANITY = value;
}

#endif
