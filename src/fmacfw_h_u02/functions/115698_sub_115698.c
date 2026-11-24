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


extern uint32_t dword_1157F4;
extern uint32_t dword_1157F8;
extern uint32_t dword_1157FC;
extern uint32_t dword_115808;
extern uint32_t dword_115810;
extern uint32_t dword_115814;
extern uint32_t dword_115818;
extern uint32_t dword_115820;
extern uint32_t dword_115824;
extern uint32_t dword_115828;
extern uint32_t dword_11582C;
extern uint32_t dword_115830;
extern uint32_t dword_115834;

// sub_115698 @ 0x115698, size 346 bytes
uint32_t * sub_115698(int a1, int a2)
{
  int *v2; // r4
  uint32_t *v3; // r3
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3
  uint32_t *v7; // r5
  unsigned int v8; // r5
  uint32_t *v9; // r1
  uint32_t *v10; // r0
  uint64_t v11; // kr00_8
  uint32_t *result; // r0
  int v13; // r1
  int v14; // r1
  int v15; // r3
  int v16; // r7
  int v17; // r6
  int v18; // r2
  volatile unsigned int v19; // r3

  if ( (**(uint16_t **)dword_1157F4 & 1) != 0 )
    sub_12F054();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_1157F8 = 1;
  }
  v2 = (int *)dword_1157FC;
  ++*(uint32_t *)dword_1157FC;
  sub_12EB90(1024, "%s\r\n", aRwnxlResetEvt);
  sub_12D00C(0x80000000);
  sub_12BA0C();
  v3 = (uint32_t *)dword_115808;
  *(uint32_t *)dword_115808 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (uint32_t *)dword_115810;
  *(uint32_t *)dword_115810 |= 0x111u;
  sub_117A7C();
  *(uint32_t *)dword_115808 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  sub_120F74();
  if ( !sub_12CD48(0) )
    sub_12D00C(0x2000000);
  v8 = dword_115814;
  sub_11F654();
  if ( *(uint8_t *)v8 && !*(uint8_t *)dword_115818 && *(uint8_t *)(v8 + 6) )
  {
    v16 = (char)(*(uint8_t *)(v8 + 5) + (*(uint8_t *)dword_115834 & 3));
    v17 = *(char *)(v8 + 7) + v16;
    if ( v17 >= *(char *)(v8 + 4) )
      LOBYTE(v17) = *(uint8_t *)(v8 + 4);
    sub_102AD0(v17);
    v18 = *(uint16_t *)(v8 + 8);
    v19 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v8 + 7) = v17;
    *(uint8_t *)(v8 + 0xB) = 1;
    sub_124BFC((uint32_t *)(v8 + 12), v19 + 60000 * v18);
    sub_12E948("update %d, %d\r\n", (char)v17, v16);
  }
  *(uint8_t *)(v8 + 6) = 0;
  sub_12EB90(1024, aResetDone);
  if ( sub_11E9B8() )
    sub_12CFC4(0x80000);
  v9 = (uint32_t *)dword_115828;
  v10 = (uint32_t *)dword_11582C;
  v11 = *(uint64_t *)(*(uint32_t *)dword_115820 + 8);
  *(uint32_t *)dword_115824 = v11;
  *v9 = HIDWORD(v11) + v11 - 4;
  *v10 = v11;
  v9[2] = v11;
  result = (uint32_t *)dword_115830;
  v13 = *v2;
  *(uint32_t *)(dword_115830 + 0x14) = v11;
  result[3] = v11;
  result[4] = HIDWORD(v11) + v11;
  if ( v13 )
  {
    v14 = v13 - 1;
    v15 = *(uint32_t *)dword_1157F8;
    *v2 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return result;
}
