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

extern uint32_t off_11E714;
extern uint32_t dword_11E718;

// init_event_control @ 0x11e6ec, size 40 bytes
int init_event_control()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  int v2; // r1

  v0 = critical_enter();
  v1 = off_11E714;
  v2 = dword_11E718;
  *((uint32_t *)off_11E714 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return enter_critical_section(-1);
}

