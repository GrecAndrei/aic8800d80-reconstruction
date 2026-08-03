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

extern uint32_t dword_12DE90;

// sub_12DE70 @ 0x12de70, size 30 bytes
int  sub_12DE70(int a1, int16_t a2)
{
  return dword_12DE90
       & ((((32 * (*(uint8_t *)(a1 + 5) ^ (*(uint8_t *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

