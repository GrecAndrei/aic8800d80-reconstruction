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

extern uint32_t off_100684;

// timer_poll @ 0x100670, size 18 bytes
// Doc: timer_poll [util]: Update cached variant byte from result
// timer_poll [util]: Update cached variant byte from result
int  timer_poll(int a1)
{
  int result; // r0

  result = timer_read(a1);
  if ( *(uint8_t *)off_100684 != result )
    *(uint8_t *)off_100684 = result;
  return result;
}

