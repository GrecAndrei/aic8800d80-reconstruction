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


extern uint32_t off_1142D4;
extern uint32_t off_1142D8;
extern uint32_t off_1142DC;
extern uint32_t off_1142E0;

// sub_11428c @ 0x11428c, size 72 bytes
int  sub_11428c(uint32_t *a1)
{
  int *v1; // r5
  uint32_t *v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_1142D4 = 1;
  }
  v1 = (int *)off_1142D8;
  v2 = off_1142DC;
  ++*(uint32_t *)off_1142D8;
  while ( !*v2 )
    ;
  result = cmd_handler_a(((uint32_t *)(uintptr_t)off_1142E0)[0] + 628, a1);
  *v2 = 1;
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(uint32_t *)off_1142D4;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}
