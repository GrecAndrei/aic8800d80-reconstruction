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

extern uint32_t off_123F88;

// set_reg_1807fc_bit20 @ 0x123f78, size 16 bytes
int  set_reg_1807fc_bit20(int result)
{
  *(uint32_t *)off_123F88 = *(uint32_t *)off_123F88 & 0xFFEFFFFF | (result << 20);
  return result;
}

