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

// sub_13D518 @ 0x13d518, size 206 bytes
int  sub_13D518(int a1)
{
  char v1; // r5
  unsigned int v2; // r3
  int result; // r0
  int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r3
  int v8; // r2

  v1 = *(uint8_t *)(a1 + 166);
  v2 = *(uint8_t *)(a1 + 177);
  *(uint8_t *)(a1 + 166) = v1 & 0xFB;
  if ( v2 > 0xB )
    goto LABEL_11;
  result = ((int)*(uint16_t *)(a1 + 12 * *(uint16_t *)(a1 + 136) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = ((int)*(uint16_t *)(a1 + 12 * *(uint16_t *)(a1 + 138) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = ((int)*(uint16_t *)(a1 + 12 * *(uint16_t *)(a1 + 140) + 10) >> 11) & 6;
  if ( !result )
    return result;
  result = v1 & 0x20;
  if ( (v1 & 0x20) != 0 )
  {
LABEL_11:
    *(uint8_t *)(a1 + 166) = v1 & 0xFB | 4;
    return 1;
  }
  v5 = a1 + 12 * *(uint16_t *)(a1 + 2 * (*(uint8_t *)(a1 + 168) + 68));
  v6 = *(uint16_t *)(v5 + 10);
  if ( (v6 & 0x2000) != 0 )
  {
    if ( (v6 & 0xF) > 2 )
      goto LABEL_9;
    v8 = (v6 >> 4) & 7;
  }
  else
  {
    if ( ((v6 >> 11) & 6) == 0 )
    {
      if ( (v6 & 0x7F) > 2 )
      {
LABEL_9:
        v7 = *(uint16_t *)(v5 + 8);
        goto LABEL_10;
      }
      goto LABEL_16;
    }
    if ( (v6 & 7) > 2 )
      goto LABEL_9;
    v8 = (v6 >> 3) & 3;
  }
  if ( v8 )
    goto LABEL_9;
LABEL_16:
  v7 = *(uint16_t *)(v5 + 8);
  if ( v7 > 0x1998 )
  {
LABEL_10:
    if ( v7 <= 0x28E )
      return result;
    goto LABEL_11;
  }
  return result;
}

