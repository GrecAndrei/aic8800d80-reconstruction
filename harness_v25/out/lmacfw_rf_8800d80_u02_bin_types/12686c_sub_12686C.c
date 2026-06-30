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

extern uint32_t off_1268D8;
extern uint32_t dword_1268DC;
extern uint32_t dword_1268E8;
extern uint32_t dword_1268E0;
extern uint32_t dword_1268E4;

// sub_12686C @ 0x12686c, size 108 bytes
// Doc: sub_122686C [rf]: Reads flag byte from global base, RF state poll
// sub_122686C [rf]: Reads flag byte from global base, RF state poll
int  sub_12686C(int result)
{
  uint16_t *v1; // r7
  int *v2; // r1
  int v3; // r12
  int v4; // r6
  int v5; // r5
  int v6; // r4
  int v7; // r2
  unsigned int v8; // r3
  unsigned int v9; // t1
  unsigned int v10; // r2
  int v11; // r2

  v1 = (uint16_t *)off_1268D8;
  if ( !*((uint8_t *)off_1268D8 + 36) )
  {
    v2 = (int *)dword_1268DC;
    v3 = dword_1268E8;
    v4 = dword_1268E0;
    v5 = dword_1268E4;
    v6 = dword_1268DC + 128;
    while ( 1 )
    {
      while ( 1 )
      {
        v9 = v2[1];
        ++v2;
        v8 = v9;
        v10 = v9 >> 8;
        if ( ((v9 >> 8) & 0xC) != 0 )
          break;
LABEL_7:
        if ( (int *)v6 == v2 )
          return mmio_set_bit_120090C(0, v1[20]);
      }
      v11 = v10 & 0xF;
      if ( result )
      {
        if ( v11 == 4 )
        {
          v7 = 0x1000000;
        }
        else if ( v11 == 7 )
        {
          v7 = 0;
        }
        else
        {
          v7 = (15 - v11) << 24;
        }
        *v2 = v8 & v5 | v7;
        goto LABEL_7;
      }
      *v2 = v8 & v3 | v4;
      if ( (int *)v6 == v2 )
        return mmio_set_bit_120090C(0, v1[20]);
    }
  }
  return result;
}

