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

extern uint32_t dword_136DDC;

// sub_136DBC @ 0x136dbc, size 32 bytes
int  sub_136DBC(int a1, int a2, int a3, int16_t a4)
{
  int v4; // r0

  v4 = sub_12C7EC(4107, a4, 4, 1u);
  sub_12C84C(v4);
  sub_12EB90(8, dword_136DDC);
  return 0;
}

