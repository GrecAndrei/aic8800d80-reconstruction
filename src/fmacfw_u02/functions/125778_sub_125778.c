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

extern uint32_t dword_125880;
extern uint32_t dword_12589C;
extern uint32_t dword_125878;
extern uint32_t dword_12587C;
extern uint32_t dword_125884;
extern uint32_t dword_125888;
extern uint32_t dword_1258A0;
extern uint32_t dword_12588C;
extern uint32_t dword_125890;
extern uint32_t dword_125894;
extern uint32_t dword_125898;

// stack_canary_check @ 0x125778, size 254 bytes
int * stack_canary_check(int a1)
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
  int v20; // r1

  v1 = dword_125880;
  v2 = dword_12589C;
  ll_event_init(
    a1 + 116,
    dword_125878 + 620 * *(uint8_t *)(a1 + 107),
    (uint32_t *)(dword_12587C + 80 * *(uint8_t *)(a1 + 107)),
    (int *)(dword_125884 + (*(uint8_t *)(a1 + 107) << 6)));
  v4 = *(uint8_t *)(a1 + 107);
  v5 = dword_125888;
  v6 = dword_1258A0;
  v7 = dword_12588C;
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
  result = memset(v10, 0, 0xFCu);
  v14 = (int *)(v1 + 4 * v9);
  *v14 = v2;
  v14[1] = 0;
  v14[4] = 0;
  if ( *(uint8_t *)(a1 + 1224) )
  {
    v15 = *(uint8_t *)(a1 + 107);
    result = (int *)dword_125890;
    v16 = 19 * v15;
    v15 *= 5;
    v17 = dword_125894 + 2 * v16;
    v18 = (uint32_t *)(dword_125890 + 4 * v15);
    v18[1] = 0;
    v18[2] = v17;
    result[v15] = v2;
    v18[4] = 0;
  }
  v19 = *(uint32_t **)(a1 + 192);
  v20 = dword_125898;
  v19[11] = 0;
  v19[17] = 0;
  v19[6] = 0;
  *(uint32_t *)(a1 + 204) = v20;
  *(uint32_t *)(a1 + 208) = a1;
  return result;
}

