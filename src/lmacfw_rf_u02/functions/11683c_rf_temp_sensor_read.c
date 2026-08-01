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

extern uint32_t off_116854;

// event_count_update @ 0x11683c, size 24 bytes
// Doc: event_count_update [rf]: Read RF temperature sensor value
// event_count_update [rf]: Read RF temperature sensor value
int event_count_update()
{
  uint8_t *v0; // r4
  int v1; // r0
  int result; // r0

  v0 = off_116854;
  v1 = list_init(off_116854);
  result = (uint8_t)(return_2(v1) - 1);
  v0[11] = result;
  v0[10] = result;
  return result;
}

