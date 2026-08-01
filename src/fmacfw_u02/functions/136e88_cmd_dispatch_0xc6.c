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

extern uint32_t dword_136E98;
extern uint32_t off_136E94;

// rf_power_off @ 0x136e88, size 12 bytes
// Doc: rf_power_off [ipc]: Dispatches host command ID 0xC6 handler
// rf_power_off [ipc]: Dispatches host command ID 0xC6 handler
int rf_power_off()
{
  int v0; // r0

  v0 = dword_136E98;
  *(uint8_t *)off_136E94 = 0;
  return event_dispatch(v0);
}

