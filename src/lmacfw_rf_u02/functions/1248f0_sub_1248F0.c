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

extern uint32_t off_12490C;
extern uint32_t dword_124910;

// mmio_clear_flag @ 0x1248f0, size 26 bytes
int mmio_clear_flag()
{
  *(uint8_t *)off_12490C = 0;
  ke_int_lock(144, 0);
  dispatch_event_handler(dword_124910);
  return 0;
}

