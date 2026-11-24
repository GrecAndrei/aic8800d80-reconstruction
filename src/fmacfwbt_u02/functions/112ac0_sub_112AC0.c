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


extern uint32_t off_112AE8;
extern uint32_t off_112AF0;

// ke_wait_event_a @ 0x112ac0, size 40 bytes
int ke_wait_event_a()
{
  int result; // r0

  if ( (((uint32_t *)(uintptr_t)off_112AE8)[44] & 0x40000000) != 0 )
    result = (int)uart_puts(aUsbSusp_0);
  else
    result = ke_event_schedule_1(aUsbSusp);
  *(uint8_t *)off_112AF0 = 1;
  return result;
}
