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

extern uint32_t dword_117AC8;
extern uint32_t off_117AA4;
extern uint32_t dword_117AA8;
extern uint32_t off_117AAC;
extern uint32_t off_117AB0;
extern uint32_t off_117AB4;
extern uint32_t dword_117AC0;
extern uint32_t off_117AC4;
extern uint32_t off_117AB8;
extern uint32_t off_117ABC;

// sub_1179A4 @ 0x1179a4, size 254 bytes
int  sub_1179A4(int a1, int a2)
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
    v4 = (char *)dword_117AC8;
  else
    v4 = (char *)off_117AA4 + 84 * a2;
  v5 = dword_117AA8;
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
  v8 = *((uint32_t *)off_117AAC + 8);
  if ( v8 )
  {
    v9 = *(uint8_t **)off_117AB0;
    *(uint32_t *)off_117AB4 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117AC0 + 1320 * *(uint8_t *)(a1 + 28) )
      *(uint32_t *)(v8 + 120) = *((uint32_t *)off_117AC4 + 4);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117AB8 = 1;
  }
  v10 = (int *)off_117ABC;
  ++*(uint32_t *)off_117ABC;
  sub_11A4D0(a1, a2);
  sub_12D470(v4 + 12);
  sub_12B098(*(uint8_t *)(a1 + 28), *(uint8_t *)(a1 + 29), 0);
  if ( (*(uint16_t *)(a1 + 30) & 1) == 0 )
    ++*((uint32_t *)off_117AA4 + 126);
  sub_1294F8(a1);
  result = sub_11708C(a1, a2, 0);
  v12 = *v10;
  *(uint16_t *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(uint32_t *)off_117AB8;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

