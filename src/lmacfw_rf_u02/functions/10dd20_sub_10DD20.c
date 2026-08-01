#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_10DDB8;
extern uint32_t off_10DDBC;
extern uint32_t dword_10DDC0;
extern uint32_t dword_10DDC4;
extern uint32_t dword_10DDA0;
extern uint32_t dword_10DDA4;
extern uint32_t dword_10DDA8;
extern uint32_t dword_10DDAC;
extern uint32_t dword_10DDB0;
extern uint32_t dword_10DDB4;

// gpio_port_init @ 0x10dd20, size 128 bytes
int gpio_port_init()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r0

  v0 = off_10DDB8;
  v1 = off_10DDBC;
  v2 = dword_10DDC0;
  v3 = dword_10DDC4;
  *(uint32_t *)off_10DDBC = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = double_to_float(v1[4]);
  v5 = aeabi_dadd(v4, HIDWORD(v4), dword_10DDA0, dword_10DDA4);
  v6 = aeabi_dsub(v5, HIDWORD(v5), dword_10DDA8, dword_10DDAC);
  v7 = double_subtract(v6, HIDWORD(v6), dword_10DDB0, dword_10DDB4);
  return aeabi_dmul(v7);
}

