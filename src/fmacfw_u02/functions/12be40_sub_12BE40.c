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

extern uint32_t off_12BE7C;
extern uint32_t off_12BE80;
extern uint32_t off_12BE88;

// sub_12BE40 @ 0x12be40, size 60 bytes
// Doc: sub_122BE40 [util]: Utility helper, bit-shift based index calculation
// sub_122BE40 [util]: Utility helper, bit-shift based index calculation
int sub_12BE40()
{
  uint32_t *v0; // r3
  int v1; // r2
  int result; // r0
  int v3; // r4
  uint32_t *v4; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12BE7C = 1;
  }
  v0 = off_12BE80;
  v1 = *(uint32_t *)off_12BE80;
  result = *(uint32_t *)off_12BE88;
  v3 = *(uint32_t *)off_12BE80 + 1;
  *(uint32_t *)off_12BE80 = v3;
  if ( v3 )
  {
    v4 = off_12BE7C;
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v4 )
        __enable_irq();
    }
  }
  return result;
}

