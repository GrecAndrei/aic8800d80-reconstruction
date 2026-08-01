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

// ke_event_send_4 @ 0x114d40, size 10 bytes
// Doc: ke_event_send_4 [patch]: Apply N NOP-aligned patch entries (count=0x14)
// ke_event_send_4 [patch]: Apply N NOP-aligned patch entries (count=0x14)
int  ke_event_send_4(int a1)
{
  return ke_task_handler(2, a1, 0xCu);
}

