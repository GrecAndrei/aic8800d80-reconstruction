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

extern uint32_t off_12DAB8;
extern uint32_t dword_12DAC0;
extern uint32_t dword_12DABC;

// memcpy_loop @ 0x12da54, size 100 bytes
uint8_t * memcpy_loop(uint8_t *a1, int a2, int a3, uint16_t *a4)
{
  unsigned int v4; // r7
  unsigned int v5; // r12
  int v6; // r6
  int v7; // r4
  uint8_t *v8; // r5

  v4 = (unsigned int)&a1[a2];
  v5 = (unsigned int)&a1[a2];
  if ( a1 < &a1[a2] )
  {
    while ( 1 )
    {
      v8 = a1;
      if ( v4 <= (unsigned int)(a1 + 1) )
        break;
      v6 = *a1;
      v7 = a1[1] + 2;
      a1 += v7;
      if ( v6 == 255 )
      {
        if ( v4 < (unsigned int)a1 )
          return 0;
        *a4 = v7;
        if ( !v8 || (unsigned int)(v8 + 3) > v5 )
          return 0;
        if ( v8[2] == a3 )
          return v8;
        a2 = (uint16_t)(a2 - v7);
        if ( v5 <= (unsigned int)a1 )
          goto LABEL_13;
        v4 = (unsigned int)&a1[a2];
      }
    }
  }
  else
  {
LABEL_13:
    if ( **(int16_t **)off_12DAB8 < 0 && (uint8_t *)v5 != a1 )
      mmio_field_update(dword_12DAC0, dword_12DABC, 127);
  }
  return 0;
}

