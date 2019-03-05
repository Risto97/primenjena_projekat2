#ifndef MESSAGE_C
#define MESSAGE_C

#include "message.h"

int decode_message(char *packet, char *message){
  int i;
  if(packet[0] == (char)PREAMBLE && packet[1] == (char)ADDR && packet[2+PAYLOAD_LEN] == (char)TRAILER){
    for(i = 0; i<PAYLOAD_LEN; i++){
      message[i] = packet[2+i];
    }
    return 1;
  }
  else{
    str_clear(packet, PACKET_LEN);
    return -1;
  }
}

void package_message(char *message, char *packet){
  packet[0] = PREAMBLE;
  packet[1] = ADDR;
  _strcpy(message, &packet[2], PAYLOAD_LEN);
  packet[2+PAYLOAD_LEN] = TRAILER;
}

void _strcpy(char *src, char *dest, int len){
  int i = 0;
  for(i=0; i<len; i++){
    dest[i] = src[i];
  }
}

void str_clear(char *str, int len){
  int i = 0;
  for(i = 0; i < len; i++){
    str[i] = 0;
  }
}
#endif
