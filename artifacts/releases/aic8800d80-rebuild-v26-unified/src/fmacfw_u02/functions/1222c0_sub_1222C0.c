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

extern uint32_t off_1222EC;
extern uint32_t dword_1222F0;

// sub_1222C0 @ 0x1222c0, size 42 bytes
int sub_1222C0()
{
  uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = off_1222EC;
  result = dword_1222F0;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}

