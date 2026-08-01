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

extern uint32_t dword_123948;

// lld_evt_timer_set @ 0x123920, size 40 bytes
// Doc: lld_evt_timer_set [mac]: Prepare and send FMAC command, returns status
// lld_evt_timer_set [mac]: Prepare and send FMAC command, returns status
int  lld_evt_timer_set(int a1, int a2, int a3, int a4)
{
  remove_tx_buffer(a2);
  check_status_bits(256, dword_123948);
  ke_msg_send_no_param(108, a4, a3);
  return 0;
}

