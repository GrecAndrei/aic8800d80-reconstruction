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

extern uint32_t off_1301AC;
extern uint32_t dword_1301B0;

// sub_13013C @ 0x13013c, size 110 bytes
int  sub_13013C(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r7
  unsigned int v6; // r6
  uint32_t *v7; // r4
  int v8; // r0

  if ( a1 == 1 )
  {
    rf_level_dump_05bc();
    return 0;
  }
  else
  {
    v4 = sub_12FB74(*(uint8_t **)(a2 + 4), 0, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_1301AC;
      v4 = sub_12FB74(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v4 > 0x7D0 )
        v7[91] = v4;
    }
    else
    {
      v7 = off_1301AC;
    }
    if ( *((uint8_t *)v7 + 363) != v5 )
    {
      *((uint8_t *)v7 + 363) = v5;
      if ( v6 )
      {
        v8 = sub_130714(v4);
        sub_1307D0(v8);
      }
      else
      {
        bt_fmac_init_n_42e();
      }
    }
    sub_12ECB0(dword_1301B0, v5, v7[91]);
    return 0;
  }
}

