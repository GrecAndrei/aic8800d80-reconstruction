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


extern uint32_t off_1125E0;
extern uint32_t off_1125E8;
extern uint32_t off_1125EC;

// ke_poll_event_b @ 0x1125b0, size 48 bytes
int ke_poll_event_b()
{
  int result; // r0
  uint32_t *v1; // r2

  if ( (*(uint16_t *)(off_1125E0 + 0xB2) & 0x4000) != 0 )
    result = (int)uart_tx_string(aUsbWkup_0);
  else
    result = dispatch_event_handler_1(aUsbWkup);
  v1 = off_1125EC;
  *(uint8_t *)off_1125E8 = 0;
  v1[896] &= ~1u;
  return result;
}
