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

extern uint32_t off_138B60;
extern uint32_t dword_138B64;
extern uint32_t off_138B5C;
extern uint32_t dword_138B74;
extern uint32_t dword_138B70;
extern uint32_t dword_138B68;
extern uint32_t dword_138B6C;

// sub_138AD4 @ 0x138ad4, size 136 bytes
uint32_t * sub_138AD4(int a1, int16_t a2, int a3)
{
  uint8_t *v3; // r5
  int v4; // r4
  int v5; // r3
  uint32_t *v6; // r6
  int v7; // r7
  int v8; // r12
  int v9; // r3

  v3 = off_138B60;
  v4 = *((uint8_t *)off_138B60 + 68);
  v5 = dword_138B64;
  v6 = (uint32_t *)(dword_138B64 + 80 * v4);
  if ( **(int16_t **)off_138B5C < 0 )
  {
    v7 = 4 * v4;
    if ( *(uint16_t *)(dword_138B64 + 80 * v4 + 76) )
    {
      sub_12F630(dword_138B74, dword_138B70, 175);
      return 0;
    }
  }
  else
  {
    v7 = 4 * v4;
  }
  v8 = dword_138B64 + 16 * (v7 + v4);
  *(uint32_t *)(v8 + 12) = a1;
  if ( a1 )
    *(uint8_t *)(v8 + 16) = *(uint8_t *)(a1 + 16);
  v9 = v5 + 16 * (v4 + v7);
  *(uint32_t *)(v9 + 68) = a3;
  *(uint16_t *)(v9 + 76) = a2;
  list_push_tail(dword_138B68, v6);
  v3[68] = v3[68]
         + 1
         - -64
         * ((unsigned int)(((unsigned int)dword_138B6C * (unsigned uint64_t)((unsigned int)(uint8_t)v3[68] + 1)) >> 32) >> 7);
  return v6;
}

