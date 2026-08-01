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

extern uint32_t dword_1321F8;

// ke_task_reset @ 0x1321c8, size 46 bytes
int ke_task_reset()
{
  uint32_t *v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0

  memset((int *)dword_1321F8, 0, 0x17Cu);
  v0 = rx_phy_status_parse(5u, 0);
  v1 = clear_1924d0_buffer(v0);
  v2 = bt_cmd_buf_clear(v1);
  v3 = reset_controller_state(v2);
  v4 = ll_global_init(v3);
  return clear_197750_buffer(v4);
}

