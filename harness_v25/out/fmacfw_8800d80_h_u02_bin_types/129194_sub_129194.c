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

extern uint32_t off_12922C;
extern uint32_t dword_129234;
extern uint32_t dword_129230;
extern uint32_t off_12923C;
extern uint32_t off_129238;
extern uint32_t off_129240;
extern uint32_t off_129244;
extern uint32_t off_129248;
extern uint32_t off_129250;
extern uint32_t off_12924C;

// sub_129194 @ 0x129194, size 150 bytes
void  sub_129194(int a1)
{
  uint8_t *v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r1
  int v5; // r0
  uint32_t *v6; // r3

  v1 = off_12922C;
  if ( *(uint8_t *)off_12922C )
  {
    v2 = *(uint8_t *)(a1 + 29);
    if ( v2 != 255 && *(uint8_t *)(a1 + 27) != 255 )
    {
      v3 = dword_129234 + 1320 * *(uint8_t *)(dword_129230 + 696 * v2 + 34);
      if ( !*(uint8_t *)(v3 + 106) )
      {
        if ( *(uint8_t *)(v3 + 108) )
        {
          v4 = *((uint32_t *)off_12923C + 4);
          v5 = *(uint16_t *)(*(uint32_t *)off_129238 + 54);
          *((uint32_t *)off_12922C + 5) = v3;
          v1[29] = 3;
          sub_124BFC((int)(v1 + 12), v4 + v5);
          if ( (*(uint32_t *)off_129240 & 4) != 0 )
          {
            if ( *((uint8_t *)off_129244 + 190) )
            {
              if ( **(uint8_t **)off_129248 == 2 )
              {
                v6 = off_129250;
                *(uint32_t *)off_12924C &= ~0x200u;
                *v6 &= ~1u;
                *v6 &= ~0x80u;
              }
            }
            sub_128D60();
          }
        }
      }
    }
  }
}

