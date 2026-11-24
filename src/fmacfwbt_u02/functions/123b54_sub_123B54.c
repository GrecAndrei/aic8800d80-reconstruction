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

// log_debug @ 0x123b54, size 40 bytes
int  log_debug(int a1, int a2, int a3, int a4)
{
  tx_buffer_cleanup(a2);
  state_check_feature(256, aSetMuEdca);
  hci_evt_alloc_send(108, a4, a3);
  return 0;
}
