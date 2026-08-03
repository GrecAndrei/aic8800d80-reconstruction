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

extern uint32_t dword_123808;

// sub_1237E0 @ 0x1237e0, size 40 bytes
int  sub_1237E0(int a1, int a2, int a3, int a4)
{
  sub_11C350(a2);
  sub_12EB90(256, dword_123808);
  sub_12C8D0(108, a4, a3);
  return 0;
}

