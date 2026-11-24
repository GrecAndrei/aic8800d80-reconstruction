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


extern float flt_10510C;
extern float flt_105114;

// sub_105070 @ 0x105070, size 154 bytes
int  sub_105070(int a1, int a2, int a3)
{
  float v6; // s14
  int v7; // r3
  uint64_t v9; // r8
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r0
  float v13; // r0
  float v14; // s14
  uint64_t v15; // r8
  uint64_t v16; // r0
  uint64_t v17; // r0
  unsigned int v18; // r0

  if ( a1 > a2 )
  {
    v15 = sub_142894(a1);
    v16 = sub_142894(a2);
    v17 = sub_142BBC(v15, v16);
    v18 = sub_142F2C(v17);
    v13 = COERCE_FLOAT(sub_12D5A0(v18));
    v14 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v9 = sub_142894(a2);
    v10 = sub_142894(a1);
    v11 = sub_142BBC(v9, v10);
    v12 = sub_142F2C(v11);
    v13 = COERCE_FLOAT(sub_12D5A0(v12));
    v14 = -20.0;
LABEL_6:
    v6 = v13 * v14;
    v7 = (int)(float)(v6 * flt_105114);
    goto LABEL_4;
  }
  v6 = flt_10510C;
  v7 = 0;
LABEL_4:
  *(float *)(a3 + 96) = v6;
  return sub_12EB90(1, "am_back_cur=%d am_back_base=%d pwr_act_diff*100=%d\n", a1, a2, v7);
}
