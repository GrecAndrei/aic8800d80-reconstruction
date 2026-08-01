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

// rx_status_shift @ 0x1052e8, size 154 bytes
int  rx_status_shift(int a1, float a2, int *a3, int a4, int a5)
{
  int result; // r0
  int v7; // r3
  int v8; // r1
  float v9; // s14
  int v10; // r1
  int v11; // r3
  int v12; // r3
  int v13; // r1
  float v14; // s14

  result = a3[2];
  a3[1] = result;
  if ( a5 )
  {
    if ( result >= 0 )
    {
      v7 = a4 + 4 * (result + 33);
      v8 = result;
      while ( 1 )
      {
        v9 = *(float *)(v7 - 4);
        v7 -= 4;
        --v8;
        if ( v9 < a2 )
          break;
        a3[1] = v8;
        if ( v8 == -1 )
          goto LABEL_22;
      }
LABEL_6:
      v10 = a3[1];
      v11 = v10 + 1;
      goto LABEL_7;
    }
  }
  else if ( result >= 0 )
  {
    v12 = a4 + 4 * (result + 1);
    v13 = result;
    while ( 1 )
    {
      v14 = *(float *)(v12 - 4);
      v12 -= 4;
      --v13;
      if ( v14 < a2 )
        goto LABEL_6;
      a3[1] = v13;
      if ( v13 == -1 )
      {
LABEL_22:
        *a3 = 0;
        goto LABEL_23;
      }
    }
  }
  v11 = result + 1;
  v10 = result;
LABEL_7:
  if ( result >= v11 )
  {
    *a3 = v11;
  }
  else
  {
    v11 = result;
    *a3 = result;
  }
  if ( v11 < 0 )
    *a3 = 0;
  if ( result < v10 )
    a3[1] = result;
  else
    result = v10;
  if ( result < 0 )
LABEL_23:
    a3[1] = 0;
  return result;
}

