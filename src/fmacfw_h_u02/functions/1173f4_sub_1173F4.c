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

// phy_sleep_prepare @ 0x1173f4, size 48 bytes
int  phy_sleep_prepare(int a1)
{
  int v1; // r4
  int v2; // r5
  int v3; // r0
  int result; // r0
  int v5; // [sp+4h] [bp-8h]

  v1 = a1 + 1272;
  v2 = 0;
  do
  {
    v3 = (uint8_t)v2;
    v5 = (uint8_t)v2++;
    phy_dispatch(v3, v1, 0);
    result = phy_dispatch(v5, v1 - 40, 0);
    v1 += 8;
  }
  while ( v2 != 5 );
  return result;
}

