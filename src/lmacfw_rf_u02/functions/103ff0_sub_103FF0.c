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

extern uint32_t dword_1041D8;
extern uint32_t dword_1041DC;
extern uint32_t dword_1041E0;
extern uint32_t dword_1041E4;
extern uint32_t dword_1041E8;
extern uint32_t dword_1041EC;
extern uint32_t dword_1041F0;
extern uint32_t dword_1041F4;
extern uint32_t dword_1041F8;
extern uint32_t dword_1041FC;

// apply_tx_power @ 0x103ff0, size 486 bytes
int  apply_tx_power(int a1, int a2, uint32_t *a3)
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

  v3 = a3[rand(a1, a2, a3)];
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
    v8 = i32_abs(v5);
    v9 = i32_abs(v4);
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
  v8 = i32_abs(v5);
  v9 = i32_abs(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    v10 = (float)v8 / (float)v9;
    v11 = aeabi_d2f(LODWORD(v10));
    v12 = aeabi_dadd(v11, HIDWORD(v11), dword_1041D8, dword_1041DC);
    v13 = aeabi_d2f((float)(v10 - 1.0) * v10);
    v14 = aeabi_dadd(v11, HIDWORD(v11), dword_1041E0, dword_1041E4);
    v15 = double_add(v14, HIDWORD(v14), dword_1041E8, dword_1041EC);
    v16 = aeabi_dadd(v13, HIDWORD(v13), v15, HIDWORD(v15));
    v17 = double_subtract(v12, HIDWORD(v12), v16, HIDWORD(v16));
    v18 = aeabi_dmul(v17);
    v19 = aeabi_d2f(v18);
    v20 = double_subtract(dword_1041F0, dword_1041F4, v19, HIDWORD(v19));
    result = aeabi_dmul(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  v24 = (float)v9 / (float)v8;
  v25 = aeabi_d2f(LODWORD(v24));
  v26 = aeabi_dadd(v25, HIDWORD(v25), dword_1041D8, dword_1041DC);
  v27 = aeabi_d2f((float)(v24 - 1.0) * v24);
  v28 = aeabi_dadd(v25, HIDWORD(v25), dword_1041E0, dword_1041E4);
  v29 = double_add(v28, HIDWORD(v28), dword_1041E8, dword_1041EC);
  v30 = aeabi_dadd(v27, HIDWORD(v27), v29, HIDWORD(v29));
  v31 = double_subtract(v26, HIDWORD(v26), v30, HIDWORD(v30));
  result = aeabi_dmul(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = aeabi_d2f(result);
    v23 = double_subtract(v22, HIDWORD(v22), dword_1041F8, dword_1041FC);
    return aeabi_dmul(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = aeabi_d2f(result ^ 0x80000000);
    v33 = double_add(v32, HIDWORD(v32), dword_1041F8, dword_1041FC);
    return aeabi_dmul(v33);
  }
  return result;
}

