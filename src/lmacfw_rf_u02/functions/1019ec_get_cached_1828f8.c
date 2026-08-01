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

extern uint32_t dword_101A18;
extern uint32_t dword_101A1C;
extern uint32_t off_101A14;

// mac_time_get @ 0x1019ec, size 40 bytes
// Doc: mac_time_get [util]: Retrieve cached pointer/value from table
// mac_time_get [util]: Retrieve cached pointer/value from table
uint64_t * mac_time_get(uint64_t *result, int a2)
{
  uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (uint64_t *)dispatch_event_handler(dword_101A18, dword_101A1C);
    *v2 = *(uint64_t *)((char *)off_101A14 + 36);
  }
  else
  {
    *result = *(uint64_t *)((char *)off_101A14 + 36);
  }
  return result;
}

