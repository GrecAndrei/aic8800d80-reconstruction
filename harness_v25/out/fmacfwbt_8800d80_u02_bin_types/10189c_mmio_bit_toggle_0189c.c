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

extern uint32_t off_1018B0;

// mmio_bit_toggle_0189c @ 0x10189c, size 20 bytes
// Doc: mmio_bit_toggle_0189c [mmio]: Toggle a single bit in MMIO control register
// mmio_bit_toggle_0189c [mmio]: Toggle a single bit in MMIO control register
unsigned int  mmio_bit_toggle_0189c(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(uint32_t *)off_1018B0 & 0xFFFFFFF7;
  *(uint32_t *)off_1018B0 = result;
  return result;
}

