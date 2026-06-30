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

extern uint32_t off_128474;
extern uint32_t dword_128488;
extern uint32_t dword_128484;
extern uint32_t off_128478;
extern uint32_t dword_12847C;
extern uint32_t dword_128480;

// sub_1283D4 @ 0x1283d4, size 160 bytes
int  sub_1283D4(int result)
{
  int v1; // r7
  int v2; // r5
  uint8_t *v3; // r6
  int v4; // r8
  int v5; // r0
  int16_t v6; // r5
  int16_t v7; // r4
  int v8; // r2

  v1 = *(uint32_t *)(result + 72);
  v2 = result;
  if ( **(int16_t **)off_128474 < 0 && !v1 )
    result = sub_12F46C(dword_128488, dword_128484, 3591);
  v3 = off_128478;
  if ( (*((uint8_t *)off_128478 + 88) & 0x20) == 0 && *((uint8_t *)off_128478 + 90) > 1u )
  {
    v4 = *(uint8_t *)(v2 + 116);
    v5 = sub_12C92C(70, *((uint8_t *)off_128478 + 88) & 0x20, *((uint8_t *)off_128478 + 88) & 0x20, 20);
    *(uint8_t *)v5 = 0;
    *(uint8_t *)(v5 + 1) = *(uint8_t *)(v2 + 107);
    *(uint8_t *)(v5 + 2) = *(uint8_t *)(v1 + 4);
    *(uint8_t *)(v5 + 3) = *(uint8_t *)(v1 + 5);
    v6 = *(uint16_t *)(v1 + 8);
    v7 = *(uint16_t *)(v1 + 10);
    v8 = dword_12847C;
    *(uint16_t *)(v5 + 4) = *(uint16_t *)(v1 + 6);
    *(uint16_t *)(v5 + 6) = v6;
    *(uint16_t *)(v5 + 8) = v7;
    *(uint8_t *)(v5 + 16) = *(uint8_t *)(v1 + 12);
    *(uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_128480
                                         * (unsigned uint64_t)(unsigned int)(*(uint32_t *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = sub_12C98C(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

