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

extern uint32_t dword_10EDCC;
extern uint32_t dword_10EDC8;
extern uint32_t dword_10EDD0;

// sub_10ED98 @ 0x10ed98, size 46 bytes
int  sub_10ED98(int a1)
{
  sub_10ECEC(dword_10EDCC, 196608, dword_10EDC8, 1);
  sub_10EC98(dword_10EDD0, a1 << 15, 1);
  return sub_10ECEC(1879048192, 1, 1, 1);
}

