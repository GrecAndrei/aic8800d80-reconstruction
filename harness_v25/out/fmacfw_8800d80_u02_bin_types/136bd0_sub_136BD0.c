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

extern uint32_t off_136D08;
extern uint32_t dword_136D10;
extern uint32_t dword_136D0C;
extern uint32_t dword_136D04;

// sub_136BD0 @ 0x136bd0, size 306 bytes
// Doc: sub_1236BD0 [tx]: TX-related state machine dispatch (mode byte at +0x6a vs 2)
// sub_1236BD0 [tx]: TX-related state machine dispatch (mode byte at +0x6a vs 2)
int ** sub_136BD0(int a1, int a2, uint32_t *a3)
{
  int v3; // r7
  int v5; // r2
  int v7; // r8
  int **v8; // r4
  char v9; // r1
  int v10; // r5
  BOOL v11; // r2
  int ***v12; // r10
  int v13; // r1
  char v14; // r3
  int **v15; // r3
  BOOL v16; // r1
  int v18; // r7
  int v19; // r0

  v3 = *(uint8_t *)(a1 + 106);
  if ( v3 != 2 || (v5 = *(uint8_t *)(a2 + 54), !*(uint8_t *)(a2 + 54)) )
  {
    *a3 = 0;
    return 0;
  }
  v7 = v5 & 1;
  if ( (v5 & 1) == 0 )
  {
    v3 = 8;
    v7 = 4;
  }
  if ( ((uint8_t)v3 & *(uint8_t *)(a2 + 53)) == 0 )
    goto LABEL_26;
  v8 = *(int ***)(a2 + 572);
  if ( !v8 )
  {
LABEL_24:
    if ( **(int16_t **)off_136D08 < 0 )
      sub_12F49C(dword_136D10, dword_136D0C, 441);
LABEL_26:
    *a3 = 1;
    return 0;
  }
  v9 = *(uint8_t *)(a2 + 310);
  v10 = dword_136D04;
  v11 = v5 == 2;
  v12 = 0;
  while ( ((uint8_t)(v9 & *(uint8_t *)(dword_136D04 + *((uint8_t *)v8 + 27))) == 0) == v11 )
  {
    v12 = (int ***)v8;
    if ( !*v8 )
      goto LABEL_24;
    v8 = (int **)*v8;
  }
  sub_12D460(a2 + 572, v12, v8);
  v13 = *(uint8_t *)(a2 + 54);
  if ( (v13 & 8) != 0 )
    v14 = 4;
  else
    v14 = 3;
  *((uint8_t *)v8 + 27) = v14;
  if ( v12 )
    v15 = *v12;
  else
    v15 = *(int ***)(a2 + 572);
  if ( v15 )
  {
    v16 = v13 == 2;
    while ( ((uint8_t)(*(uint8_t *)(a2 + 310) & *(uint8_t *)(v10 + *((uint8_t *)v15 + 27))) == 0) == v16 )
    {
      v15 = (int **)*v15;
      if ( !v15 )
        goto LABEL_22;
    }
    goto LABEL_20;
  }
LABEL_22:
  v18 = *(uint8_t *)(a2 + 53) & ~v3;
  *(uint8_t *)(a2 + 53) = v18;
  if ( (v18 & v7) != 0 )
  {
LABEL_20:
    *((uint16_t *)v8[18] + 54) |= 0x2000u;
    return v8;
  }
  v19 = sub_12C92C(65, 0, 5, 4u);
  *(uint16_t *)v19 = *(uint16_t *)(a2 + 32);
  *(uint8_t *)(v19 + 3) = *(uint8_t *)(a2 + 34);
  *(uint8_t *)(v19 + 2) = 0;
  sdio_buffer_prepare_n_4e8(v19);
  return v8;
}

