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
extern uint32_t dword_104660;
extern uint32_t dword_104668;
extern uint32_t dword_104670;
extern uint32_t dword_104678;

// sub_104470 @ 0x104470, size 486 bytes
int  sub_104470(int a1, int a2, int a3)
{
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r0
  int v6; // r11
  int v7; // r10
  int v8; // r4
  int v9; // r0
  unsigned int v10; // s16
  uint64_t v11; // r8
  uint64_t v12; // r4
  uint64_t v13; // r6
  uint64_t v14; // r0
  uint64_t v15; // r0
  uint64_t v16; // r0
  uint64_t v17; // r0
  unsigned int v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  int result; // r0
  uint64_t v22; // r0
  uint64_t v23; // r0
  unsigned int v24; // s16
  uint64_t v25; // r8
  uint64_t v26; // r4
  uint64_t v27; // r6
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r0
  uint64_t v32; // r0
  uint64_t v33; // r0

  v3 = *(uint32_t *)(a3 + 4 * sub_1041E4(a1, a2, (uint32_t *)a3));
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
    v8 = sub_1437A4(v5);
    v9 = sub_1437A4(v4);
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
  v8 = sub_1437A4(v5);
  v9 = sub_1437A4(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    *(float *)&v10 = (float)v8 / (float)v9;
    v11 = sub_142A94(v10);
    v12 = sub_142B44(v11, *(uint64_t *)&dword_104658);
    v13 = sub_142A94(COERCE_UNSIGNED_INT((float)(*(float *)&v10 - 1.0) * *(float *)&v10));
    v14 = sub_142B44(v11, *(uint64_t *)&dword_104660);
    v15 = sub_1427D8(v14, *(uint64_t *)&dword_104668);
    v16 = sub_142B44(v13, v15);
    v17 = sub_1427D4(v12, v16);
    v18 = sub_143108(v17);
    v19 = sub_142A94(v18);
    v20 = sub_1427D4(*(uint64_t *)&dword_104670, v19);
    result = sub_143108(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  *(float *)&v24 = (float)v9 / (float)v8;
  v25 = sub_142A94(v24);
  v26 = sub_142B44(v25, *(uint64_t *)&dword_104658);
  v27 = sub_142A94(COERCE_UNSIGNED_INT((float)(*(float *)&v24 - 1.0) * *(float *)&v24));
  v28 = sub_142B44(v25, *(uint64_t *)&dword_104660);
  v29 = sub_1427D8(v28, *(uint64_t *)&dword_104668);
  v30 = sub_142B44(v27, v29);
  v31 = sub_1427D4(v26, v30);
  result = sub_143108(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = sub_142A94(result);
    v23 = sub_1427D4(v22, *(uint64_t *)&dword_104678);
    return sub_143108(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = sub_142A94(result ^ 0x80000000);
    v33 = sub_1427D8(v32, *(uint64_t *)&dword_104678);
    return sub_143108(v33);
  }
  return result;
}
