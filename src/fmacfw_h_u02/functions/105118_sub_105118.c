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

extern uint32_t dword_1051C8;
extern uint32_t dword_1051CC;
extern uint32_t dword_1051C4;

// div_by_20 @ 0x105118, size 168 bytes
int  div_by_20(float a1, int a2, int a3)
{
  float v5; // r0
  int v6; // r0
  uint64_t v7; // r0
  int16_t v8; // r0
  uint64_t v9; // kr00_8
  uint64_t v11; // kr08_8

  v5 = load_version_string(a1 / 20.0);
  v6 = float_to_double((float)a2 * v5);
  v7 = double_exp_check(v6);
  v8 = double_to_float(v7, HIDWORD(v7));
  if ( v8 <= 232 )
  {
    if ( v8 > 31 )
    {
      *(uint8_t *)(a3 + 104) = v8;
    }
    else
    {
      v11 = *(uint64_t *)(a3 + 112);
      *(uint8_t *)(a3 + 104) = 32;
      if ( SHIDWORD(v11) < (int)v11 )
        alloc_tx_event(dword_1051C8, HIDWORD(v11), v11);
    }
  }
  else
  {
    v9 = *(uint64_t *)(a3 + 112);
    *(uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v9) < (int)v9 )
      alloc_tx_event(dword_1051CC, HIDWORD(v9), v9);
  }
  return check_feature_flag(1, dword_1051C4);
}

