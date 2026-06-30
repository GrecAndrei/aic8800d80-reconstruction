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

extern uint32_t off_10D780;

// log_hw_init_if_d774 @ 0x10d774, size 12 bytes
// Doc: log_hw_init_if_d774 [util]: Initializes hardware log interface via NVIC (0xe000e100)
// log_hw_init_if_d774 [util]: Initializes hardware log interface via NVIC (0xe000e100)
void log_hw_init_if_d774()
{
  if ( !*(uint32_t *)off_10D780 )
    log_hw_init_d648();
}

