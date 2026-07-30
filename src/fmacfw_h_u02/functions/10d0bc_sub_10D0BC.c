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

extern uint32_t dword_10D0D8;
extern uint32_t off_10D0E0;
extern uint32_t off_10D0DC;

// sub_10D0BC @ 0x10d0bc, size 26 bytes
int  sub_10D0BC(int a1, int a2, int a3)
{
  int result; // r0
  uint32_t *v5; // r3

  result = sub_12E948(dword_10D0D8, a1, a3);
  v5 = off_10D0E0;
  *(uint32_t *)off_10D0DC = a1;
  *v5 = 0x1000000;
  return result;
}

