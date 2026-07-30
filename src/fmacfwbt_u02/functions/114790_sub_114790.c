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

// sub_114790 @ 0x114790, size 42 bytes
int  sub_114790(uint8_t *a1)
{
  int v1; // r3

  v1 = *a1;
  switch ( v1 )
  {
    case 1:
      return a1[3] + 4;
    case 2:
      return *(uint16_t *)(a1 + 3) + 5;
    case 3:
      return a1[3] + 4;
    case 4:
      return a1[2] + 3;
  }
  return -1;
}

