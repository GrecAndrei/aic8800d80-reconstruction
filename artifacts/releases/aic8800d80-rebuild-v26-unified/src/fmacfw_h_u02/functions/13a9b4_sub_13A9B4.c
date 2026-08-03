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

extern uint32_t dword_13AA20;
extern uint32_t dword_13AA24;
extern uint32_t off_13AA28;
extern uint32_t off_13AA2C;

// sub_13A9B4 @ 0x13a9b4, size 106 bytes
int  sub_13A9B4(int a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r1
  int *v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2

  sub_12EB90(
    32,
    dword_13AA20,
    *(uint16_t *)(a1 + 32),
    *(uint16_t *)(a1 + 30),
    *(uint8_t *)(a1 + 27));
  v6 = *(uint16_t *)(a1 + 30);
  v7 = v6 << 31;
  if ( (v6 & 1) != 0 || (sub_11754C(), (*(uint16_t *)(a1 + 30) & 1) != 0) )
    sub_12E948(dword_13AA24, v7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_13AA28 = 1;
  }
  v8 = (int *)off_13AA2C;
  ++*(uint32_t *)off_13AA2C;
  result = sub_117DD8(a1, a3, a2);
  if ( *v8 )
  {
    v10 = *v8 - 1;
    v11 = *(uint32_t *)off_13AA28;
    *v8 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

