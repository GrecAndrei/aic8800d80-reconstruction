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

// rf_write_pattern_4605 @ 0x1309f0, size 46 bytes
int  rf_write_pattern_4605(int a1)
{
  **(uint8_t **)a1 = 70;
  *(uint8_t *)(*(uint32_t *)a1 + 1) = 5;
  *(uint8_t *)(*(uint32_t *)a1 + 2) = 112;
  *(uint8_t *)(*(uint32_t *)a1 + 3) = 0;
  *(uint8_t *)(*(uint32_t *)a1 + 4) = 0;
  *(uint8_t *)(*(uint32_t *)a1 + 5) = 0;
  *(uint8_t *)(*(uint32_t *)a1 + 6) = 0;
  *(uint32_t *)a1 += 7;
  return 7;
}

