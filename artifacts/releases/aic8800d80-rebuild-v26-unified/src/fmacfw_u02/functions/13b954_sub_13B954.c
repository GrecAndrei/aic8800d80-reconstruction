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

// sub_13B954 @ 0x13b954, size 24 bytes
int  sub_13B954(int a1, int16_t a2, char a3)
{
  int result; // r0

  result = (*(int ( **)(int, int))a1)(a1, (a2 - *(uint16_t *)(a1 + 4)) & 0xFFF) + a1;
  *(uint8_t *)(result + 6) = a3;
  return result;
}

