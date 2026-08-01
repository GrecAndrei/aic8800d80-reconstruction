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

// get_event_handler @ 0x11f4cc, size 6 bytes
// Doc: get_event_handler [rf]: Read RF control field from memory-mapped register
// get_event_handler [rf]: Read RF control field from memory-mapped register
int get_event_handler()
{
  return *((uint32_t *)rf_mem_read_f4d4 + 1);
}

