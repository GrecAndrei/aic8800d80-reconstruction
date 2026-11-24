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


extern uint32_t dword_115934;
extern uint32_t dword_115938;
extern uint32_t dword_11593C;
extern uint32_t dword_115948;
extern uint32_t dword_115950;
extern uint32_t dword_115954;
extern uint32_t dword_115958;
extern uint32_t dword_115960;
extern uint32_t dword_115964;
extern uint32_t dword_115968;
extern uint32_t dword_11596C;
extern uint32_t dword_115970;
extern uint32_t dword_115974;

// sub_1157D8 @ 0x1157d8, size 346 bytes
uint32_t * sub_1157D8(int a1, int a2)
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

  if ( (**(uint16_t **)dword_115934 & 1) != 0 )
    sub_12F194();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_115938 = 1;
  }
  v2 = (int *)dword_11593C;
  ++*(uint32_t *)dword_11593C;
  sub_12ECD0(1024, "%s\r\n", aRwnxlResetEvt);
  sub_12D14C(0x80000000);
  sub_12BB4C();
  v3 = (uint32_t *)dword_115948;
  *(uint32_t *)dword_115948 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (uint32_t *)dword_115950;
  *(uint32_t *)dword_115950 |= 0x111u;
  sub_117BBC();
  *(uint32_t *)dword_115948 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  sub_1210B4();
  if ( !sub_12CE88(0) )
    sub_12D14C(0x2000000);
  v8 = dword_115954;
  sub_11F794();
  if ( *(uint8_t *)v8 && !*(uint8_t *)dword_115958 && *(uint8_t *)(v8 + 6) )
  {
    v16 = (char)(*(uint8_t *)(v8 + 5) + (*(uint8_t *)dword_115974 & 3));
    v17 = *(char *)(v8 + 7) + v16;
    if ( v17 >= *(char *)(v8 + 4) )
      LOBYTE(v17) = *(uint8_t *)(v8 + 4);
    sub_102B80(v17);
    v18 = *(uint16_t *)(v8 + 8);
    v19 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v8 + 7) = v17;
    *(uint8_t *)(v8 + 0xB) = 1;
    sub_124D3C((uint32_t *)(v8 + 12), v19 + 60000 * v18);
    sub_12EA88("update %d, %d\r\n", (char)v17, v16);
  }
  *(uint8_t *)(v8 + 6) = 0;
  sub_12ECD0(1024, aResetDone);
  if ( sub_11EAF8() )
    sub_12D104(0x80000);
  v9 = (uint32_t *)dword_115968;
  v10 = (uint32_t *)dword_11596C;
  v11 = *(uint64_t *)(*(uint32_t *)dword_115960 + 8);
  *(uint32_t *)dword_115964 = v11;
  *v9 = HIDWORD(v11) + v11 - 4;
  *v10 = v11;
  v9[2] = v11;
  result = (uint32_t *)dword_115970;
  v13 = *v2;
  *(uint32_t *)(dword_115970 + 0x14) = v11;
  result[3] = v11;
  result[4] = HIDWORD(v11) + v11;
  if ( v13 )
  {
    v14 = v13 - 1;
    v15 = *(uint32_t *)dword_115938;
    *v2 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return result;
}
