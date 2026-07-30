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

extern uint32_t off_10D5D0;

// sub_10D5AC @ 0x10d5ac, size 36 bytes
int sub_10D5AC()
{
  int v0; // r3
  int result; // r0

  v0 = *((uint32_t *)off_10D5D0 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((uint32_t *)off_10D5D0 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((uint32_t *)off_10D5D0 + 2) = 0x40000;
    return irq_nesting_or_d104(0x20000000);
  }
  return result;
}

