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

// sub_113C14 @ 0x113c14, size 50 bytes
int  sub_113C14(int a1)
{
  unsigned int v2; // r0
  char v3; // r1
  int v4; // r4

  v2 = sub_113A44(6u);
  if ( (v2 & 0xFF0000) == 0 )
  {
    v3 = 16;
    v4 = 1;
LABEL_3:
    sub_113AD0(6u, a1 << v3);
    return v4;
  }
  v4 = HIBYTE(v2);
  if ( !HIBYTE(v2) )
  {
    v3 = 24;
    goto LABEL_3;
  }
  return -1;
}

