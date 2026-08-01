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

// phy_enable @ 0x13ade4, size 24 bytes
int  phy_enable(int a1, int a2)
{
  int16_t v2; // r2

  v2 = *(uint16_t *)(a1 + 30) | 1;
  *(uint32_t *)(a1 + 68) = 0;
  *(uint32_t *)(a1 + 80) = 0;
  *(uint16_t *)(a1 + 30) = v2;
  return phy_txpower_calc(a1, a2);
}

