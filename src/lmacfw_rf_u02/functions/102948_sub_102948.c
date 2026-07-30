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

extern uint32_t off_102960;
extern uint32_t off_102964;

// sub_102948 @ 0x102948, size 24 bytes
int sub_102948()
{
  int result; // r0

  result = mmio_set_bit_120090C(*((uint8_t *)off_102960 + 36), *((uint16_t *)off_102960 + 20));
  ++*(uint8_t *)off_102964;
  return result;
}

