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

// sub_12034C @ 0x12034c, size 26 bytes
int  sub_12034C(int a1)
{
  uint32_t *v2; // r0

  v2 = (uint32_t *)sub_12C7EC(143, 0, 255, 4);
  *v2 = a1;
  return sub_12C84C(v2);
}

