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

// sub_122810 @ 0x122810, size 30 bytes
int  sub_122810(char a1, char a2)
{
  uint8_t *v4; // r0

  v4 = (uint8_t *)rf_bus_setup_n3a8(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return sub_12CBB4(v4);
}

