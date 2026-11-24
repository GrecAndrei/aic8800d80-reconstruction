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


extern uint32_t off_126FD4;

// rf_set_frequency_2 @ 0x126f90, size 62 bytes
int  rf_set_frequency_2(int a1)
{
  int v1; // s15
  int v2; // r3

  v1 = (int)COERCE_FLOAT(wait_sdio_core_ready());
  dispatch_event_handler_1("\x9D\x89t=%d C\n", v1);
  v2 = (char)v1 - *((char *)off_126FD4 + 3);
  if ( v2 < 0 )
    v2 = *((char *)off_126FD4 + 3) - (char)v1;
  if ( v2 > 4 )
  {
    *((uint8_t *)off_126FD4 + 3) = v1;
    freq_offset_to_channel((char)v1);
  }
  return rx_index_update();
}
