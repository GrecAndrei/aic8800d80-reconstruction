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

// sub_12C8E0 @ 0x12c8e0, size 22 bytes
int  sub_12C8E0(int a1, int16_t a2, int16_t a3, int16_t a4)
{
  *(uint16_t *)(a1 - 8) = a2;
  *(uint16_t *)(a1 - 6) = a3;
  *(uint16_t *)(a1 - 4) = a4;
  return sub_12C84C(a1);
}

