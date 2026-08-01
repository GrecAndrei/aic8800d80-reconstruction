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

extern uint32_t off_102B04;
extern uint32_t off_102B08;

// handle_event @ 0x102ad4, size 48 bytes
int handle_event()
{
  int result; // r0
  int *i; // r4

  result = bt_enable(*((uint8_t *)off_102B04 + 36), *((uint16_t *)off_102B04 + 20));
  for ( i = *((int **)off_102B08 + 2); i; i = (int *)*i )
  {
    while ( !*((uint8_t *)i + 108) )
    {
      i = (int *)*i;
      if ( !i )
        return result;
    }
    result = rf_temperature_comp(i);
  }
  return result;
}

