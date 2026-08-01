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

extern uint32_t off_11430C;
extern uint32_t off_114310;
extern uint32_t off_114314;

// ke_event_busy_check @ 0x1142e0, size 42 bytes
// Doc: ke_event_busy_check [util]: Get LMAC state value from global pointer
// ke_event_busy_check [util]: Get LMAC state value from global pointer
void ke_event_busy_check()
{
  int *v0; // r4

  v0 = (int *)off_11430C;
  if ( !*(uint32_t *)off_11430C )
    *v0 = ke_event_schedule();
  if ( !*(uint32_t *)off_114310 )
    *(uint32_t *)off_114310 = *v0 + 67092480;
  *(uint32_t *)off_114314 = 1;
}

