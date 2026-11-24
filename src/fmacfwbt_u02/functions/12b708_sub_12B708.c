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

// bt_send_hci_804 @ 0x12b708, size 40 bytes
uint32_t * bt_send_hci_804(char a1, uint16_t a2)
{
  char *v3; // r4

  v3 = (char *)bt_buf_alloc(2052, a2, 2, 1);
  state_check_feature(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return hci_evt_send((int)v3);
}
