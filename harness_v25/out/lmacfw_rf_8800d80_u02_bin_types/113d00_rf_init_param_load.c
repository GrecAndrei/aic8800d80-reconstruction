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

// rf_init_param_load @ 0x113d00, size 128 bytes
// Doc: rf_init_param_load [rf]: Loads RF parameter via helper and extracts bit fields
// rf_init_param_load [rf]: Loads RF parameter via helper and extracts bit fields
int  rf_init_param_load(int *a1, unsigned int *a2)
{
  unsigned int v4; // r0
  int v5; // r4
  int result; // r0
  unsigned int v7; // r7
  unsigned int v8; // r0
  unsigned int v9; // r7
  int v10; // r7
  unsigned int v11; // r0

  v4 = sub_113A44(0xFu);
  v5 = HIWORD(v4) & 1;
  if ( (v4 & 0x10000) != 0 )
  {
    result = sub_113C48(a1, a2);
    if ( result <= 1 )
      *a1 = *a1 & 0xFFFFFF00 | (uint8_t)(*a1 + 1);
  }
  else
  {
    v7 = sub_113A44(0xDu);
    v8 = sub_113A44(0xEu);
    v9 = HIWORD(v7) << 16;
    if ( v9 | v8 )
    {
      v10 = (v8 << 16) | HIWORD(v9);
      v11 = HIWORD(v8);
    }
    else
    {
      v10 = sub_113A44(0xCu);
      v11 = (uint16_t)sub_113A44(0xDu);
      if ( v10 )
      {
        v5 = 1;
      }
      else if ( (uint16_t)v11 )
      {
        v5 = 1;
      }
      else
      {
        v5 = 2;
      }
    }
    *a1 = v10;
    *a2 = v11;
    return v5;
  }
  return result;
}

