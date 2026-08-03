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

extern uint32_t off_137258;
extern uint32_t dword_13725C;

// ipc_msg_send_0x100b @ 0x137228, size 48 bytes
// Doc: ipc_msg_send_0x100b [ipc]: Send IPC message with code 0x100b using message dispatch helper
// ipc_msg_send_0x100b [ipc]: Send IPC message with code 0x100b using message dispatch helper
int  ipc_msg_send_0x100b(int a1, uint8_t *a2)
{
  uint16_t *v2; // r5
  int v4; // r0

  v2 = (uint16_t *)off_137258;
  v4 = rf_bus_setup_n3a8(4107, *((uint16_t *)off_137258 + 1924), 4, 1u);
  sub_12CBB4(v4);
  feature_guard_sdio(8, dword_13725C, v2[1924]);
  bt_init_check_1827f4(*a2);
  return 0;
}

