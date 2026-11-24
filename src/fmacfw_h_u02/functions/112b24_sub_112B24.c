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


extern uint32_t off_112B4C;
extern uint32_t off_112B54;

// wlan_get_state @ 0x112b24, size 40 bytes
int wlan_get_state()
{
  int result; // r0

  if ( (((uint32_t *)(uintptr_t)off_112B4C)[44] & 0x40000000) != 0 )
    result = (int)radio_tx_write_string(aUsbSusp_0);
  else
    result = alloc_tx_event(aUsbSusp);
  *(uint8_t *)off_112B54 = 1;
  return result;
}
