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

extern uint32_t dword_122A04;

// sub_1229E8 @ 0x1229e8, size 28 bytes
int  sub_1229E8(int a1, int a2, int a3, int a4)
{
  sub_143630(dword_122A04, a2, 69);
  sub_12C8D0(120, a4, a3);
  return 0;
}

