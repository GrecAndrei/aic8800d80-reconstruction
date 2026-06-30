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

extern uint32_t off_11F034;
extern uint32_t off_11F030;
extern uint32_t off_11F038;

// mmio_set_clear_bits @ 0x11f004, size 44 bytes
// Doc: mmio_set_clear_bits [mmio]: Set bit 0x10000 in reg, then clear same bit in another reg
// mmio_set_clear_bits [mmio]: Set bit 0x10000 in reg, then clear same bit in another reg
int mmio_set_clear_bits()
{
  uint32_t *v0; // r2
  int result; // r0

  v0 = off_11F034;
  *(uint32_t *)off_11F030 = 0x10000;
  *v0 &= ~0x10000u;
  result = irq_nesting_or(0x80000);
  if ( *(uint8_t *)off_11F038 )
    return sub_1224F4(result);
  return result;
}

