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

extern uint32_t dword_1173F0;
extern uint32_t dword_1173D8;
extern uint32_t dword_1173DC;
extern uint32_t off_1173E0;
extern uint32_t off_1173E4;
extern uint32_t off_1173E8;
extern uint32_t off_1173EC;

// sub_11735C @ 0x11735c, size 124 bytes
int  sub_11735C(int a1)
{
  uint32_t *v2; // r5
  int v3; // r3
  int v4; // r4
  uint32_t *v5; // r2
  int *v6; // r5
  int v7; // r1
  int result; // r0
  int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v2 = (uint32_t *)dword_1173F0;
  else
    v2 = (uint32_t *)(dword_1173D8 + 84 * a1);
  sub_118800(a1, dword_1173DC + 8 * a1, 0);
  sub_118800(a1, v2 + 3, 0);
  *v2 = 0;
  v2[5] = 0;
  sub_115F10(a1);
  v3 = *(uint32_t *)off_1173E0;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1173E4 = 1;
  }
  v5 = off_1173E8;
  v6 = (int *)off_1173E0;
  v7 = *(uint32_t *)off_1173E8;
  result = *(uint32_t *)off_1173E8 + 1;
  *(uint32_t *)off_1173E8 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_1173E4;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_1173EC = v4;
  return result;
}

