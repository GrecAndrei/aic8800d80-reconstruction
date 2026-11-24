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


extern uint32_t off_112CD8;
extern uint32_t off_112CE0;
extern uint32_t off_112CE4;

// rf_isr_clear @ 0x112ca8, size 48 bytes
int rf_isr_clear()
{
  int result; // r0
  uint32_t *v1; // r2

  if ( (((uint32_t *)(uintptr_t)off_112CD8)[44] & 0x40000000) != 0 )
    result = (int)read_memory_byte(aUsbWkup_0);
  else
    result = event_dispatch(aUsbWkup);
  v1 = off_112CE4;
  *(uint8_t *)off_112CE0 = 0;
  v1[896] &= ~1u;
  return result;
}
