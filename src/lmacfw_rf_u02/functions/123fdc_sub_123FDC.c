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

extern uint32_t off_123FEC;

// set_reg_158a08_bits20_25 @ 0x123fdc, size 16 bytes
int  set_reg_158a08_bits20_25(int result)
{
  *(uint32_t *)off_123FEC = *(uint32_t *)off_123FEC & 0xFC0FFFFF | (result << 20);
  return result;
}

