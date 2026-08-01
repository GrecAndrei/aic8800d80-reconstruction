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

extern uint32_t dword_11ACEC;

// mmio_status_read @ 0x11ac78, size 116 bytes
unsigned int * mmio_status_read(unsigned int *result, unsigned int *a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r5
  int v4; // r2
  int v5; // r5
  unsigned int v6; // r3
  int v7; // r2

  v2 = *result;
  if ( (*result & 0x1C000) == 0 )
  {
    if ( (v2 & 0x2000) != 0 )
      v3 = *result & 0xF;
    else
      v3 = *result & 7;
    v4 = (v2 >> 11) & 6;
    if ( v4 )
    {
      if ( v3 >= 3 )
        v4 = 0x100000;
      else
        v4 = 0x80000;
      if ( v3 >= 3 )
        v5 = 8;
      else
        v5 = 4;
    }
    else if ( v3 > 3 )
    {
      v4 = 0x80000;
      v5 = 4;
    }
    else
    {
      v5 = 0;
    }
    *result = v4 | (((v2 >> 7) & 3) << 24) | v2 & 0xE0003FFF | 0x4008000;
    v6 = *a2 & 0xFFFF00FF;
    v7 = dword_11ACEC + v5;
    *a2 = v6;
    *a2 = v6 | (*(char *)(v7 + 198) << 8);
  }
  return result;
}

