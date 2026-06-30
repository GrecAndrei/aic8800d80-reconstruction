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

// sub_130F28 @ 0x130f28, size 40 bytes
uint8_t * sub_130F28(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0

  result = sub_12DCA0(a1, a2);
  if ( result )
  {
    *(uint16_t *)(a3 + 228) = result[2] | (result[3] << 8);
    *(uint8_t *)(a3 + 230) = result[4];
  }
  else
  {
    *(uint8_t *)(a3 + 230) = 0;
    *(uint16_t *)(a3 + 228) = 0;
  }
  return result;
}

