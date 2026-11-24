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

// sdio_set_blocksize @ 0x137274, size 40 bytes
int sdio_set_blocksize()
{
  int v0; // r0
  int v1; // r0

  v0 = bt_buf_alloc(2051, 2, 4, 1);
  hci_evt_send(v0);
  v1 = hci_cmd_send_short(4u);
  state_check_feature(8, "scanu cancel:%d\r\n", v1);
  return 0;
}
