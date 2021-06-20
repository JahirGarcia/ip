#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define IP_SIZE 4
#define BYTE 8

uint32_t ip2int(uint8_t *ip) {
  short i = 0;
  uint32_t int_ip = ip[i];

  for(i=1; i<IP_SIZE; i++) 
    int_ip = (int_ip << BYTE) | ip[i];

  return int_ip;
}

uint8_t *int2ip(uint32_t int_ip) {
  short i = 0;
  uint8_t *ip = malloc(sizeof(uint8_t) * IP_SIZE);

  for(i=0; i<IP_SIZE; i++) 
    ip[i] = int_ip >> ((IP_SIZE - (i + 1)) * BYTE);

  return ip;
}

int main() {
  uint8_t ip[IP_SIZE] = { 192, 168, 1, 15 };

  uint32_t int_ip = ip2int(ip);
  printf("%u\n", int_ip);

  memcpy(ip, int2ip(int_ip), IP_SIZE * BYTE);
  printf("%u.%u.%u.%u\n", ip[0], ip[1], ip[2], ip[3]);

  return 0;
}
