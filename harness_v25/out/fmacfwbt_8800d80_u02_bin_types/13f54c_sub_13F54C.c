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

extern uint32_t dword_13F65C;
extern uint32_t dword_13F660;
extern uint32_t dword_13F664;
extern uint32_t off_13F668;

// sub_13F54C @ 0x13f54c, size 272 bytes
// Doc: sub_123F54C [bt]: Process indexed entry list (3x stride) with magic 0x1998 threshold
// sub_123F54C [bt]: Process indexed entry list (3x stride) with magic 0x1998 threshold
unsigned int  sub_13F54C(int a1, int a2, int a3)
{
  int v3; // r1
  int v4; // r3
  unsigned int v5; // r6
  unsigned int v6; // r3
  int v8; // r1
  int v9; // r12
  int v10; // r7
  unsigned int v11; // r3
  unsigned int v12; // r2
  int v13; // r4
  unsigned int v14; // r4
  unsigned int result; // r0
  unsigned int v16; // r2

  v3 = 3 * a2;
  v4 = a1 + 4 * v3;
  v5 = *(uint16_t *)(v4 + 8);
  if ( v5 <= 0x1998 )
    return 0;
  v6 = *(uint16_t *)(v4 + 10);
  v8 = 4 * v3;
  v9 = (v6 >> 11) & 7;
  if ( (v6 & 0x2000) != 0 )
  {
    v10 = (v6 >> 11) & 6;
    v11 = v6 & 0xF;
    v12 = *(uint32_t *)(a1 + 148);
    v13 = (uint8_t)v10;
    if ( v10 )
      goto LABEL_4;
  }
  else
  {
    if ( ((v6 >> 11) & 6) != 0 )
    {
      v12 = *(uint32_t *)(a1 + 148);
      v14 = dword_13F65C;
LABEL_6:
      v13 = v14 / HIWORD(v12);
      goto LABEL_7;
    }
    v12 = *(uint32_t *)(a1 + 148);
    v11 = v6 & 0x7F;
    v13 = 0;
  }
  if ( v11 > 3 )
  {
LABEL_4:
    v14 = dword_13F65C;
    if ( v9 == 6 )
      v14 = dword_13F660;
    goto LABEL_6;
  }
LABEL_7:
  result = (dword_13F664 * (1000 * v5 / (rx_desc_parse_n_ebbc(a1 + v8 + 4) + v13))) >> 16;
  if ( a3 )
  {
    if ( v5 <= 0x3332 )
    {
      return (uint64_t)(*(uint8_t *)off_13F668 * (unsigned uint64_t)result) >> 7;
    }
    else if ( v5 > 0x4CCB )
    {
      if ( v5 <= 0x6665 )
      {
        return (uint64_t)(*((uint8_t *)off_13F668 + 2) * (unsigned uint64_t)result) >> 7;
      }
      else if ( v5 >= 0x8000 )
      {
        if ( v5 > 0x9998 )
          v16 = *((uint8_t *)off_13F668 + 5);
        else
          v16 = *((uint8_t *)off_13F668 + 4);
        return (uint64_t)(v16 * (unsigned uint64_t)result) >> 7;
      }
      else
      {
        return (uint64_t)(*((uint8_t *)off_13F668 + 3) * (unsigned uint64_t)result) >> 7;
      }
    }
    else
    {
      return (uint64_t)(*((uint8_t *)off_13F668 + 1) * (unsigned uint64_t)result) >> 7;
    }
  }
  return result;
}

