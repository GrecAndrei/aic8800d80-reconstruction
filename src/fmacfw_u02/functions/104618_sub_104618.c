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

extern uint32_t dword_104800;
extern uint32_t dword_104804;
extern uint32_t dword_104808;
extern uint32_t dword_10480C;
extern uint32_t dword_104810;
extern uint32_t dword_104814;
extern uint32_t dword_104818;
extern uint32_t dword_10481C;
extern uint32_t dword_104820;
extern uint32_t dword_104824;

// handle_tx_descriptor @ 0x104618, size 486 bytes
int  handle_tx_descriptor(int a1, int a2, uint32_t *a3)
{
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r0
  int v6; // r11
  int v7; // r10
  int v8; // r4
  int v9; // r0
  float v10; // s16
  uint64_t v11; // r8
  uint64_t v12; // r4
  uint64_t v13; // r6
  uint64_t v14; // r0
  uint64_t v15; // r0
  uint64_t v16; // r0
  int v17; // r0
  int v18; // r0
  uint64_t v19; // r0
  int v20; // r0
  int result; // r0
  uint64_t v22; // r0
  int v23; // r0
  float v24; // s16
  uint64_t v25; // r8
  uint64_t v26; // r4
  uint64_t v27; // r6
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  int v31; // r0
  uint64_t v32; // r0
  int v33; // r0

  v3 = a3[get_next_sequence(a1, a2, a3)];
  v4 = (uint16_t)v3 >> 4;
  if ( (v3 & 0x80000000) == 0 )
  {
    v5 = v3 >> 20;
    if ( ((v3 >> 4) & 0x800) != 0 )
    {
      v4 -= 4096;
      v6 = 1;
      v7 = -1;
    }
    else
    {
      v6 = 1;
      v7 = 1;
    }
LABEL_4:
    v8 = abs_i32(v5);
    v9 = abs_i32(v4);
    if ( v8 < v9 )
      goto LABEL_5;
    goto LABEL_11;
  }
  v5 = (v3 >> 20) - 4096;
  if ( ((v3 >> 4) & 0x800) == 0 )
  {
    v6 = -1;
    v7 = 1;
    goto LABEL_4;
  }
  v8 = abs_i32(v5);
  v9 = abs_i32(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    v10 = (float)v8 / (float)v9;
    v11 = float_to_double(LODWORD(v10));
    v12 = double_add(v11, HIDWORD(v11), dword_104800, dword_104804);
    v13 = float_to_double((float)(v10 - 1.0) * v10);
    v14 = double_add(v11, HIDWORD(v11), dword_104808, dword_10480C);
    v15 = double_compare(v14, HIDWORD(v14), dword_104810, dword_104814);
    v16 = double_add(v13, HIDWORD(v13), v15, HIDWORD(v15));
    v17 = double_compare_wrapper(v12, HIDWORD(v12), v16, HIDWORD(v16));
    v18 = double_to_uint(v17);
    v19 = float_to_double(v18);
    v20 = double_compare_wrapper(dword_104818, dword_10481C, v19, HIDWORD(v19));
    result = double_to_uint(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  v24 = (float)v9 / (float)v8;
  v25 = float_to_double(LODWORD(v24));
  v26 = double_add(v25, HIDWORD(v25), dword_104800, dword_104804);
  v27 = float_to_double((float)(v24 - 1.0) * v24);
  v28 = double_add(v25, HIDWORD(v25), dword_104808, dword_10480C);
  v29 = double_compare(v28, HIDWORD(v28), dword_104810, dword_104814);
  v30 = double_add(v27, HIDWORD(v27), v29, HIDWORD(v29));
  v31 = double_compare_wrapper(v26, HIDWORD(v26), v30, HIDWORD(v30));
  result = double_to_uint(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = float_to_double(result);
    v23 = double_compare_wrapper(v22, HIDWORD(v22), dword_104820, dword_104824);
    return double_to_uint(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = float_to_double(result ^ 0x80000000);
    v33 = double_compare(v32, HIDWORD(v32), dword_104820, dword_104824);
    return double_to_uint(v33);
  }
  return result;
}

