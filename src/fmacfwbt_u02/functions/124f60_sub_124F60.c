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


extern uint32_t off_125034;
extern uint32_t off_125038;
extern uint32_t off_12503C;
extern uint32_t off_125040;
extern uint32_t off_125044;
extern uint32_t off_12504C;
extern uint32_t off_125054;

// sub_124F60 @ 0x124f60, size 212 bytes
int  sub_124F60(uint32_t *a1, int a2)
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
    *(uint32_t *)off_125034 = 1;
  }
  v4 = (int *)off_125038;
  v5 = off_12503C;
  ++*(uint32_t *)off_125038;
  v6 = *((uint32_t *)v5 + 4);
  if ( a2 - v6 < 0 )
  {
    sub_12ECB0("timer past: cb=%x, time=%x, curr=%x\r\n", a1[1], a2, v6);
    if ( **(uint16_t **)off_12504C < 0 )
      sub_12F694(off_125054, (int)aMmTimerSet, 131);
  }
  v7 = (uint32_t *)off_125040;
  if ( a1 == *(uint32_t **)off_125040 )
  {
    sub_12D4F8(off_125040);
    v13 = off_125044;
    a1[3] = a2;
    result = sub_12D5A8((int)v7, a1, (int ( *)(uint32_t *, uint32_t *))v13);
    v10 = (uint32_t *)*v7;
    if ( !*v7 )
    {
      *((uint32_t *)off_12503C + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  sub_12D510(off_125040, a1);
  v8 = off_125044;
  a1[3] = a2;
  result = sub_12D5A8((int)v7, a1, (int ( *)(uint32_t *, uint32_t *))v8);
  v10 = (uint32_t *)*v7;
  if ( a1 == (uint32_t *)*v7 )
  {
LABEL_14:
    v14 = off_12503C;
    v15 = v10[3];
    result = 0x40000;
    *((uint32_t *)off_12503C + 2) = 0x40000;
    *((uint32_t *)v14 + 12) = v15;
    *((uint32_t *)v14 + 2) = 4;
  }
LABEL_6:
  if ( *v4 && (v11 = *v4 - 1, v12 = *(uint32_t *)off_125034, (*v4 = v11) == 0) && v12 )
  {
    __enable_irq();
    if ( a2 - *((uint32_t *)off_12503C + 4) < 0 )
      return sub_12D32C(0x20000000);
  }
  else if ( a2 - *((uint32_t *)off_12503C + 4) < 0 )
  {
    return sub_12D32C(0x20000000);
  }
  return result;
}
