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

extern uint32_t off_124938;
extern uint32_t dword_12493C;
extern uint32_t off_124934;
extern uint32_t dword_124940;

// mmio_enable_clock @ 0x124914, size 32 bytes
int mmio_enable_clock()
{
  int *v0; // r1
  int v1; // r0

  v0 = (int *)off_124938;
  v1 = dword_12493C;
  *(uint32_t *)off_124934 |= 0x10u;
  *v0 = v1;
  write_bb_control();
  dispatch_event_handler(dword_124940);
  return 0;
}

