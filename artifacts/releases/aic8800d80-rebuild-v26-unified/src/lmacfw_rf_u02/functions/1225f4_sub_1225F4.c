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

extern uint32_t off_122664;
extern uint32_t dword_122668;

// sub_1225F4 @ 0x1225f4, size 110 bytes
int  sub_1225F4(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r7
  unsigned int v6; // r6
  uint32_t *v7; // r4
  int v8; // r0

  if ( a1 == 1 )
  {
    rf_level_dump(1);
    return 0;
  }
  else
  {
    v4 = parse_int(*(uint8_t **)(a2 + 4), 0, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_122664;
      v4 = parse_int(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v4 > 0x7D0 )
        v7[91] = v4;
    }
    else
    {
      v7 = off_122664;
    }
    if ( *((uint8_t *)v7 + 363) != v5 )
    {
      *((uint8_t *)v7 + 363) = v5;
      if ( v6 )
      {
        v8 = rf_level_apply_n274(v4);
        sub_127108(v8);
      }
      else
      {
        rf_bus_write_n3d6_716c();
      }
    }
    msg_parse(dword_122668, v5, v7[91]);
    return 0;
  }
}

