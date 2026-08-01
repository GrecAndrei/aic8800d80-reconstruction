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

extern uint32_t off_137154;
extern uint32_t dword_137158;

// rf_send_channel_alt @ 0x137124, size 48 bytes
int  rf_send_channel_alt(int a1, uint8_t *a2)
{
  uint16_t *v2; // r5
  int v4; // r0

  v2 = (uint16_t *)off_137154;
  v4 = ke_msg_alloc(4107, *((uint16_t *)off_137154 + 1924), 4, 1u);
  ke_msg_send(v4);
  check_status_bits(8, dword_137158, v2[1924]);
  hci_cmd_process(*a2);
  return 0;
}

