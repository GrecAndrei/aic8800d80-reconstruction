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

extern uint32_t dword_112598;

// ke_poll_event_a @ 0x11256c, size 40 bytes
// Doc: rf_fault_dump [rf]: Dumps RF fault state for diagnostic logging
// rf_fault_dump [rf]: Dumps RF fault state for diagnostic logging
uint8_t * ke_poll_event_a(int a1, int a2)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)rf_bus_reset_n2a4 + 89) & 0x4000) != 0 )
    result = uart_tx_string((uint8_t *)fmac_chan_set_or_init);
  else
    result = (uint8_t *)dispatch_event_handler(dword_112598, a2);
  *(uint8_t *)rf_cmd_send_n_37c = 1;
  return result;
}

