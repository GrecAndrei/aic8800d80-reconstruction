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

extern uint32_t off_12A684;
extern uint32_t dword_12A68C;
extern uint32_t dword_12A688;

// bt_chan_check @ 0x12a618, size 106 bytes
// Doc: bt_chan_check [bt]: Check BT channel/status byte (offset 0x18) against 0x7F
// bt_chan_check [bt]: Check BT channel/status byte (offset 0x18) against 0x7F
int  bt_chan_check(int result, uint8_t *a2, int a3, int a4)
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
      if ( **(int16_t **)off_12A684 < 0 )
      {
        if ( *(uint8_t *)(result + 106) )
        {
          v7 = a4;
          sub_12F694(dword_12A68C, dword_12A688, 64);
          a4 = v7;
        }
      }
      return sub_129FAC(v5, v4, *(uint32_t *)(v6 + 132) + a4);
    }
  }
  return result;
}

