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
extern uint32_t dword_112B58;
extern uint32_t dword_112B50;
extern uint32_t off_112B54;

// wlan_get_state @ 0x112b24, size 40 bytes
uint8_t * wlan_get_state(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112B4C + 89) & 0x4000) != 0 )
    result = radio_tx_write_string((uint8_t *)dword_112B58);
  else
    result = (uint8_t *)alloc_tx_event(dword_112B50, a2, a3);
  *(uint8_t *)off_112B54 = 1;
  return result;
}

