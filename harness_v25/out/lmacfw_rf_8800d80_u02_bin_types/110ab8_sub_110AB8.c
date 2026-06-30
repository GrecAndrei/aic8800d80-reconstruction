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

extern uint32_t off_110B28;
extern uint32_t off_110B2C;
extern uint32_t off_110B30;
extern uint32_t off_110B34;
extern uint32_t off_110B38;
extern uint32_t off_110B40;
extern uint32_t off_110B3C;

// sub_110AB8 @ 0x110ab8, size 112 bytes
int  sub_110AB8(int a1, int a2, int a3)
{
  uint32_t *v3; // r5
  uint32_t *v4; // r4
  int v5; // r6
  int v6; // r7
  uint32_t *v7; // r3
  uint32_t *v8; // r12
  int result; // r0
  int *v10; // r3
  int v11; // r3
  uint32_t *v12; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_110B28 = 1;
  }
  v3 = off_110B2C;
  v4 = off_110B30;
  v5 = *(uint32_t *)off_110B2C;
  v6 = *(uint32_t *)off_110B2C + 1;
  *(uint32_t *)off_110B2C = v6;
  *v4 = 256;
  while ( (*v4 & 0x200) != 0 )
    ;
  if ( *(uint32_t *)off_110B34 )
  {
    v7 = off_110B38;
    v8 = off_110B40;
    *(uint32_t *)(*((uint32_t *)off_110B38 + 769) + 4) = a1;
    *v8 += a2;
  }
  else
  {
    v12 = off_110B40;
    *(uint32_t *)off_110B34 = a1;
    v7 = off_110B38;
    *v12 += a2;
  }
  result = 256;
  *(uint32_t *)off_110B3C = 256;
  v7[769] = a3;
  if ( v6 )
  {
    v10 = (int *)off_110B28;
    *v3 = v5;
    v11 = *v10;
    if ( !v5 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

