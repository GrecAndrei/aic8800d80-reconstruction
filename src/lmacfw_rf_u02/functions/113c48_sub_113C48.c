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

// mmio_read_pair @ 0x113c48, size 78 bytes
int  mmio_read_pair(int *a1, unsigned int *a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r3
  int v8; // r4
  int result; // r0
  uint16_t v10; // r0

  v4 = mmio_read32(8u);
  v5 = mmio_read32(9u);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    v7 = HIWORD(v5);
    v8 = (v5 << 16) | HIWORD(v6);
    result = 0;
  }
  else
  {
    v8 = mmio_read32(7u);
    v10 = mmio_read32(8u);
    v7 = v10;
    if ( v8 )
    {
      result = 1;
    }
    else if ( v10 )
    {
      result = 1;
    }
    else
    {
      result = 2;
    }
  }
  *a1 = v8;
  *a2 = v7;
  return result;
}

