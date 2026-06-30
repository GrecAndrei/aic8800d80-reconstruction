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

extern uint32_t off_12D344;
extern uint32_t dword_12D34C;
extern uint32_t dword_12D348;

// sub_12D2E8 @ 0x12d2e8, size 90 bytes
int  sub_12D2E8(int result, uint32_t *a2)
{
  int v2; // r5
  uint32_t *v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r3

  v2 = result;
  if ( **(int16_t **)off_12D344 < 0 && !result )
    result = sub_12F46C(dword_12D34C, dword_12D348, 132);
  v4 = *(uint32_t **)v2;
  if ( *(uint32_t *)v2 )
  {
    if ( v4 == a2 )
    {
      v6 = *(uint32_t **)(v2 + 4);
      *(uint32_t *)v2 = *a2;
      if ( v6 == a2 )
        *(uint32_t *)(v2 + 4) = 0;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 = (uint32_t *)*v4;
        if ( !v4 )
          break;
        if ( v4 == a2 )
        {
          if ( *(uint32_t **)(v2 + 4) == a2 )
            *(uint32_t *)(v2 + 4) = v5;
          *v5 = *a2;
          return result;
        }
      }
    }
  }
  return result;
}

