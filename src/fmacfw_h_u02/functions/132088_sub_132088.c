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


extern uint32_t dword_1320B8;

// vendor_platform_init @ 0x132088, size 46 bytes
int vendor_platform_init()
{
  memset_thunk((int *)dword_1320B8, 0, 0x17Cu);
  hci_cmd_preprocess(5u, 0);
  clear_shared_mem();
  reset_hci_control_block();
  ble_clear_state();
  init_locks();
  return clear_tx_buf();
}
