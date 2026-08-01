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

extern uint32_t off_126DD0;
extern uint32_t dword_126DD4;

// rx_index_update @ 0x126da4, size 44 bytes
unsigned int rx_index_update()
{
  uint8_t *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  uint8_t v3; // r0

  v0 = (uint8_t *)off_126DD0;
  result = *((uint8_t *)off_126DD0 + 6);
  v2 = *((uint8_t *)off_126DD0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((uint8_t *)off_126DD0 + 6) = v3;
    set_xtal_ftune(v3);
    return dispatch_event_handler(dword_126DD4, v0[5], v0[6]);
  }
  return result;
}

