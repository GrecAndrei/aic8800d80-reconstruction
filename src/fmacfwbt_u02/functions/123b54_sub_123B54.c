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

extern uint32_t dword_123B7C;

// log_debug @ 0x123b54, size 40 bytes
// Doc: sub_1223B54 [unknown]: Unknown helper at 0x1223B54
// sub_1223B54 [unknown]: Unknown helper at 0x1223B54
int  log_debug(int a1, int a2, int a3, int a4)
{
  int v5; // r3

  tx_buffer_cleanup(a2);
  state_check_feature(256, dword_123B7C);
  hci_evt_alloc_send(108, a4, a3, v5);
  return 0;
}

