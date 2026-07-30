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

// sub_12ADD4 @ 0x12add4, size 30 bytes
uint8_t * sub_12ADD4(uint8_t *result)
{
  *result = -35;
  result[2] = 80;
  result[3] = 111;
  result[4] = -102;
  result[5] = 9;
  result[6] = 12;
  return result;
}

