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

extern uint32_t dword_1303B0;
extern uint32_t off_1303B4;

// rf_timer_toggle_start @ 0x130370, size 62 bytes
unsigned int rf_timer_toggle_start()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(hw_poll_status());
  alloc_tx_event(dword_1303B0, v0);
  v1 = (char)v0 - *((char *)off_1303B4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_1303B4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((uint8_t *)off_1303B4 + 3) = v0;
    check_frame_len((char)v0);
  }
  return compare_calibration_levels();
}

