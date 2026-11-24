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

// sub_107824 @ 0x107824, size 164 bytes
int  sub_107824(int a1, uint32_t *a2, int a3)
{
  int v3; // r8
  int v7; // s15
  int v8; // r2
  int v9; // r2

  v3 = *(uint32_t *)(a3 + 8);
  sub_12ECD0(1, "gain_base=%d\n", v3);
  sub_12ECD0(1, "pwr_hih=%d\n", a1);
  v7 = (int)(float)(COERCE_FLOAT(sub_12D6E0(COERCE_UNSIGNED_INT(vcvts_n_f32_u32(a1, 0xEu)))) * 10.0);
  sub_12ECD0(1, "pwr_db=%d\n", v7);
  v8 = a2[8];
  if ( v8 < v7 )
  {
    sub_12ECD0(1, "sat> %d \n", v8);
    v9 = a2[9];
    if ( v9 <= v7 )
      goto LABEL_3;
LABEL_5:
    sub_12ECD0(1, "sma %d\n", v9);
    goto LABEL_3;
  }
  v9 = a2[9];
  if ( v9 > v7 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(a3 + 8) = (int)COERCE_FLOAT(sub_12D708(COERCE_INT((float)(unsigned int)(a2[7] - v7 + v3))));
  return sub_107760(a3);
}
