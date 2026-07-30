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

extern uint32_t dword_117548;
extern uint32_t off_117524;
extern uint32_t dword_117528;
extern uint32_t off_11752C;
extern uint32_t off_117530;
extern uint32_t off_117534;
extern uint32_t dword_117540;
extern uint32_t off_117544;
extern uint32_t off_117538;
extern uint32_t off_11753C;

// sub_117424 @ 0x117424, size 254 bytes
int  sub_117424(int a1, int a2)
{
  char *v4; // r7
  int v5; // r0
  int16_t v6; // r1
  uint32_t *v7; // r3
  int v8; // r3
  uint8_t *v9; // r2
  int *v10; // r6
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r2

  if ( a2 == 5 )
    v4 = (char *)dword_117548;
  else
    v4 = (char *)off_117524 + 84 * a2;
  v5 = dword_117528;
  v6 = *(uint16_t *)(a1 + 30);
  v7 = *(uint32_t **)(a1 + 76);
  v7[9] = *(uint8_t *)(a1 + 51) + *(uint8_t *)(a1 + 53) + *(uint16_t *)(a1 + 4) + 4;
  v7[8] = 0;
  v7[13] = 0;
  v7[14] = 0;
  v7[4] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[3] = v5;
  v7[15] = 0;
  v7[12] = 0;
  v7[17] = 0;
  v7[10] = 0;
  if ( (v6 & 1) == 0 )
    v7[18] = 0;
  v8 = *((uint32_t *)off_11752C + 8);
  if ( v8 )
  {
    v9 = *(uint8_t **)off_117530;
    *(uint32_t *)off_117534 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117540 + 1320 * *(uint8_t *)(a1 + 28) )
      *(uint32_t *)(v8 + 120) = *((uint32_t *)off_117544 + 4);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117538 = 1;
  }
  v10 = (int *)off_11753C;
  ++*(uint32_t *)off_11753C;
  sub_119F50(a1, a2);
  sub_12D108(v4 + 12);
  sub_12AD34(*(uint8_t *)(a1 + 28), *(uint8_t *)(a1 + 29), 0);
  if ( (*(uint16_t *)(a1 + 30) & 1) == 0 )
    ++*((uint32_t *)off_117524 + 126);
  sub_129194(a1);
  result = sub_116B0C(a1, a2, 0);
  v12 = *v10;
  *(uint16_t *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(uint32_t *)off_117538;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

