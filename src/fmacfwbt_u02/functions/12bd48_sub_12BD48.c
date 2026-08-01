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

extern uint32_t off_12BD68;
extern uint32_t off_12BD6C;
extern uint32_t off_12BD70;

// mmio_clear_high_bits @ 0x12bd48, size 32 bytes
// Doc: sub_122BD48 [mmio]: Clear high bit in MMIO registers at 0x403280xx
// sub_122BD48 [mmio]: Clear high bit in MMIO registers at 0x403280xx
void *mmio_clear_high_bits()
{
  void *result; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  result = off_12BD68;
  v1 = off_12BD6C;
  v2 = off_12BD70;
  *(uint32_t *)off_12BD68 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

