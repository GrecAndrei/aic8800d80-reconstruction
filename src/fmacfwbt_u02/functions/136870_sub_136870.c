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

extern uint32_t off_13688C;

// txpwr_reset_state @ 0x136870, size 28 bytes
// Doc: sub_1236870 [util]: Initialize/zero a 16-byte control structure via memset
// sub_1236870 [util]: Initialize/zero a 16-byte control structure via memset
uint32_t *txpwr_reset_state()
{
  uint8_t *v0; // r4

  v0 = off_13688C;
  memset_byte((int *)off_13688C, 0, 0x10u);
  v0[12] = 0;
  return hci_cmd_send(7u, 0);
}

