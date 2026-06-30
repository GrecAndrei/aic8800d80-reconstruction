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

extern uint32_t dword_12B3D0;

// sub_12B3A4 @ 0x12b3a4, size 40 bytes
int  sub_12B3A4(char a1, int a2)
{
  uint8_t *v3; // r4

  v3 = (uint8_t *)sub_12C7EC(2052, a2, 2, 1);
  sub_12EB90(4, dword_12B3D0);
  *v3 = a1;
  return sub_12C84C(v3);
}

