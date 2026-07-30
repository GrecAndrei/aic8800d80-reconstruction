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

extern uint32_t off_12D360;
extern uint32_t off_12D364;
extern uint32_t off_12D368;

// sub_12D32C @ 0x12d32c, size 52 bytes
int  sub_12D32C(int a1)
{
  uint32_t *v1; // r2
  int *v2; // r5
  int v3; // r1
  int v4; // r4
  int result; // r0
  int *v6; // r3
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12D360 = 1;
  }
  v1 = off_12D364;
  v2 = (int *)off_12D368;
  v3 = *(uint32_t *)off_12D364;
  v4 = *(uint32_t *)off_12D364 + 1;
  result = a1 | *(uint32_t *)off_12D368;
  *(uint32_t *)off_12D364 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (int *)off_12D360;
    *v1 = v3;
    v7 = *v6;
    if ( !v3 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

