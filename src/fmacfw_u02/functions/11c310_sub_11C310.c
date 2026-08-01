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

extern uint32_t off_11C344;
extern uint32_t off_11C34C;
extern uint32_t off_11C348;

// check_radio_interrupt @ 0x11c310, size 52 bytes
int check_radio_interrupt()
{
  int result; // r0
  int v1; // r4
  int *v2; // r2
  int v3; // r3

  result = is_radio_ready();
  if ( (*(uint32_t *)off_11C344 & 0x8000) != 0 && (v1 = result, (result = rf_get_status_bit21()) != 0) && v1 )
  {
    v2 = (int *)off_11C34C;
    v3 = *(uint32_t *)off_11C34C;
    *((uint32_t *)off_11C348 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((uint32_t *)off_11C348 + 4) = 0;
  }
  return result;
}

