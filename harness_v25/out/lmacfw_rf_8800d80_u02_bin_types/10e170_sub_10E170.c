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

extern uint32_t off_10E1FC;
extern uint32_t off_10E200;
extern uint32_t dword_10E204;
extern uint32_t dword_10E208;
extern uint32_t dword_10E20C;
extern uint32_t dword_10E210;

// sub_10E170 @ 0x10e170, size 138 bytes
float sub_10E170()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E1FC;
  v1 = off_10E200;
  v2 = dword_10E204;
  v3 = dword_10E208;
  v4 = dword_10E20C;
  *(uint32_t *)off_10E1FC = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  sub_10DCE8();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  sub_10EFB4(dword_10E210, 0, 15360);
  return (float)((float)((float)v5 / flt_10E214) - 1.0) * flt_10E218;
}

