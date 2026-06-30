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

// sub_122124 @ 0x122124, size 94 bytes
int  sub_122124(uint8_t *a1, int a2)
{
  int v2; // r3
  int result; // r0
  char v5; // r2
  int v6; // r6
  char v7; // r5
  uint8_t *v8; // r0

  v2 = (char)a1[143];
  result = (char)a1[142];
  v5 = a1[144];
  v6 = (uint8_t)a1[145];
  a1[142] = a2;
  if ( v2 )
  {
    v7 = a2;
    if ( v6 )
    {
      if ( v6 != 1 || result >= a2 || a2 <= v2 + v5 )
        goto LABEL_7;
      LOBYTE(v6) = 0;
    }
    else
    {
      if ( result <= a2 || a2 >= v2 - v5 )
        goto LABEL_7;
      LOBYTE(v6) = 1;
    }
    v8 = (uint8_t *)sub_12C92C(87, 13, 0, 3);
    *v8 = a1[107];
    v8[1] = v6;
    v8[2] = v7;
    result = sdio_buffer_prepare_n_4e8(v8);
LABEL_7:
    a1[145] = v6;
  }
  return result;
}

