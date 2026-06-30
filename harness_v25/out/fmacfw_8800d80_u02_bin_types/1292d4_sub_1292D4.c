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

extern uint32_t off_12936C;
extern uint32_t dword_129374;
extern uint32_t dword_129370;
extern uint32_t off_12937C;
extern uint32_t off_129378;
extern uint32_t off_129380;
extern uint32_t off_129384;
extern uint32_t off_129388;
extern uint32_t off_129390;
extern uint32_t off_12938C;

// sub_1292D4 @ 0x1292d4, size 150 bytes
void  sub_1292D4(int a1)
{
  uint8_t *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  uint32_t *v6; // r3

  v1 = off_12936C;
  if ( *(uint8_t *)off_12936C )
  {
    v2 = *(uint8_t *)(a1 + 29);
    if ( v2 != 255 && *(uint8_t *)(a1 + 27) != 255 )
    {
      v3 = dword_129374 + 1320 * *(uint8_t *)(dword_129370 + 696 * v2 + 34);
      if ( !*(uint8_t *)(v3 + 106) )
      {
        if ( *(uint8_t *)(v3 + 108) )
        {
          v4 = *((uint32_t *)off_12937C + 4);
          v5 = *(uint16_t *)(*(uint32_t *)off_129378 + 54);
          *((uint32_t *)off_12936C + 5) = v3;
          v1[29] = 3;
          timestamp_update((int)(v1 + 12), v4 + v5);
          if ( (*(uint32_t *)off_129380 & 4) != 0 )
          {
            if ( *((uint8_t *)off_129384 + 190) )
            {
              if ( **(uint8_t **)off_129388 == 2 )
              {
                v6 = off_129390;
                *(uint32_t *)off_12938C &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            sub_128EA0();
          }
        }
      }
    }
  }
}

