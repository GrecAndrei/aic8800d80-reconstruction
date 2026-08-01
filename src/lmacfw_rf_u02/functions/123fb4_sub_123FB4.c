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

extern uint32_t off_123FC4;

// set_reg_1807fc_bits24_27 @ 0x123fb4, size 16 bytes
int  set_reg_1807fc_bits24_27(int result)
{
  *(uint32_t *)off_123FC4 = *(uint32_t *)off_123FC4 & 0xF0FFFFFF | (result << 24);
  return result;
}

