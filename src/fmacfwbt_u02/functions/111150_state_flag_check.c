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

extern uint32_t off_111160;
extern uint32_t off_111164;

// ll_util_get_state @ 0x111150, size 16 bytes
// Doc: ll_util_get_state [rf]: Check internal state flags
// ll_util_get_state [rf]: Check internal state flags
int ll_util_get_state()
{
  if ( *(uint8_t *)off_111160 )
    return 1;
  else
    return *(uint8_t *)off_111164;
}

