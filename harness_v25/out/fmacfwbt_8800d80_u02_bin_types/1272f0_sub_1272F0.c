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

extern uint32_t off_127380;
extern uint32_t off_127384;
extern uint32_t off_127388;
extern uint32_t off_12738C;
extern uint32_t dword_127390;

// sub_1272F0 @ 0x1272f0, size 144 bytes
// Doc: sub_12272F0 [util]: Helper using global table at 0x190c30 with offset 0x2c
// sub_12272F0 [util]: Helper using global table at 0x190c30 with offset 0x2c
int  sub_1272F0(int result)
{
  uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  uint8_t *v4; // r0
  int *v5; // r6
  int v6; // r3
  int v7; // r2
  uint32_t *v8; // r0

  v1 = off_127380;
  v2 = result;
  if ( *((uint32_t *)off_127380 + 11) )
  {
    *((uint32_t *)off_127380 + 11) = result;
  }
  else
  {
    v3 = *((uint32_t *)off_127380 + 10);
    if ( v3 == result )
    {
      *(uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (uint8_t *)rf_bus_setup_n3a8(69, 13, 0, 1);
        *v4 = *(uint8_t *)(v3 + 24);
        sub_12CBB4(v4);
      }
      if ( *((int *)off_127384 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_127388 = 1;
        }
        v5 = (int *)off_12738C;
        ++*(uint32_t *)off_12738C;
        patch_sub_1217374(4);
        sub_1178DC(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(uint32_t *)off_127388;
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
      v8 = (uint32_t *)rf_bus_setup_n3a8(140, 0, 255, 4);
      *v8 = dword_127390;
      return sub_12CBB4(v8);
    }
  }
  return result;
}

