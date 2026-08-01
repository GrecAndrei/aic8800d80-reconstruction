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

// nvic_configure @ 0x10d774, size 12 bytes
// Doc: nvic_configure [util]: Initializes hardware log interface via NVIC (0xe000e100)
// nvic_configure [util]: Initializes hardware log interface via NVIC (0xe000e100)
void nvic_configure()
{
  if ( !*(uint32_t *)off_10D780 )
    is_initialized();
}

