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

extern uint32_t dword_125740;
extern uint32_t dword_12575C;
extern uint32_t dword_125738;
extern uint32_t dword_12573C;
extern uint32_t dword_125744;
extern uint32_t dword_125748;
extern uint32_t dword_125760;
extern uint32_t dword_12574C;
extern uint32_t dword_125750;
extern uint32_t dword_125754;
extern uint32_t off_125758;

// sub_125638 @ 0x125638, size 254 bytes
int * sub_125638(int a1)
{
  int v1; // r7
  int v2; // r9
  int v4; // r3
  int v5; // r1
  int v6; // r12
  int v7; // r0
  uint8_t *v8; // r2
  int v9; // r8
  int *v10; // r0
  uint32_t *v11; // r6
  int v12; // r3
  int *result; // r0
  int *v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r1
  uint32_t *v18; // r2
  uint32_t *v19; // r3
  void *v20; // r1

  v1 = dword_125740;
  v2 = dword_12575C;
  sub_11892C(
    a1 + 116,
    dword_125738 + 620 * *(uint8_t *)(a1 + 107),
    (uint32_t *)(dword_12573C + 80 * *(uint8_t *)(a1 + 107)),
    (int *)(dword_125744 + (*(uint8_t *)(a1 + 107) << 6)));
  v4 = *(uint8_t *)(a1 + 107);
  v5 = dword_125748;
  v6 = dword_125760;
  v7 = dword_12574C;
  *(uint16_t *)(a1 + 218) = 6;
  v8 = (uint8_t *)(v5 + 8 * v4);
  *(uint16_t *)(a1 + 228) = 255;
  *(uint8_t *)(a1 + 227) = 0;
  *(uint16_t *)(a1 + 220) = 0;
  *(uint8_t *)(a1 + 230) = 0;
  *v8 = 5;
  v8[1] = 4;
  v8[2] = *(uint8_t *)(a1 + 227);
  v8[4] = 0;
  v8[5] = 0;
  v8[3] = 1;
  v9 = 5 * v4;
  v10 = (int *)(v7 + 252 * v4);
  v11 = (uint32_t *)(v6 + 40 * v4);
  v12 = v1 + 20 * v4;
  v11[8] = (char *)v10 + *(uint8_t *)(a1 + 229);
  v11[3] = v8 + 5;
  v11[4] = 0;
  *(uint32_t *)(v6 + 8 * v9) = v2;
  v11[2] = v8;
  v11[1] = v12;
  v11[6] = v12;
  v11[5] = v2;
  result = sub_100200(v10, 0, 0xFCu);
  v14 = (int *)(v1 + 4 * v9);
  *v14 = v2;
  v14[1] = 0;
  v14[4] = 0;
  if ( *(uint8_t *)(a1 + 1224) )
  {
    v15 = *(uint8_t *)(a1 + 107);
    result = (int *)dword_125750;
    v16 = 19 * v15;
    v15 *= 5;
    v17 = dword_125754 + 2 * v16;
    v18 = (uint32_t *)(dword_125750 + 4 * v15);
    v18[1] = 0;
    v18[2] = v17;
    result[v15] = v2;
    v18[4] = 0;
  }
  v19 = *(uint32_t **)(a1 + 192);
  v20 = off_125758;
  v19[11] = 0;
  v19[17] = 0;
  v19[6] = 0;
  *(uint32_t *)(a1 + 204) = v20;
  *(uint32_t *)(a1 + 208) = a1;
  return result;
}

