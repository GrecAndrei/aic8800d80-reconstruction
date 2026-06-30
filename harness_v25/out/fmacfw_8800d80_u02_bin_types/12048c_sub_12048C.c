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

// sub_12048C @ 0x12048c, size 26 bytes
int  sub_12048C(int a1)
{
  uint32_t *v2; // r0

  v2 = (uint32_t *)sub_12C92C(143, 0, 255, 4);
  *v2 = a1;
  return sub_12C98C(v2);
}

