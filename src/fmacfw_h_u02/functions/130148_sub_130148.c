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

extern uint32_t off_13017C;
extern uint32_t off_130180;

// mmio_register_access @ 0x130148, size 50 bytes
void mmio_register_access()
{
  uint32_t *v0; // r4
  unsigned int v1; // r0

  v0 = off_13017C;
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      v1 = radio_rx_read_byte();
      if ( lock_with_timeout(v1) > 0 )
      {
        if ( *(uint8_t *)off_130180 )
          rf_calibration_proc();
        return;
      }
    }
  }
}

