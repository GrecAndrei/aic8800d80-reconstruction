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

extern uint32_t off_126468;

// is_flag_set_n645c @ 0x12645c, size 12 bytes
// Doc: is_flag_set_n645c [util]: Check flag byte at 0x180834 returns 0 or 1
// is_flag_set_n645c [util]: Check flag byte at 0x180834 returns 0 or 1
int is_flag_set_n645c()
{
  int result; // r0

  result = *(uint8_t *)off_126468;
  if ( *(uint8_t *)off_126468 )
    return 1;
  return result;
}

