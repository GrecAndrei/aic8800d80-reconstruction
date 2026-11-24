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


extern uint32_t off_11ABEC;
extern uint32_t off_11ABF0;
extern uint32_t off_11ABF4;
extern uint32_t off_11ABF8;
extern uint32_t off_11ABFC;
extern uint32_t off_11AC04;
extern uint32_t off_11AC0C;

// sub_11AB18 @ 0x11ab18, size 212 bytes
int  sub_11AB18(uint32_t *a1, int a2)
{
  int *v4; // r7
  volatile unsigned int *v5; // r2
  int v6; // r3
  uint32_t *v7; // r6
  void *v8; // r2
  int result; // r0
  uint32_t *v10; // r3
  int v11; // r3
  int v12; // r2
  void *v13; // r2
  volatile unsigned int *v14; // r2
  int v15; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11ABEC = 1;
  }
  v4 = (int *)off_11ABF0;
  v5 = off_11ABF4;
  ++*(uint32_t *)off_11ABF0;
  v6 = *((uint32_t *)v5 + 4);
  if ( a2 - v6 < 0 )
  {
    sub_11F504("timer past: cb=%x, time=%x, curr=%x\r\n", a1[1], a2, v6);
    if ( **(uint16_t **)off_11AC04 < 0 )
      sub_1219C4(off_11AC0C, (int)aMmTimerSet, 131);
  }
  v7 = (uint32_t *)off_11ABF8;
  if ( a1 == *(uint32_t **)off_11ABF8 )
  {
    sub_11E7AC(off_11ABF8);
    v13 = off_11ABFC;
    a1[3] = a2;
    result = sub_11E840((int)v7, a1, (int ( *)(uint32_t *, uint32_t *))v13);
    v10 = (uint32_t *)*v7;
    if ( !*v7 )
    {
      *((uint32_t *)off_11ABF4 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  sub_11E7C4(off_11ABF8, a1);
  v8 = off_11ABFC;
  a1[3] = a2;
  result = sub_11E840((int)v7, a1, (int ( *)(uint32_t *, uint32_t *))v8);
  v10 = (uint32_t *)*v7;
  if ( a1 == (uint32_t *)*v7 )
  {
LABEL_14:
    v14 = off_11ABF4;
    v15 = v10[3];
    result = 0x40000;
    *((uint32_t *)off_11ABF4 + 2) = 0x40000;
    *((uint32_t *)v14 + 12) = v15;
    *((uint32_t *)v14 + 2) = 4;
  }
LABEL_6:
  if ( *v4 && (v11 = *v4 - 1, v12 = *(uint32_t *)off_11ABEC, (*v4 = v11) == 0) && v12 )
  {
    __enable_irq();
    if ( a2 - *((uint32_t *)off_11ABF4 + 4) < 0 )
      return sub_11E5E0(0x20000000);
  }
  else if ( a2 - *((uint32_t *)off_11ABF4 + 4) < 0 )
  {
    return sub_11E5E0(0x20000000);
  }
  return result;
}
