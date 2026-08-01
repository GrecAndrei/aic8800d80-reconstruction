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

extern uint32_t dword_13070C;
extern uint32_t off_130710;

// rf_calibrate_value @ 0x1306cc, size 62 bytes
unsigned int rf_calibrate_value()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(wait_radio_ready());
  ke_event_schedule(dword_13070C, v0);
  v1 = (char)v0 - *((char *)off_130710 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_130710 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((uint8_t *)off_130710 + 3) = v0;
    ke_timeout_to_ticks((char)v0);
  }
  return ll_seq_update();
}

