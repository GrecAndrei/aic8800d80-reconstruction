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

extern uint32_t dword_112AF4;

// ke_wait_event_a @ 0x112ac0, size 40 bytes
// Doc: rf_msg_handler_n_49e [rf]: Handles RF subsystem messages from host
// rf_msg_handler_n_49e [rf]: Handles RF subsystem messages from host
uint8_t * ke_wait_event_a(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)rf_msg_handler_n_478 + 89) & 0x4000) != 0 )
    result = uart_puts((uint8_t *)dword_112AF4);
  else
    result = (uint8_t *)ke_event_schedule(rf_msg_handler_n_474, a2, a3);
  *(uint8_t *)rf_msg_handler_n_470 = 1;
  return result;
}

