#ifndef MESSAGE_H
#define MESSAGE_H

/* Packet format
=========================
   PREAMBLE: 1 byte
   ADDR:     1 byte
   PAYLOAD:  2 bytes
   TRAILER:  1 byte
====================== */

#define PACKET_LEN 5

#define PREAMBLE 0x55
#define ADDR 0x24
#define PAYLOAD_LEN 2
#define TRAILER 0x55

int decode_message(char *raw, char *message);
void package_message(char *message, char *packet);
void str_clear(char *str, int len);
void _strcpy(char *src, char *dest, int len);

#endif
