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

extern uint32_t off_12F4E0;
extern uint32_t off_12F4E4;

// bad_func_0x12f4b8 @ 0x12f4b8, size 40 bytes
void bad_func_0x12f4b8()
{
  uint32_t *v0; // r3
  int v1; // r2
  int v2; // r1
  uint32_t *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F4E0 = 1;
  }
  v0 = off_12F4E4;
  v1 = *(uint32_t *)off_12F4E4;
  v2 = *(uint32_t *)off_12F4E4 + 1;
  *(uint32_t *)off_12F4E4 = v2;
  if ( v2 )
  {
    v3 = off_12F4E0;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}

