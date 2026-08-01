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

extern uint32_t off_12BD30;
extern uint32_t off_12BD34;
extern uint32_t off_12BD38;
extern uint32_t off_12BD3C;

// util_abs @ 0x12bcc0, size 110 bytes
int  util_abs(int a1)
{
  unsigned int v1; // r2
  uint32_t *v2; // r5
  int v3; // r6
  int v4; // r3
  int v5; // r7
  unsigned int v6; // r1
  int v7; // r3
  int *v8; // r1
  int *v9; // r4
  int v10; // r0
  int result; // r0
  int *v12; // r3
  int v13; // r3

  v1 = abs32(a1);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12BD30 = 1;
  }
  v2 = off_12BD34;
  v3 = *(uint32_t *)off_12BD34;
  v4 = *(uint32_t *)off_12BD38;
  v5 = *(uint32_t *)off_12BD34 + 1;
  v6 = *(uint32_t *)off_12BD3C;
  *(uint32_t *)off_12BD34 = v5;
  v7 = v4 | 0x1000000;
  if ( a1 <= 0 )
  {
    if ( !a1 || ~v6 >= v1 + 32 )
      goto LABEL_5;
LABEL_13:
    result = -1;
    goto LABEL_6;
  }
  if ( v1 > v6 )
    goto LABEL_13;
LABEL_5:
  v8 = (int *)off_12BD3C;
  v9 = (int *)off_12BD38;
  v10 = *(uint32_t *)off_12BD3C - a1;
  *(uint32_t *)off_12BD3C = v10;
  *v9 = v7;
  *v8 = v10;
  *v9 = v7;
  *v8 = v10;
  result = 0;
  *v9 = v7;
LABEL_6:
  if ( v5 )
  {
    v12 = (int *)off_12BD30;
    *v2 = v3;
    v13 = *v12;
    if ( !v3 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

