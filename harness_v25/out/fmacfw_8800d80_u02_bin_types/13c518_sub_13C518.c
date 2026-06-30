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

extern uint32_t dword_13C690;
extern uint32_t dword_13C694;

// sub_13C518 @ 0x13c518, size 374 bytes
// Doc: sub_123C518 [unknown]: Parses indexed record header and dispatches by sub-byte tag
// sub_123C518 [unknown]: Parses indexed record header and dispatches by sub-byte tag
unsigned int  sub_13C518(uint8_t *a1, int a2, int a3, uint8_t *a4)
{
  int v4; // r6
  int v5; // r11
  int v6; // r9
  int v10; // r2
  int v11; // r3
  int v12; // r8
  int v13; // r7
  uint8_t *v15; // r0
  int v16; // lr
  int v17; // r12
  uint8_t *v18; // r1
  uint8_t *v19; // r0
  uint8_t *v20; // r1
  int v21; // t1
  int v22; // r9
  int v23; // r10
  int v24; // r0
  int v25; // r1
  int v26; // zf
  int v27; // r11
  uint64_t v28; // [sp+8h] [bp-Ch]

  v4 = a1[8];
  v5 = *(uint16_t *)a1;
  v6 = *(uint8_t *)(v4 + a2);
  if ( !sub_13C484(v5, v6) )
    return 0;
  v11 = a1[9];
  if ( v11 == 255 )
    goto LABEL_9;
  v12 = a1[10];
  if ( v12 == 255 )
    goto LABEL_9;
  v13 = v10;
  if ( !*(uint32_t *)(dword_13C690 + 1320 * v12 + 1200) )
    return 0;
  if ( (a1[48] & 8) == 0 )
  {
    if ( (*(uint32_t *)(dword_13C694 + 696 * v11 + 4) & 8) != 0 && (v5 & 0x4000) == 0 )
    {
      v27 = v5 & 0xFC;
      if ( (v27 == 192 || v27 == 160) && (unsigned int)(v6 - 6) <= 1 )
      {
        *a4 = 1;
        return 1;
      }
LABEL_9:
      *a4 = 0;
      return 1;
    }
    return 0;
  }
  if ( (v5 & 0xFC) != 0xD0 || (unsigned int)(v6 - 13) > 1 )
  {
    if ( *(uint32_t *)(dword_13C690 + 1320 * v12 + 1204) )
    {
      if ( v4 + 19 >= v10 )
        goto LABEL_9;
      v15 = sub_12DBA0((uint8_t *)(v4 + a2 + 2), (uint16_t)(v10 - 2 - v4));
      if ( !v15 )
        goto LABEL_9;
      v16 = *((uint16_t *)v15 + 1);
      if ( (unsigned int)(v16 - 4) > 1 )
        goto LABEL_9;
      v17 = 1320 * v12 + 120 * v16 + dword_13C690;
      if ( !*(uint8_t *)(v17 + 579) )
        goto LABEL_9;
      v28 = *((uint32_t *)v15 + 1) & 0xFFFFFFLL;
      if ( *(uint64_t *)(v17 + 480) >= (unsigned uint64_t)(*((uint32_t *)v15 + 1) & 0xFFFFFF) )
        goto LABEL_9;
      v18 = v15;
      v19 = v15 + 18;
      v21 = *(uint32_t *)(v18 + 10);
      v20 = v18 + 10;
      v22 = v21;
      v23 = *((uint32_t *)v20 + 1);
      *(uint64_t *)(v17 + 480) = v28;
      do
        *v20++ = 0;
      while ( v20 != v19 );
      v24 = sub_13CBEC(1320 * v12 + 480 + 120 * v16 + dword_13C690, a2, v13 - 18, v4, 0);
      v26 = v23 == v25;
      if ( v23 == v25 )
        v26 = v22 == v24;
      if ( !v26 )
        goto LABEL_9;
    }
    return 0;
  }
  return ((v5 ^ 0x4000u) >> 14) & 1;
}

