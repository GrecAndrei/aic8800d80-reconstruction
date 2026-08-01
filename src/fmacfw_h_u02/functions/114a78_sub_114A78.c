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

extern uint32_t off_114AB0;
extern uint32_t off_114AB4;

// undefined_instruction_handler @ 0x114a78, size 54 bytes
int undefined_instruction_handler()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_114AB0 = 1;
  }
  v0 = (int *)off_114AB4;
  ++*(uint32_t *)off_114AB4;
  result = MEMORY[0x1C8]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(uint32_t *)off_114AB0;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

