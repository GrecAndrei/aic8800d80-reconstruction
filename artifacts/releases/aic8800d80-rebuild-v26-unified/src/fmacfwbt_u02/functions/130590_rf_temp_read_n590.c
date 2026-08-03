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

extern uint32_t off_1305B8;

// rf_temp_read_n590 @ 0x130590, size 38 bytes
// Doc: rf_temp_read_n590 [rf]: Reads signed byte from RF register and forwards value via sub_10dea0
// rf_temp_read_n590 [rf]: Reads signed byte from RF register and forwards value via sub_10dea0
int rf_temp_read_n590()
{
  if ( *((uint8_t *)off_1305B8 + 1) )
    return *((char *)off_1305B8 + 3);
  rf_hw_timer_init();
  return (int)COERCE_FLOAT(rf_hw_timer_read());
}

