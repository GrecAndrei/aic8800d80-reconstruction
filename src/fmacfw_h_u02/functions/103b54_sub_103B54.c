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

extern uint32_t off_103B88;

// rf_clear_ana_bits @ 0x103b54, size 50 bytes
int rf_clear_ana_bits()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_103B88;
  *(uint32_t *)off_103B88 &= ~0x400000u;
  *v0 &= ~0x200000u;
  mmio_read32(2);
  *v0 |= 0x200000u;
  result = mmio_read32(2);
  *v0 |= 0x400000u;
  return result;
}

