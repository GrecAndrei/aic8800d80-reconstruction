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

extern uint32_t dword_1064D8;
extern uint32_t dword_1064DC;
extern uint32_t dword_1064D0;
extern uint32_t dword_1064D4;

// init_callbacks @ 0x106450, size 124 bytes
int  init_callbacks(int a1, int a2, int a3)
{
  uint64_t v5; // r0
  int v6; // r0
  int v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5

  v5 = signed_int_to_double(a2);
  v6 = double_compare_core(v5, HIDWORD(v5), dword_1064D8, dword_1064DC);
  v7 = a1 + 4 * a3;
  v8 = double_to_int(v6);
  v9 = *(uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(log_float_converted(v8));
  v11 = *(uint64_t *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    check_feature_flag(1, dword_1064D0);
    if ( *(uint32_t *)(a1 + 172) <= v12 )
      goto LABEL_3;
LABEL_5:
    check_feature_flag(1, dword_1064D4);
    goto LABEL_3;
  }
  if ( *(uint32_t *)(a1 + 172) > v12 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return load_const_table(a1, a3);
}

