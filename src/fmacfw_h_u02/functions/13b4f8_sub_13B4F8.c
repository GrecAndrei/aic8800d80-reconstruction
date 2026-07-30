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

extern uint32_t dword_13B530;
extern uint32_t dword_13B52C;

// sub_13B4F8 @ 0x13b4f8, size 50 bytes
int  sub_13B4F8(int a1, int a2, unsigned int a3)
{
  if ( sub_12CD48(a3) == 2 )
  {
    sub_13B8E4(a3 >> 8);
    sub_12D108(dword_13B530, (uint32_t *)(dword_13B52C + 32 * (a3 >> 8)));
    sub_12CBF4(a3, 0);
  }
  return 0;
}

