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

extern uint32_t dword_117688;
extern uint32_t off_117664;
extern uint32_t dword_117668;
extern uint32_t off_11766C;
extern uint32_t off_117670;
extern uint32_t off_117674;
extern uint32_t dword_117680;
extern uint32_t off_117684;
extern uint32_t off_117678;
extern uint32_t off_11767C;

// sub_117564 @ 0x117564, size 254 bytes
// Doc: sub_1217564 [mac]: Dispatch routine with 5-way case switch
// sub_1217564 [mac]: Dispatch routine with 5-way case switch
int  sub_117564(int a1, int a2)
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
    v4 = (char *)dword_117688;
  else
    v4 = (char *)off_117664 + 84 * a2;
  v5 = dword_117668;
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
  v8 = *((uint32_t *)off_11766C + 8);
  if ( v8 )
  {
    v9 = *(uint8_t **)off_117670;
    *(uint32_t *)off_117674 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117680 + 1320 * *(uint8_t *)(a1 + 28) )
      *(uint32_t *)(v8 + 120) = *((uint32_t *)off_117684 + 4);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_117678 = 1;
  }
  v10 = (int *)off_11767C;
  ++*(uint32_t *)off_11767C;
  sub_11A090(a1, a2);
  list_push_tail(v4 + 12);
  sub_12AE74(*(uint8_t *)(a1 + 28), *(uint8_t *)(a1 + 29), 0);
  if ( (*(uint16_t *)(a1 + 30) & 1) == 0 )
    ++*((uint32_t *)off_117664 + 126);
  sub_1292D4(a1);
  result = sub_116C4C(a1, a2, 0);
  v12 = *v10;
  *(uint16_t *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(uint32_t *)off_117678;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

