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

extern uint32_t off_128544;

// wlc_ops_wrapper @ 0x128520, size 34 bytes
// Doc: sub_1228520 [util]: Trivial wrapper calling sub_1284d0
// sub_1228520 [util]: Trivial wrapper calling sub_1284d0
BOOL  wlc_ops_wrapper(int a1)
{
  BOOL result; // r0

  result = wlc_get_ops_alt(a1);
  if ( result )
    return !*((uint32_t *)off_128544 + 11) || *(uint8_t *)(*((uint32_t *)off_128544 + 10) + 16) == 6;
  return result;
}

