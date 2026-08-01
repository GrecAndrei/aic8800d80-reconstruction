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

// dec_retry_count @ 0x11a2d0, size 22 bytes
// Doc: sub_121A2D0 [util]: Decrement reference counter at offset 0xe and deref handle at 0x154
// sub_121A2D0 [util]: Decrement reference counter at offset 0xe and deref handle at 0x154
int  dec_retry_count(int result)
{
  char v1; // r3

  v1 = *(uint8_t *)(result + 14) - 1;
  *(uint8_t *)(result + 14) = v1;
  if ( !v1 )
    return cmd_handler_a(*(uint32_t *)(result + 340));
  return result;
}

