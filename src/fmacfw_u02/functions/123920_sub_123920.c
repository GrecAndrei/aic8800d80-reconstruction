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

// lld_evt_timer_set @ 0x123920, size 40 bytes
int  lld_evt_timer_set(int a1, int a2, int a3, int a4)
{
  remove_tx_buffer(a2);
  check_status_bits(256, aSetMuEdca);
  ke_msg_send_no_param(108, a4, a3);
  return 0;
}
