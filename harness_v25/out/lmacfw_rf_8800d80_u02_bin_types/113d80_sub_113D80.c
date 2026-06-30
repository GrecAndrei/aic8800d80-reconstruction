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

// sub_113D80 @ 0x113d80, size 120 bytes
int  sub_113D80(unsigned int a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r4

  if ( (sub_113A44(0xFu) & 0x10000) != 0 )
    return -2;
  v4 = sub_113A44(0xCu);
  if ( (uint16_t)sub_113A44(0xDu) | v4 )
  {
    v5 = sub_113A44(0xDu);
    if ( (HIWORD(v5) << 16) | sub_113A44(0xEu) )
    {
      return -1;
    }
    else
    {
      sub_113AD0(0xDu, a1 << 16);
      sub_113AD0(0xEu, HIWORD(a1) | (a2 << 16));
      return 0;
    }
  }
  else
  {
    sub_113AD0(0xCu, a1);
    sub_113AD0(0xDu, a2);
    return 1;
  }
}

