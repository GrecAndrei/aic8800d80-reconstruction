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

extern uint32_t off_1158A0;

// is_flag_set_clz @ 0x115890, size 14 bytes
// Doc: is_flag_set_clz [util]: Check if flag byte is set using clz, returns 0/1
// is_flag_set_clz [util]: Check if flag byte is set using clz, returns 0/1
BOOL is_flag_set_clz()
{
  return *((uint8_t *)off_1158A0 + 142) == 0;
}

