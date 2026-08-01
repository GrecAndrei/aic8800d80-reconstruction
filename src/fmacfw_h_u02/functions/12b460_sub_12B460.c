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

extern uint32_t off_12B688;
extern uint32_t dword_12B68C;
extern uint32_t dword_12B690;
extern uint32_t dword_12B6C0;
extern uint32_t off_12B6BC;
extern uint32_t dword_12B680;
extern uint32_t off_12B69C;
extern uint32_t dword_12B6A0;
extern uint32_t dword_12B678;
extern uint32_t dword_12B67C;
extern uint32_t off_12B694;
extern uint32_t dword_12B698;
extern uint32_t off_12B6A4;
extern uint32_t off_12B6A8;
extern uint32_t dword_12B6AC;
extern uint32_t off_12B6B0;
extern uint32_t off_12B6B4;

// rf_irq_service @ 0x12b460, size 530 bytes
unsigned int  rf_irq_service(unsigned int result)
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
  int v10; // r0
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
  unsigned int *v22; // r7
  int v23; // r0

  v1 = off_12B688;
  v2 = (uint8_t)*(uint32_t *)off_12B688;
  if ( result != v2 )
  {
    v3 = dword_12B68C;
    v4 = dword_12B690;
    v5 = dword_12B6C0;
    *(uint32_t *)off_12B6BC = ((0xF0 / result) << 8) & 0xF00 | *(uint32_t *)off_12B6BC & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = double_exp_check(dword_12B680);
      *v1 = v4 & (double_to_float_rounding(v21) << 18) | *v1 & v5;
      v22 = (unsigned int *)off_12B69C;
      v23 = double_exp_check(0);
      *v22 = dword_12B6A0 & (double_to_float_rounding(v23) << 20) | *v22 & 0xC00FFFFF;
    }
    else
    {
      v7 = signed_int_to_double(result);
      v8 = double_compare_common(v7, HIDWORD(v7), dword_12B678, dword_12B67C);
      v9 = double_to_int(v8);
      v10 = float_to_double(LODWORD(v9));
      v11 = double_exp_check(v10);
      *v1 = v4 & (double_to_float_rounding(v11) << 18) | *v1 & v5;
    }
    v12 = (unsigned int *)off_12B69C;
    *(uint32_t *)off_12B694 = dword_12B698 & ((v6 * (uint16_t)(*(uint32_t *)off_12B694 >> 8) / v2) << 8)
                          | *(uint32_t *)off_12B694 & 0xFF0000FF;
    *v12 = dword_12B6A0 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(uint32_t *)off_12B6A4 & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(uint32_t *)off_12B6A4 = v14;
    }
    v15 = off_12B6A8;
    v16 = dword_12B698;
    v17 = dword_12B6AC;
    v18 = (unsigned int *)off_12B6B0;
    *(uint32_t *)off_12B6A8 = dword_12B698 & ((v6 * (uint16_t)(*(uint32_t *)off_12B6A8 >> 8) / v2) << 8)
                          | *(uint32_t *)off_12B6A8 & dword_12B6AC;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (unsigned int *)off_12B6B4;
    v20 = dword_12B6A0;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}

