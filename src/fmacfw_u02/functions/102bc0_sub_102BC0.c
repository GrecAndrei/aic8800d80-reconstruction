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


extern uint32_t off_102BF0;
extern uint32_t off_102BF8;

// check_radio_state @ 0x102bc0, size 38 bytes
int check_radio_state()
{
  int result; // r0

  result = event_dispatch("%s\r\n", aIntcSpurious);
  if ( **(uint16_t **)off_102BF0 < 0 )
    return mmio_clear_register(off_102BF8, (int)aIntcSpurious_0, 61);
  return result;
}
