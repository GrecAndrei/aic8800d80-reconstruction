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

extern uint32_t off_1018A0;
extern uint32_t off_1018A4;

// mmio_wait_bit @ 0x101888, size 24 bytes
int  mmio_wait_bit(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_1018A0 & 8) != 0 )
  {
    result = read_hw_clock(result, a2, a3, *(uint32_t *)off_1018A0 << 28);
    *(uint32_t *)off_1018A4 = 8;
  }
  return result;
}

