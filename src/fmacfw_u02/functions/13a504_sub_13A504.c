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

extern uint32_t dword_13A524;
extern uint32_t off_13A520;

// sub_13A504 @ 0x13a504, size 28 bytes
BOOL sub_13A504()
{
  return *(uint16_t *)(dword_13A524 + 80 * *((uint8_t *)off_13A520 + 68) + 76) == 0;
}

