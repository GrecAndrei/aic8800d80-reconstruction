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

// build_tx_power_cfg @ 0x130d14, size 54 bytes
int  build_tx_power_cfg(int a1, int a2)
{
  int16_t v2; // r3
  int16_t v3; // r4
  int16_t v4; // r2

  *(uint8_t *)a1 = 3;
  *(uint8_t *)(a1 + 1) = 0;
  *(uint8_t *)(a1 + 2) = *(uint8_t *)(a2 + 23);
  v2 = *(uint8_t *)(a2 + 22);
  v3 = *(uint8_t *)(a2 + 18);
  v4 = *(uint16_t *)(a2 + 20);
  *(uint16_t *)(a1 + 5) = *(uint16_t *)(a2 + 14);
  *(uint16_t *)(a1 + 3) = (4 * v2) | (2 * v3) | (v4 << 6);
  *(uint16_t *)(a1 + 7) = 16 * *(uint16_t *)(a2 + 12);
  return 9;
}

