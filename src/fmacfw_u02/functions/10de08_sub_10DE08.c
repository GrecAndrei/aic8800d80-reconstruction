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

extern uint32_t off_10DE1C;

// util_get_struct_offset @ 0x10de08, size 18 bytes
int util_get_struct_offset()
{
  if ( *((uint8_t *)off_10DE1C + 369) )
    return gpio_set_bit(2);
  else
    return gpio_clear_bit(2);
}

