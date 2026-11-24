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


extern uint32_t off_13704C;

// rf_cmd_set @ 0x137024, size 40 bytes
int rf_cmd_set()
{
  uint16_t *v0; // r4
  int v1; // r0

  v0 = (uint16_t *)off_13704C;
  v1 = bt_buf_alloc(4107, *((uint16_t *)off_13704C + 1924), 4, 1);
  hci_evt_send(v1);
  state_check_feature(8, "scan idle cancel cfm %d\r\n", v0[1924]);
  return 0;
}
