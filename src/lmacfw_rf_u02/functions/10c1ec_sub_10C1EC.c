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


extern uint32_t off_10C2DC;
extern uint32_t off_10C2E0;

// sub_10C1EC @ 0x10c1ec, size 238 bytes
int  sub_10C1EC(int a1, int a2, int a3, int a4, uint8_t a5, uint8_t a6)
{
  int result; // r0
  uint32_t *v10; // r10
  uint32_t *v11; // r11

  sub_101E18(a1, a2, a2, 0, 0, 0);
  if ( a1 == 1 )
  {
    v10 = off_10C2DC;
    v11 = off_10C2E0;
    *(uint32_t *)off_10C2DC &= ~0x400u;
    *v11 |= 0x8000000u;
    sub_102E04(1);
    sub_10BF28((unsigned int *)a3, a4, a5, a6);
    if ( a5 )
    {
      sub_102BB0(28, (uint16_t *)a4);
      *v11 &= ~0x8000000u;
      *v10 |= 0x400u;
      sub_102E04(0);
      sub_10BF28((unsigned int *)a3, a4, a5, a6);
      return sub_102BB0(28, (uint16_t *)a4);
    }
    else
    {
      *v11 &= ~0x8000000u;
      *v10 |= 0x400u;
      sub_102E04(0);
      return (int)sub_10BF28((unsigned int *)a3, a4, 0, a6);
    }
  }
  else
  {
    result = (int)sub_10BF28((unsigned int *)a3, a4, a5, a6);
    if ( a5 )
      return sub_102BB0(3, (uint16_t *)a4);
  }
  return result;
}
