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

extern uint32_t off_13596C;

// sub_135940 @ 0x135940, size 44 bytes
int  sub_135940(int a1)
{
  uint32_t *v1; // r5

  v1 = off_13596C;
  sub_12C5FC(6154, 6);
  sub_143630(a1, v1[4], 54);
  sub_12C8F8(v1[4] - 12);
  v1[4] = a1;
  return sub_135224();
}

