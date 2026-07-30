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

extern uint32_t off_117A78;
extern uint32_t off_117A74;

// sub_117A58 @ 0x117a58, size 26 bytes
int sub_117A58()
{
  uint32_t *v0; // r2

  v0 = off_117A78;
  *(uint32_t *)off_117A74 = 0x10000;
  *v0 &= ~0x10000u;
  return irq_nesting_or(0x4000);
}

