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

extern uint32_t off_12A460;
extern uint32_t dword_12A468;
extern uint32_t dword_12A464;

// sub_12A3F4 @ 0x12a3f4, size 106 bytes
// Doc: sub_122A3F4 [util]: Check byte field against 0x7f and branch accordingly
// sub_122A3F4 [util]: Check byte field against 0x7f and branch accordingly
int  sub_12A3F4(int result, uint8_t *a2, int a3, int a4)
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
      if ( **(int16_t **)off_12A460 < 0 )
      {
        if ( *(uint8_t *)(result + 106) )
        {
          v7 = a4;
          sub_12F46C(dword_12A468, dword_12A464, 64);
          a4 = v7;
        }
      }
      return sub_129D88(v5, v4, *(uint32_t *)(v6 + 132) + a4);
    }
  }
  return result;
}

