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

extern uint32_t off_1304FC;

// clear_flag_send_event_42e @ 0x1304d8, size 36 bytes
int clear_flag_send_event_42e()
{
  int result; // r0

  *((uint8_t *)off_1304FC + 1) = 0;
  result = rf_get_state(1070, 1);
  if ( result )
    return invalid_handler_12c5fc(1070, 1);
  return result;
}

