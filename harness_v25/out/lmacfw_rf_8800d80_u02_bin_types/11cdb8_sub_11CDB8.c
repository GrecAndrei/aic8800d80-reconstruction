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

extern uint32_t off_11CFE0;
extern uint32_t dword_11CFE4;
extern uint32_t dword_11CFE8;
extern uint32_t dword_11D018;
extern uint32_t off_11D014;
extern uint32_t dword_11CFD8;
extern uint32_t dword_11CFDC;
extern uint32_t dword_11D010;
extern uint32_t off_11CFF4;
extern uint32_t dword_11CFF8;
extern uint32_t dword_11CFD0;
extern uint32_t dword_11CFD4;
extern uint32_t off_11CFEC;
extern uint32_t dword_11CFF0;
extern uint32_t off_11CFFC;
extern uint32_t off_11D000;
extern uint32_t dword_11D004;
extern uint32_t off_11D008;
extern uint32_t off_11D00C;

// sub_11CDB8 @ 0x11cdb8, size 530 bytes
// Doc: sub_121CDB8 [util]: Check firmware ready flag from MMIO
// sub_121CDB8 [util]: Check firmware ready flag from MMIO
unsigned int  sub_11CDB8(unsigned int result)
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

  v1 = off_11CFE0;
  v2 = (uint8_t)*(uint32_t *)off_11CFE0;
  if ( result != v2 )
  {
    v3 = dword_11CFE4;
    v4 = dword_11CFE8;
    v5 = dword_11D018;
    *(uint32_t *)off_11D014 = ((0xF0 / result) << 8) & 0xF00 | *(uint32_t *)off_11D014 & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = math_round(dword_11CFD8, dword_11CFDC);
      v22 = sub_127BA4(v21);
      v23 = dword_11D010;
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (unsigned int *)off_11CFF4;
      v25 = math_round(0, v23);
      *v24 = dword_11CFF8 & (sub_127BA4(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = sub_12754C(result);
      v8 = sub_127620(v7, HIDWORD(v7), dword_11CFD0, dword_11CFD4);
      v9 = sub_127BE4(v8);
      v10 = sub_127570(LODWORD(v9));
      v11 = math_round(v10, HIDWORD(v10));
      *v1 = v4 & (sub_127BA4(v11) << 18) | *v1 & v5;
    }
    v12 = (unsigned int *)off_11CFF4;
    *(uint32_t *)off_11CFEC = dword_11CFF0 & ((v6 * (uint16_t)(*(uint32_t *)off_11CFEC >> 8) / v2) << 8)
                          | *(uint32_t *)off_11CFEC & 0xFF0000FF;
    *v12 = dword_11CFF8 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(uint32_t *)off_11CFFC & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(uint32_t *)off_11CFFC = v14;
    }
    v15 = off_11D000;
    v16 = dword_11CFF0;
    v17 = dword_11D004;
    v18 = (unsigned int *)off_11D008;
    *(uint32_t *)off_11D000 = dword_11CFF0 & ((v6 * (uint16_t)(*(uint32_t *)off_11D000 >> 8) / v2) << 8)
                          | *(uint32_t *)off_11D000 & dword_11D004;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (unsigned int *)off_11D00C;
    v20 = dword_11CFF8;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}

