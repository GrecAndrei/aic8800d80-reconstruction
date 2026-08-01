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

extern uint32_t off_10C6E8;
extern uint32_t off_10C6E4;
extern uint32_t off_10C6F4;
extern uint32_t dword_10C6F8;
extern uint32_t dword_10C6F0;
extern uint32_t off_10C6EC;

// peripheral_clock_enable @ 0x10c638, size 172 bytes
int peripheral_clock_enable()
{
  int *v0; // r2
  unsigned int *v1; // r1
  uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r3
  unsigned int v5; // r5
  int result; // r0

  v0 = (int *)off_10C6E8;
  *((uint32_t *)off_10C6E4 + 64) = 6;
  v0[1] &= ~0x40000u;
  v0[1] |= 0x20000u;
  while ( (v0[12] & 0x44) != 4 )
    ;
  v1 = (unsigned int *)off_10C6F4;
  v2 = off_10C6E4;
  v3 = dword_10C6F8;
  v4 = (unsigned int)(((unsigned int)dword_10C6F0 * (unsigned uint64_t)*(unsigned int *)off_10C6EC) >> 32) >> 18;
  v5 = v4 | 0x80140000;
  v4 |= 0x140000u;
  *(uint32_t *)off_10C6F4 = v4;
  *v1 = v5;
  *v1 = v4;
  v0[1] |= 0x18802u;
  v2[81] = 8;
  *v0 = *v0 & 0x3BF | 0x40 | *v0 & v3;
  v2[14] |= 1u;
  v0[17] |= 0x88000000;
  v0[21] &= ~0x200000u;
  result = v3 & v0[21];
  v0[21] = v0[21] & 0x3FD | 2 | result;
  v0[21] &= ~0x800u;
  return result;
}

