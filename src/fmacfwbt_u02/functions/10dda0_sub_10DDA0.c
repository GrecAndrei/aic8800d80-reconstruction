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

extern uint32_t off_10DE38;
extern uint32_t off_10DE3C;
extern uint32_t dword_10DE40;
extern uint32_t dword_10DE44;
extern uint32_t dword_10DE20;
extern uint32_t dword_10DE24;
extern uint32_t dword_10DE28;
extern uint32_t dword_10DE2C;
extern uint32_t dword_10DE30;
extern uint32_t dword_10DE34;

// sub_10DDA0 @ 0x10dda0, size 128 bytes
int sub_10DDA0()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  int v2; // r1
  int v3; // r2
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r0

  v0 = off_10DE38;
  v1 = off_10DE3C;
  v2 = dword_10DE40;
  v3 = dword_10DE44;
  *(uint32_t *)off_10DE3C = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = sub_142A50(v1[4]);
  v5 = sub_142B44(v4, HIDWORD(v4), dword_10DE20, dword_10DE24);
  v6 = sub_142D98(v5, HIDWORD(v5), dword_10DE28, dword_10DE2C);
  v7 = sub_1427D4(v6, HIDWORD(v6), dword_10DE30, dword_10DE34);
  return sub_143108(v7);
}

