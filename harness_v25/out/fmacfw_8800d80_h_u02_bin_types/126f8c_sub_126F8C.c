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

extern uint32_t off_12701C;
extern uint32_t off_127020;
extern uint32_t off_127024;
extern uint32_t off_127028;
extern uint32_t dword_12702C;

// sub_126F8C @ 0x126f8c, size 144 bytes
int  sub_126F8C(int result)
{
  uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  uint8_t *v4; // r0
  int *v5; // r6
  int v6; // r3
  int v7; // r2
  uint32_t *v8; // r0

  v1 = off_12701C;
  v2 = result;
  if ( *((uint32_t *)off_12701C + 11) )
  {
    *((uint32_t *)off_12701C + 11) = result;
  }
  else
  {
    v3 = *((uint32_t *)off_12701C + 10);
    if ( v3 == result )
    {
      *(uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (uint8_t *)sub_12C7EC(69, 13, 0, 1);
        *v4 = *(uint8_t *)(v3 + 24);
        sub_12C84C(v4);
      }
      if ( *((int *)off_127020 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_127024 = 1;
        }
        v5 = (int *)off_127028;
        ++*(uint32_t *)off_127028;
        sub_116DF4(4);
        sub_11735C(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(uint32_t *)off_127024;
          *v5 = v6;
          if ( !v6 )
          {
            if ( v7 )
              __enable_irq();
          }
        }
      }
      v1[11] = v2;
      *(uint8_t *)(v2 + 16) = 2;
      v8 = (uint32_t *)sub_12C7EC(140, 0, 255, 4);
      *v8 = dword_12702C;
      return sub_12C84C(v8);
    }
  }
  return result;
}

