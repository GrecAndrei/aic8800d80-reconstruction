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

extern uint32_t off_128768;

// bt_link_type @ 0x128744, size 34 bytes
BOOL  bt_link_type(int a1)
{
  BOOL result; // r0

  result = bt_link_check(a1);
  if ( result )
    return !*((uint32_t *)off_128768 + 11) || *(uint8_t *)(*((uint32_t *)off_128768 + 10) + 16) == 6;
  return result;
}

