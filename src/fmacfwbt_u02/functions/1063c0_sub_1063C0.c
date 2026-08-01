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

extern uint32_t dword_106448;
extern uint32_t dword_10644C;
extern uint32_t dword_106440;
extern uint32_t dword_106444;

// log_message @ 0x1063c0, size 124 bytes
// Doc: sub_12063C0 [util]: Init/setup wrapper calling address-table lookup and helper routines
// sub_12063C0 [util]: Init/setup wrapper calling address-table lookup and helper routines
int  log_message(int a1, int a2, int a3)
{
  uint64_t v5; // r0
  int v6; // r0
  int v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5

  v5 = __aeabi_i2d(a2);
  v6 = __aeabi_ddiv(v5, HIDWORD(v5), dword_106448, dword_10644C);
  v7 = a1 + 4 * a3;
  v8 = double_to_float(v6);
  v9 = *(uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(system_init_sequence(v8));
  v11 = *(uint64_t *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    state_check_feature(1, dword_106440);
    if ( *(uint32_t *)(a1 + 172) <= v12 )
      goto LABEL_3;
LABEL_5:
    state_check_feature(1, dword_106444);
    goto LABEL_3;
  }
  if ( *(uint32_t *)(a1 + 172) > v12 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return rf_load_calib_data(a1, a3);
}

