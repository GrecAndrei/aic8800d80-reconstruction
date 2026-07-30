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

extern uint32_t dword_1197A0;
extern uint32_t dword_11979C;

// sub_11972C @ 0x11972c, size 110 bytes
int  sub_11972C(int a1, int a2, int a3, int a4)
{
  int v4; // r8
  int v5; // r7

  v4 = dword_1197A0;
  v5 = dword_11979C;
  sub_1282E8(dword_1197A0, a2 + 1, 12);
  sub_1282E8(v4 + 12, a2 + 13, 10);
  sub_1282E8(v4 + 24, a2 + 23, 12);
  sub_1282E8(v5, a2 + 35, 12);
  sub_1282E8(v5 + 12, a2 + 47, 10);
  sub_1282E8(v5 + 24, a2 + 57, 12);
  sub_11DED8(120, a4, a3);
  return 0;
}

