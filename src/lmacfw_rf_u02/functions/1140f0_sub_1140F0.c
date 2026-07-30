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

// sub_1140F0 @ 0x1140f0, size 76 bytes
int  sub_1140F0(int a1)
{
  uint8_t v2; // r0
  char v3; // r1
  int v4; // r4
  int v6; // r5

  v2 = sub_113A44(0x10u);
  v3 = v2 & 0xF;
  if ( (v2 & 0xF) != 0 )
  {
    v4 = v2 >> 4;
    if ( v4 )
      return -1;
    v3 = 4;
  }
  else
  {
    v4 = 1;
  }
  if ( (unsigned int)(a1 + 7) > 0xF )
    return v4 + 1;
  if ( a1 <= 0 )
    v6 = -a1;
  else
    v6 = (a1 - 1) | 8;
  host_reg_wait_set(0x10u, v6 << v3);
  return v4;
}

