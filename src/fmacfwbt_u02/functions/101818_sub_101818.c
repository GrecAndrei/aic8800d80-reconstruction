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

extern uint32_t dword_101844;
extern uint32_t dword_101848;
extern uint32_t off_101840;

// timer_count_read @ 0x101818, size 40 bytes
uint64_t * timer_count_read(uint64_t *result, int a2)
{
  uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (uint64_t *)ke_event_schedule(dword_101844, dword_101848, a2);
    *v2 = *(uint64_t *)((char *)off_101840 + 36);
  }
  else
  {
    *result = *(uint64_t *)((char *)off_101840 + 36);
  }
  return result;
}

