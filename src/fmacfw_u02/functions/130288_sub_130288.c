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

extern uint32_t off_1302BC;
extern uint32_t off_1302C0;

// read_mmio_reg @ 0x130288, size 50 bytes
void read_mmio_reg()
{
  uint32_t *v0; // r4
  unsigned int byte_uart; // r0

  v0 = off_1302BC;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      byte_uart = gpio_read();
      if ( find_by_index(byte_uart) > 0 )
      {
        if ( *(uint8_t *)off_1302C0 )
          parse_large_ioctl();
        return;
      }
    }
  }
}

