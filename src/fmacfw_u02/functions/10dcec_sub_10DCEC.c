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

extern uint32_t off_10DCFC;

// sub_10DCEC @ 0x10dcec, size 16 bytes
int  sub_10DCEC(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DCFC + 2);
  *((uint32_t *)off_10DCFC + 2) = result;
  return result;
}

