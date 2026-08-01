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

extern uint32_t off_124090;

// set_reg_180800_bits7_8 @ 0x12407c, size 18 bytes
int  set_reg_180800_bits7_8(int a1)
{
  *(uint32_t *)off_124090 = *(uint32_t *)off_124090 & 0xFFFFFE7F | (a1 << 7);
  return 0;
}

