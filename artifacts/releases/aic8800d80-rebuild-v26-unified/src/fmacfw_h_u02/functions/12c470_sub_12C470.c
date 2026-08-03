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

extern uint32_t dword_12C484;

// sub_12C470 @ 0x12c470, size 18 bytes
BOOL  sub_12C470(int a1, int a2)
{
  return *(uint32_t *)(a1 + 8) - *(uint32_t *)(a2 + 8) > (unsigned int)dword_12C484;
}

