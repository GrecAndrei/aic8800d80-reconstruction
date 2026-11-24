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


extern uint32_t off_126E7C;

// sub_126E54 @ 0x126e54, size 38 bytes
int sub_126E54()
{
  if ( *((uint8_t *)off_126E7C + 1) )
    return *((char *)off_126E7C + 3);
  sub_10DE98();
  return (int)COERCE_FLOAT(sub_10DEF0());
}
