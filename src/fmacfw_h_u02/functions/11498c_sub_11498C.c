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

// sub_11498C @ 0x11498c, size 58 bytes
int  sub_11498C(int *a1)
{
  uint8_t v2; // r0
  int v3; // r2
  int result; // r0
  int v5; // r3

  v2 = MEMORY[0x1FC](16);
  v3 = v2 >> 4;
  if ( (v2 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v2 )
    {
      *a1 = 0;
      return 2;
    }
    v3 = v2;
    result = 1;
  }
  if ( (v3 & 8) != 0 )
    v5 = v3 & 7;
  else
    v5 = -v3;
  if ( (v3 & 8) != 0 )
    ++v5;
  *a1 = v5;
  return result;
}

