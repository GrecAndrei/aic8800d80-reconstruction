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

// sub_12D240 @ 0x12d240, size 8 bytes
// Doc: sub_122D240 [util]: Zero-initialize a structure and check a status flag
// sub_122D240 [util]: Zero-initialize a structure and check a status flag
uint32_t * sub_12D240(uint32_t *result)
{
  *result = 0;
  result[1] = 0;
  return result;
}

