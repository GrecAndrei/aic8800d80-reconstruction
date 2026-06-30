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

extern uint32_t dword_13B4F4;
extern uint32_t dword_13B4F0;
extern uint32_t dword_13B4EC;

// sub_13B4C0 @ 0x13b4c0, size 42 bytes
int  sub_13B4C0(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( sub_12CD48(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B4F4;
    else
      v4 = dword_13B4F0;
    sub_12D108(v4, (uint32_t *)(dword_13B4EC + 32 * (a3 >> 8)));
  }
  return 0;
}

