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

extern uint32_t dword_126FD0;
extern uint32_t off_126FD4;

// rf_set_frequency @ 0x126f90, size 62 bytes
unsigned int rf_set_frequency()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(wait_sdio_core_ready());
  dispatch_event_handler(dword_126FD0, v0);
  v1 = (char)v0 - *((char *)off_126FD4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_126FD4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((uint8_t *)off_126FD4 + 3) = v0;
    freq_offset_to_channel((char)v0);
  }
  return rx_index_update();
}

