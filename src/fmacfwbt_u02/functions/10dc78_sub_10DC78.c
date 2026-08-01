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

extern uint32_t off_10DC8C;

// check_radio_flag @ 0x10dc78, size 18 bytes
int check_radio_flag()
{
  if ( *((uint8_t *)off_10DC8C + 369) )
    return gpio_set_bit_reg0(1);
  else
    return gpio_clear_bit_reg0(1);
}

