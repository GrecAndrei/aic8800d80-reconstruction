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


extern uint32_t off_12150C;

// bt_post_event_14ea14 @ 0x1214dc, size 42 bytes
int  bt_post_event_14ea14(int a1, uint32_t *a2, int a3, int a4)
{
  dispatch_event_handler_1("\x9D\x81DBG: Setting severity filter: 0x%08x\n", *a2);
  off_12150C[1] = *a2;
  ke_evt_handler(1031, a4, a3);
  return 0;
}
