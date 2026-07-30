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

extern uint32_t off_12A320;
extern uint32_t dword_12A328;
extern uint32_t dword_12A324;

// sub_12A2B4 @ 0x12a2b4, size 106 bytes
int  sub_12A2B4(int result, uint8_t *a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r6
  int v6; // r5
  int v7; // [sp+4h] [bp-4h]

  if ( a2[24] == 127 && !a2[29] && (uint8_t)a2[31] == 221 && a2[36] == 9 )
  {
    v4 = (int)(a2 + 37);
    if ( a2[37] == 12 )
    {
      v5 = *(uint8_t *)(result + 1225);
      v6 = result;
      if ( **(int16_t **)off_12A320 < 0 )
      {
        if ( *(uint8_t *)(result + 106) )
        {
          v7 = a4;
          sub_12F32C(dword_12A328, dword_12A324, 64);
          a4 = v7;
        }
      }
      return sub_129C48(v5, v4, *(uint32_t *)(v6 + 132) + a4);
    }
  }
  return result;
}

