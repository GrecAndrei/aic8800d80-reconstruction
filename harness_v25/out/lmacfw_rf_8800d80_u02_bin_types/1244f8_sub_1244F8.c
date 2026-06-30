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

extern uint32_t off_12451C;

// sub_1244F8 @ 0x1244f8, size 36 bytes
int sub_1244F8()
{
  int result; // r0
  int v1; // r3

  result = sub_1242F0(2u);
  v1 = (uint16_t)(*(uint16_t *)off_12451C + 1);
  if ( v1 == 10 )
  {
    *(uint16_t *)off_12451C = 0;
    return sub_12632C(result);
  }
  else
  {
    *(uint16_t *)off_12451C = v1;
  }
  return result;
}

