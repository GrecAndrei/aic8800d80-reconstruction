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

extern uint32_t off_1178DC;
extern uint32_t off_1178E0;

// sub_1178B4 @ 0x1178b4, size 38 bytes
int sub_1178B4()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(uint32_t *)off_1178DC & 0xF00000;
  if ( v0 )
  {
    result = sub_11AB34((uint8_t)(11 - __clz(v0)));
    *(uint32_t *)off_1178E0 = v0;
  }
  else
  {
    *(uint32_t *)off_1178E0 = 0;
  }
  return result;
}

