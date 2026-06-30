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

extern uint32_t off_117A1C;
extern uint32_t off_117A20;

// sub_1179F4 @ 0x1179f4, size 38 bytes
// Doc: sub_12179F4 [patch]: Checks upper-nibble mask and dispatches handler
// sub_12179F4 [patch]: Checks upper-nibble mask and dispatches handler
int sub_1179F4()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(uint32_t *)off_117A1C & 0xF00000;
  if ( v0 )
  {
    result = sub_11AC74((uint8_t)(11 - __clz(v0)));
    *(uint32_t *)off_117A20 = v0;
  }
  else
  {
    *(uint32_t *)off_117A20 = 0;
  }
  return result;
}

