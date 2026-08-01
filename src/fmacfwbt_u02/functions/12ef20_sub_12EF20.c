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

extern uint32_t dword_12EF40;
extern uint32_t off_12EF44;

// bt_init_controller @ 0x12ef20, size 32 bytes
int bt_init_controller()
{
  ke_event_schedule(dword_12EF40);
  irq_lock(1071, 1);
  *((uint32_t *)off_12EF44 + 20) &= ~2u;
  return 0;
}

