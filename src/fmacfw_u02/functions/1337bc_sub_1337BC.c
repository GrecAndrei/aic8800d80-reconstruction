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

extern uint32_t off_1337F0;
extern uint32_t dword_1337F8;
extern uint32_t dword_1337F4;

// patch_flag_get @ 0x1337bc, size 52 bytes
int  patch_flag_get(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_1337F0 >= 0 || (value = rx_rate_field_parse(6u), value == 10) )
  {
    bt_patch_set_delay(value);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_1337F8, dword_1337F4, 1038);
    bt_patch_set_delay(v2);
    return 0;
  }
}

