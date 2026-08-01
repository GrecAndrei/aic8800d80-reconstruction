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

// rf_cmd_8_write @ 0x114784, size 90 bytes
int  rf_cmd_8_write(uint32_t *a1, unsigned int *a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  int v7; // r4
  uint16_t v8; // r0
  unsigned int v9; // r3
  int result; // r0

  v4 = MEMORY[0x1FC](8);
  v5 = MEMORY[0x1FC](9);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    *a1 = (v5 << 16) | HIWORD(v6);
    *a2 = HIWORD(v5);
    return 0;
  }
  else
  {
    v7 = MEMORY[0x1FC](7);
    v8 = MEMORY[0x1FC](8);
    v9 = v8;
    if ( v7 )
    {
      *a1 = v7;
      *a2 = v8;
      return 1;
    }
    else
    {
      *a1 = 0;
      if ( v8 )
        result = 1;
      else
        result = 2;
      *a2 = v9;
    }
  }
  return result;
}

