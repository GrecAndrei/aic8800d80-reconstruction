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

extern uint32_t dword_14053C;

// ble_ll_adv_chk_active @ 0x140510, size 42 bytes
BOOL ble_ll_adv_chk_active()
{
  int v0; // r5

  v0 = dword_14053C;
  if ( !*(uint32_t *)(dword_14053C + 6472) )
    return 1;
  if ( rx_rate_field_parse(0xBu) == 3 )
    return **(uint32_t **)(v0 + 6472) == 0;
  return 0;
}

