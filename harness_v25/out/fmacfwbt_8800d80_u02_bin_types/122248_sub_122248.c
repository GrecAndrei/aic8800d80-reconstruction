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

// sub_122248 @ 0x122248, size 30 bytes
int  sub_122248(int a1)
{
  uint8_t *v2; // r0

  v2 = (uint8_t *)sub_12CB54(67, 6, 0, 1);
  *v2 = *(uint8_t *)(a1 + 107);
  return sub_12CBB4(v2);
}

