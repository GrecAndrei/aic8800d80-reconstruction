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

// rf_cmd_read @ 0x137228, size 48 bytes
// Doc: rf_cmd_read [ipc]: Send IPC message with code 0x100b using message dispatch helper
// rf_cmd_read [ipc]: Send IPC message with code 0x100b using message dispatch helper
int  rf_cmd_read(int a1, uint8_t *a2)
{
  uint16_t *v2; // r5
  int v4; // r0

  v2 = (uint16_t *)off_137258;
  v4 = bt_buf_alloc(4107, *((uint16_t *)off_137258 + 1924), 4, 1u);
  hci_evt_send(v4);
  state_check_feature(8, dword_13725C, v2[1924]);
  radio_event_dispatcher(*a2);
  return 0;
}

