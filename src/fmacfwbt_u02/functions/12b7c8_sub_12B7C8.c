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

extern uint32_t off_12B9F0;
extern uint32_t dword_12B9F4;
extern uint32_t dword_12B9F8;
extern uint32_t dword_12BA28;
extern uint32_t off_12BA24;
extern uint32_t dword_12B9E8;
extern uint32_t dword_12B9EC;
extern uint32_t dword_12BA20;
extern uint32_t off_12BA04;
extern uint32_t dword_12BA08;
extern uint32_t dword_12B9E0;
extern uint32_t dword_12B9E4;
extern uint32_t off_12B9FC;
extern uint32_t dword_12BA00;
extern uint32_t off_12BA0C;
extern uint32_t off_12BA10;
extern uint32_t dword_12BA14;
extern uint32_t off_12BA18;
extern uint32_t off_12BA1C;

// rf_wait_event @ 0x12b7c8, size 530 bytes
// Doc: sub_122B7C8 [unknown]: unknown behavioral stub in fmac firmware bluetooth variant
// sub_122B7C8 [unknown]: unknown behavioral stub in fmac firmware bluetooth variant
unsigned int  rf_wait_event(unsigned int result)
{
  uint32_t *v1; // r6
  unsigned int v2; // r5
  int v3; // r2
  int v4; // r7
  int v5; // r8
  unsigned int v6; // r4
  uint64_t v7; // r0
  int v8; // r0
  float v9; // r0
  uint64_t v10; // r0
  int v11; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r3
  int v14; // r3
  uint32_t *v15; // r6
  int v16; // r2
  int v17; // r0
  unsigned int *v18; // r1
  unsigned int *v19; // r2
  int v20; // r1
  int v21; // r0
  int v22; // r0
  int v23; // r1
  unsigned int *v24; // r7
  int v25; // r0

  v1 = off_12B9F0;
  v2 = (uint8_t)*(uint32_t *)off_12B9F0;
  if ( result != v2 )
  {
    v3 = dword_12B9F4;
    v4 = dword_12B9F8;
    v5 = dword_12BA28;
    *(uint32_t *)off_12BA24 = ((0xF0 / result) << 8) & 0xF00 | *(uint32_t *)off_12BA24 & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = softfloat_float_op(dword_12B9E8, dword_12B9EC);
      v22 = __aeabi_d2ulz(v21);
      v23 = dword_12BA20;
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (unsigned int *)off_12BA04;
      v25 = softfloat_float_op(0, v23);
      *v24 = dword_12BA08 & (__aeabi_d2ulz(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = __aeabi_i2d(result);
      v8 = __aeabi_dmul(v7, HIDWORD(v7), dword_12B9E0, dword_12B9E4);
      v9 = double_to_float(v8);
      v10 = __aeabi_f2d(LODWORD(v9));
      v11 = softfloat_float_op(v10, HIDWORD(v10));
      *v1 = v4 & (__aeabi_d2ulz(v11) << 18) | *v1 & v5;
    }
    v12 = (unsigned int *)off_12BA04;
    *(uint32_t *)off_12B9FC = dword_12BA00 & ((v6 * (uint16_t)(*(uint32_t *)off_12B9FC >> 8) / v2) << 8)
                          | *(uint32_t *)off_12B9FC & 0xFF0000FF;
    *v12 = dword_12BA08 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(uint32_t *)off_12BA0C & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(uint32_t *)off_12BA0C = v14;
    }
    v15 = off_12BA10;
    v16 = dword_12BA00;
    v17 = dword_12BA14;
    v18 = (unsigned int *)off_12BA18;
    *(uint32_t *)off_12BA10 = dword_12BA00 & ((v6 * (uint16_t)(*(uint32_t *)off_12BA10 >> 8) / v2) << 8)
                          | *(uint32_t *)off_12BA10 & dword_12BA14;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (unsigned int *)off_12BA1C;
    v20 = dword_12BA08;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}

