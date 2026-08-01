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

extern uint32_t dword_1125F0;

// ke_poll_event_b @ 0x1125b0, size 48 bytes
// Doc: rf_cmd_send_n_360 [rf]: Send RF command to hardware queue
// rf_cmd_send_n_360 [rf]: Send RF command to hardware queue
uint8_t * ke_poll_event_b(int a1, int a2)
{
  uint8_t *result; // r0
  uint32_t *v3; // r2

  if ( (*((uint16_t *)rf_cmd_send_n_338 + 89) & 0x4000) != 0 )
    result = uart_tx_string((uint8_t *)dword_1125F0);
  else
    result = (uint8_t *)dispatch_event_handler(rf_bus_reset_n2f4, a2);
  v3 = rf_cmd_send_n_32c;
  *(uint8_t *)rf_bus_reset_n2f8_0 = 0;
  v3[896] &= ~1u;
  return result;
}

