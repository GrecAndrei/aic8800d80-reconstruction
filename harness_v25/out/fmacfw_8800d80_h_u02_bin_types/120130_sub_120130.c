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

extern uint32_t off_1201C0;
extern uint32_t off_1201C4;
extern uint32_t off_1201C8;
extern uint32_t dword_1201CC;
extern uint32_t off_1201D0;

// sub_120130 @ 0x120130, size 144 bytes
int  sub_120130(int result, unsigned int a2)
{
  uint32_t *v2; // r5
  uint8_t *v3; // r3
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r7
  unsigned int v7; // r4
  int *i; // r3
  unsigned int v9; // r2
  int *v10; // r3
  int v11; // r3

  *(uint16_t *)(result + 222) = a2;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1201C0 = 1;
  }
  v2 = off_1201C4;
  v3 = off_1201C8;
  v4 = *(uint32_t *)off_1201C4;
  v5 = *((uint8_t *)off_1201C8 + 18);
  v6 = *(uint32_t *)off_1201C4 + 1;
  *(uint32_t *)off_1201C4 = v6;
  if ( v5 <= 1 )
  {
    v3[20] = *(uint8_t *)(result + 107);
    v7 = a2;
    *(uint16_t *)(result + 224) = 257;
  }
  else
  {
    v7 = *(uint16_t *)(dword_1201CC + 1320 * (uint8_t)v3[20] + 222);
    if ( a2 < v7 )
    {
      v3[20] = *(uint8_t *)(result + 107);
      v7 = a2;
    }
    for ( i = *((int **)v3 + 2); i; i = (int *)*i )
    {
      v9 = *((uint16_t *)i + 111);
      *((uint8_t *)i + 225) = 1;
      *((uint8_t *)i + 224) = v9 / v7;
    }
  }
  *(uint32_t *)off_1201D0 = (HIWORD(*(uint32_t *)off_1201D0) << 16) | v7;
  if ( v6 )
  {
    v10 = (int *)off_1201C0;
    *v2 = v4;
    v11 = *v10;
    if ( !v4 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

