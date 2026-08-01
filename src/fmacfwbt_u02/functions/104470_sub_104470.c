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

extern uint32_t dword_104658;
extern uint32_t dword_10465C;
extern uint32_t dword_104660;
extern uint32_t dword_104664;
extern uint32_t dword_104668;
extern uint32_t dword_10466C;
extern uint32_t dword_104670;
extern uint32_t dword_104674;
extern uint32_t dword_104678;
extern uint32_t dword_10467C;

// tx_parse_desc @ 0x104470, size 486 bytes
int  tx_parse_desc(int a1, int a2, uint32_t *a3)
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

  v3 = a3[util_get_hw_index(a1, a2, a3)];
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
    v8 = absolute_value(v5);
    v9 = absolute_value(v4);
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
  v8 = absolute_value(v5);
  v9 = absolute_value(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    v10 = (float)v8 / (float)v9;
    v11 = __aeabi_f2d(LODWORD(v10));
    v12 = __aeabi_dmul(v11, HIDWORD(v11), dword_104658, dword_10465C);
    v13 = __aeabi_f2d((float)(v10 - 1.0) * v10);
    v14 = __aeabi_dmul(v11, HIDWORD(v11), dword_104660, dword_104664);
    v15 = __aeabi_dadd(v14, HIDWORD(v14), dword_104668, dword_10466C);
    v16 = __aeabi_dmul(v13, HIDWORD(v13), v15, HIDWORD(v15));
    v17 = __aeabi_dsub(v12, HIDWORD(v12), v16, HIDWORD(v16));
    v18 = double_to_float(v17);
    v19 = __aeabi_f2d(v18);
    v20 = __aeabi_dsub(dword_104670, dword_104674, v19, HIDWORD(v19));
    result = double_to_float(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  v24 = (float)v9 / (float)v8;
  v25 = __aeabi_f2d(LODWORD(v24));
  v26 = __aeabi_dmul(v25, HIDWORD(v25), dword_104658, dword_10465C);
  v27 = __aeabi_f2d((float)(v24 - 1.0) * v24);
  v28 = __aeabi_dmul(v25, HIDWORD(v25), dword_104660, dword_104664);
  v29 = __aeabi_dadd(v28, HIDWORD(v28), dword_104668, dword_10466C);
  v30 = __aeabi_dmul(v27, HIDWORD(v27), v29, HIDWORD(v29));
  v31 = __aeabi_dsub(v26, HIDWORD(v26), v30, HIDWORD(v30));
  result = double_to_float(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = __aeabi_f2d(result);
    v23 = __aeabi_dsub(v22, HIDWORD(v22), dword_104678, dword_10467C);
    return double_to_float(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = __aeabi_f2d(result ^ 0x80000000);
    v33 = __aeabi_dadd(v32, HIDWORD(v32), dword_104678, dword_10467C);
    return double_to_float(v33);
  }
  return result;
}

