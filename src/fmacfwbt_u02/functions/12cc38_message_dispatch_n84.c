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

// hci_evt_alloc_send @ 0x12cc38, size 16 bytes
// Doc: message_dispatch_n86_cc3a [ipc]: Dispatch IPC message storing two halfword params at negative offset
// message_dispatch_n86_cc3a [ipc]: Dispatch IPC message storing two halfword params at negative offset
int  hci_evt_alloc_send(int16_t a1, int16_t a2, int16_t a3)
{
  int v3; // r0

  v3 = bt_buf_alloc(a1, a2, a3, 0);
  return hci_evt_send(v3);
}

