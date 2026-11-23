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


extern uint32_t dword_1151F4;
extern uint32_t dword_1151F8;
extern uint32_t dword_1151FC;
extern uint32_t dword_115200;
extern uint32_t dword_115204;
extern uint32_t dword_115208;
extern uint32_t dword_115210;
extern uint32_t dword_115214;
extern uint32_t dword_115218;
extern uint32_t dword_11521C;
extern uint32_t dword_115220;
extern uint32_t dword_115224;
extern uint32_t dword_115228;

// mmio_wait_flag @ 0x1150a8, size 330 bytes
int  mmio_wait_flag(int a1, int a2)
{
  int v2; // r3
  uint32_t *v3; // r4
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
  int result; // r0
  int v18; // r3
  int v19; // r2
  int v20; // r6
  int v21; // r2
  volatile unsigned int v22; // r3

  v2 = **(uint16_t **)dword_1151F4;
  if ( (v2 & 1) != 0 )
    sub_1216EC(a1, a2, v2 << 31);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_1151F8 = 1;
  }
  v3 = (uint32_t *)dword_1151FC;
  v4 = dword_115200;
  v5 = dword_115204;
  ++*(uint32_t *)dword_1151FC;
  sub_11F74C(1024, v5, v4);
  v6 = sub_11E628(0x80000000);
  v7 = sub_11D348(v6);
  v8 = (uint32_t *)dword_115208;
  *(uint32_t *)dword_115208 &= 0xFFFFFFu;
  *v8 |= 0x10u;
  v9 = (*(volatile uint32_t *)0x40501010u);
  v10 = v9 + 100;
  do
    v11 = v10 - (*(volatile uint32_t *)0x40501010u);
  while ( v11 >= 0 );
  v12 = (uint32_t *)dword_115210;
  *(uint32_t *)dword_115210 |= 0x111u;
  v13 = sub_115E98(v7);
  *(uint32_t *)dword_115208 &= ~0x10u;
  *v12 &= 0xFFFFFEEE;
  sub_1188C4(v13);
  if ( !sub_11E34C(0) )
    sub_11E628(0x2000000);
  v14 = dword_115214;
  sub_1182F4();
  if ( *(uint8_t *)v14 && !*(uint8_t *)dword_115218 && *(uint8_t *)(v14 + 6) )
  {
    v20 = *(char *)(v14 + 7) + (char)(*(uint8_t *)(v14 + 5) + (*(uint8_t *)dword_115224 & 3));
    if ( v20 >= *(char *)(v14 + 4) )
      LOBYTE(v20) = *(uint8_t *)(v14 + 4);
    sub_1029DC((char)v20);
    v21 = *(uint16_t *)(v14 + 8);
    v22 = (*(volatile uint32_t *)0x40501010u);
    *(uint8_t *)(v14 + 7) = v20;
    *(uint8_t *)(v14 + 0xB) = 1;
    sub_11AB18(v14 + 12, v22 + 60000 * v21);
    sub_11F504(dword_115228);
  }
  v16 = dword_11521C;
  *(uint8_t *)(v14 + 6) = 0;
  sub_11F74C(1024, v16, v15);
  if ( *(uint32_t *)dword_115220 )
    sub_11E5E0(0x2000);
  result = sub_11798C();
  if ( result )
    result = sub_11E5E0(0x400000);
  if ( *v3 )
  {
    v18 = *v3 - 1;
    v19 = *(uint32_t *)dword_1151F8;
    *v3 = v18;
    if ( !v18 )
    {
      if ( v19 )
        __enable_irq();
    }
  }
  return result;
}
