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


extern uint32_t off_112594;
extern uint32_t off_11259C;

// ke_poll_event_a @ 0x11256c, size 40 bytes
int ke_poll_event_a()
{
  int result; // r0

  if ( (*(uint16_t *)(off_112594 + 0xB2) & 0x4000) != 0 )
    result = (int)uart_tx_string(aUsbSusp_0);
  else
    result = dispatch_event_handler_1(aUsbSusp);
  *(uint8_t *)off_11259C = 1;
  return result;
}
