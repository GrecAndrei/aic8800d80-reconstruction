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

extern uint32_t dword_137020;

// rf_cmd_txpwr_set @ 0x137000, size 32 bytes
// Doc: sub_1237000 [ipc]: IPC/control message handler entry
// sub_1237000 [ipc]: IPC/control message handler entry
int  rf_cmd_txpwr_set(int a1, int a2, int a3, int16_t a4)
{
  int v4; // r0

  v4 = bt_buf_alloc(4107, a4, 4, 1u);
  hci_evt_send(v4);
  state_check_feature(8, dword_137020);
  return 0;
}

