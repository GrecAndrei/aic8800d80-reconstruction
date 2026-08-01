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

extern uint32_t dword_1383DC;

// parse_pdu_data @ 0x138378, size 98 bytes
uint8_t * parse_pdu_data(uint8_t *a1)
{
  uint8_t *v1; // r4
  uint8_t *v3; // r8
  int v4; // r6
  int v5; // r5
  uint8_t *v6; // r9
  int v7; // r2

  if ( !*a1 )
    return (uint8_t *)*a1;
  v1 = (uint8_t *)dword_1383DC;
  v3 = 0;
  v4 = dword_1383DC + 3840;
  v5 = -128;
  v6 = a1 + 1;
  while ( v1[8] )
  {
    if ( (char)v1[64] <= v5 || (v7 = *a1, v7 != (uint8_t)v1[16]) || memcpy(v1 + 17, v6, v7) )
    {
      v1 += 60;
      if ( v1 == (uint8_t *)v4 )
        return v3;
    }
    else
    {
      v5 = (char)v1[64];
      v3 = v1 + 8;
      v1 += 60;
      if ( v1 == (uint8_t *)v4 )
        return v3;
    }
  }
  return v3;
}

