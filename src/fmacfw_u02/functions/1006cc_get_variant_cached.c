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

extern uint32_t off_1006D4;

// get_status_byte @ 0x1006cc, size 6 bytes
// Doc: get_status_byte [util]: Return cached silicon variant byte from global table at offset 1
// get_status_byte [util]: Return cached silicon variant byte from global table at offset 1
int get_status_byte()
{
  return *((uint8_t *)off_1006D4 + 1);
}

