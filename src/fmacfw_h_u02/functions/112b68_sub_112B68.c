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
extern uint32_t dword_112BA8;
extern uint32_t dword_112B9C;
extern uint32_t off_112BA4;
extern uint32_t off_112BA0;

// mac_get_int_status @ 0x112b68, size 48 bytes
uint8_t * mac_get_int_status(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)off_112B98 + 89) & 0x4000) != 0 )
    result = radio_tx_write_string((uint8_t *)dword_112BA8);
  else
    result = (uint8_t *)alloc_tx_event(dword_112B9C, a2, a3);
  v4 = off_112BA4;
  *(uint8_t *)off_112BA0 = 0;
  v4[896] &= ~1u;
  return result;
}

