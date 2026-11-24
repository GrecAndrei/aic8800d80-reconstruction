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


extern uint32_t off_112B98;
extern uint32_t off_112BA0;
extern uint32_t off_112BA4;

// mac_get_int_status @ 0x112b68, size 48 bytes
int mac_get_int_status()
{
  int result; // r0
  uint32_t *v1; // r2

  if ( (((uint32_t *)(uintptr_t)off_112B98)[44] & 0x40000000) != 0 )
    result = (int)radio_tx_write_string(aUsbWkup_0);
  else
    result = alloc_tx_event(aUsbWkup);
  v1 = off_112BA4;
  *(uint8_t *)off_112BA0 = 0;
  v1[896] &= ~1u;
  return result;
}
