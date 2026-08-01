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

extern uint32_t off_136284;
extern uint32_t dword_13628C;
extern uint32_t dword_136288;

// patch_set_enabled @ 0x13623c, size 70 bytes
int patch_set_enabled()
{
  if ( **(int16_t **)off_136284 < 0 && rx_rate_field_parse(7u) != 3 && rx_rate_field_parse(7u) )
    mmio_clear_register(dword_13628C, dword_136288, 442);
  if ( rx_rate_field_parse(7u) == 3 )
    bt_ready_check(3);
  return 0;
}

