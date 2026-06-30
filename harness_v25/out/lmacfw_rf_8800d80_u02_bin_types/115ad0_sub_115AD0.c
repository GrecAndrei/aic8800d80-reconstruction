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

extern uint32_t dword_115B4C;
extern uint32_t dword_115B48;
extern uint32_t dword_115B44;
extern uint32_t off_115B50;
extern uint32_t off_115B54;
extern uint32_t off_115B58;
extern uint32_t off_115B5C;

// sub_115AD0 @ 0x115ad0, size 116 bytes
int  sub_115AD0(int a1)
{
  uint32_t *v1; // r5
  int v3; // r3
  int v4; // r4
  uint32_t *v5; // r2
  int *v6; // r5
  int v7; // r1
  int result; // r0
  int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v1 = (uint32_t *)dword_115B4C;
  else
    v1 = (uint32_t *)dword_115B48;
  if ( a1 != 5 )
    v1 += 7 * a1;
  sub_1160FC(a1, dword_115B44 + 8 * a1, 0);
  sub_1160FC(a1, v1 + 3, 0);
  *v1 = 0;
  v1[5] = 0;
  sub_1152D8(a1);
  v3 = *(uint32_t *)off_115B50;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_115B54 = 1;
  }
  v5 = off_115B58;
  v6 = (int *)off_115B50;
  v7 = *(uint32_t *)off_115B58;
  result = *(uint32_t *)off_115B58 + 1;
  *(uint32_t *)off_115B58 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_115B54;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(uint32_t *)off_115B5C = v4;
  return result;
}

