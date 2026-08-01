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

extern uint32_t dword_1154D4;
extern uint32_t off_1154D0;

// event_reset @ 0x1154c4, size 12 bytes
int  event_reset(int a1, int a2)
{
  int v2; // r0

  v2 = dword_1154D4;
  *(uint8_t *)off_1154D0 = 0;
  return event_dispatch(v2, a2, 0);
}

