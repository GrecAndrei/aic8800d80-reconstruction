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
extern uint32_t dword_115940;
extern uint32_t dword_115944;
extern uint32_t dword_115948;
extern uint32_t dword_115950;
extern uint32_t dword_115954;
extern uint32_t dword_115958;
extern uint32_t dword_11595C;
extern uint32_t dword_115960;
extern uint32_t dword_115964;
extern uint32_t dword_115968;
extern uint32_t dword_11596C;
extern uint32_t dword_115970;
extern uint32_t dword_115974;
extern uint32_t dword_115978;

// check_event_flag @ 0x1157d8, size 346 bytes
uint32_t * check_event_flag(int a1, int a2)
{
  int v2; // r3
  int *v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r0
  uint32_t *v8; // r3
  volatile unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r3
  uint32_t *v12; // r5
  int v13; // r0
  unsigned int v14; // r5
  int v15; // r2
  unsigned int v16; // r1
  int v17; // r0
  uint32_t *v18; // r1
  uint32_t *v19; // r0
  uint64_t v20; // kr00_8
  uint32_t *result; // r0
  int v22; // r1
  int v23; // r1
  int v24; // r3
  int v25; // r6
  int v26; // r2
  volatile unsigned int v27; // r3

  v2 = **(uint16_t **)dword_115934;
  if ( (v2 & 1) != 0 )
    sub_12F194(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_115938 = 1;
  }
  v3 = (int *)dword_11593C;
  v4 = dword_115940;
  v5 = dword_115944;
  ++*(uint32_t *)dword_11593C;
  sub_12ECD0(1024, v5, v4);
  v6 = sub_12D14C(0x80000000);
  v7 = sub_12BB4C(v6);
  v8 = (uint32_t *)dword_115948;
  *(uint32_t *)dword_115948 &= 0xFFFFFFu;
  *v8 |= 0x10u;
  v9 = (*(volatile uint32_t *)0x40501010u);
  v10 = v9 + 100;
  do
    v11 = v10 - (*(volatile uint32_t *)0x40501010u);
  while ( v11 >= 0 );
  v12 = (uint32_t *)dword_115950;
  *(uint32_t *)dword_115950 |= 0x111u;
  v13 = sub_117BBC(v7);
  *(uint32_t *)dword_115948 &= ~0x10u;
  *v12 &= 0xFFFFFEEE;
  sub_1210B4(v13);
  if ( !sub_12CE88(0) )
    sub_12D14C(0x2000000);
  v14 = dword_115954;
  sub_11F794();
  if ( *(uint8_t *)v14 && !*(uint8_t *)dword_115958 && *(uint8_t *)(v14 + 6) )
  {
    v25 = *(char *)(v14 + 7) + (char)(*(uint8_t *)(v14 + 5) + (*(uint8_t *)dword_115974 & 3));
    if ( v25 >= *(char *)(v14 + 4) )
      LOBYTE(v25) = *(uint8_t *)(v14 + 4);
    sub_102B80((char)v25);
    v26 = *(uint16_t *)(v14 + 8);
    v27 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v14 + 7) = v25;
    *(uint8_t *)(v14 + 0xB) = 1;
    sub_124D3C(v14 + 12, v27 + 60000 * v26);
    sub_12EA88(dword_115978);
  }
  v16 = dword_11595C;
  *(uint8_t *)(v14 + 6) = 0;
  v17 = sub_12ECD0(1024, v16, v15);
  if ( sub_11EAF8(v17) )
    sub_12D104(0x80000);
  v18 = (uint32_t *)dword_115968;
  v19 = (uint32_t *)dword_11596C;
  v20 = *(uint64_t *)(*(uint32_t *)dword_115960 + 8);
  *(uint32_t *)dword_115964 = v20;
  *v18 = HIDWORD(v20) + v20 - 4;
  *v19 = v20;
  v18[2] = v20;
  result = (uint32_t *)dword_115970;
  v22 = *v3;
  *(uint32_t *)(dword_115970 + 0x14) = v20;
  result[3] = v20;
  result[4] = HIDWORD(v20) + v20;
  if ( v22 )
  {
    v23 = v22 - 1;
    v24 = *(uint32_t *)dword_115938;
    *v3 = v23;
    if ( !v23 )
    {
      if ( v24 )
        __enable_irq();
    }
  }
  return result;
}
