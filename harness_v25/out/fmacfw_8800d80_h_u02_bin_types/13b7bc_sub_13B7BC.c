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

extern uint32_t off_13B7CC;

// sub_13B7BC @ 0x13b7bc, size 14 bytes
unsigned int  sub_13B7BC(int a1)
{
  return ((unsigned int)(a1 - (*((uint32_t *)off_13B7CC + 4) >> 10)) >> 15) & 1;
}

