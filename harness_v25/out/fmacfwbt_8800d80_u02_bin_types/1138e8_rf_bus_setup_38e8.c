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

extern uint32_t off_1138F8;

// rf_bus_setup_38e8 @ 0x1138e8, size 16 bytes
// Doc: rf_bus_setup_38e8 [rf]: Initializes RF bus addresses from globals
// rf_bus_setup_38e8 [rf]: Initializes RF bus addresses from globals
BOOL rf_bus_setup_38e8()
{
  return *((uint8_t *)off_1138F8 + 8) == 1;
}

