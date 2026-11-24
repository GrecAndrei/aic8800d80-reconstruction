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


extern uint32_t off_112B34;
extern uint32_t off_112B3C;
extern uint32_t off_112B40;

// ke_wait_event_b @ 0x112b04, size 48 bytes
int ke_wait_event_b()
{
  int result; // r0
  uint32_t *v1; // r2

  if ( (((uint32_t *)(uintptr_t)off_112B34)[44] & 0x40000000) != 0 )
    result = (int)uart_puts(aUsbWkup_0);
  else
    result = ke_event_schedule_1(aUsbWkup);
  v1 = off_112B40;
  *(uint8_t *)off_112B3C = 0;
  v1[896] &= ~1u;
  return result;
}
