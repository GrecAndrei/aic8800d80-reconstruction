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

extern uint32_t dword_137084;

// sub_137054 @ 0x137054, size 48 bytes
int  sub_137054(int a1, int a2, int a3, int16_t a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)rf_bus_setup_n3a8(4104, a4, 4, 2u);
  feature_guard_sdio(8, dword_137084);
  *v5 = 1;
  v5[1] = *(uint8_t *)(a2 + 2);
  sub_12CBB4((int)v5);
  return 0;
}

