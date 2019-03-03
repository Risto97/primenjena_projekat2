#ifndef MESSAGE_C
#define MESSAGE_C

#include "message.h"

int decode_message(char *packet, char *message){
  if(packet[0] == PREAMBLE && packet[1] == ADDR && packet[2+PAYLOAD_LEN] == TRAILER){
      message[0] = packet[2];
      message[1] = packet[3];
      message[2] = 13; // endl
      str_clear(packet, PACKET_LEN);
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
  packet[2+PAYLOAD_LEN+1] = 13; // endl
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
