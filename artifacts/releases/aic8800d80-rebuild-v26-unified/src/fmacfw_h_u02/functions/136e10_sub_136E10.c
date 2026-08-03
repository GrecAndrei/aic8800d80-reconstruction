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

extern uint32_t dword_136E40;

// sub_136E10 @ 0x136e10, size 48 bytes
int  sub_136E10(int a1, int a2, int a3, int16_t a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)sub_12C7EC(4104, a4, 4, 2u);
  sub_12EB90(8, dword_136E40);
  *v5 = 1;
  v5[1] = *(uint8_t *)(a2 + 2);
  sub_12C84C((int)v5);
  return 0;
}

