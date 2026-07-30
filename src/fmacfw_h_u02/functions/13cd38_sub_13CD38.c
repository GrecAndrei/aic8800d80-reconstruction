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

// sub_13CD38 @ 0x13cd38, size 374 bytes
unsigned int  sub_13CD38(int a1, unsigned int a2)
{
  unsigned int v2; // r2
  int v3; // nf
  unsigned int v5; // r3
  unsigned int v6; // r4
  int v7; // cf
  unsigned int v8; // r3
  unsigned int v9; // r3
  int v10; // cc
  uint16_t v11; // r3

  if ( (a2 & 0x2000) != 0 )
  {
    v2 = a2 & 0xF;
    switch ( (a2 >> 11) & 7 )
    {
      case 4u:
        if ( *(uint8_t *)(a1 + 176) > v2
          && (((int)*(uint16_t *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3u) + 7 > v2 )
        {
          a2 = a2 & 0xFFF0 | (uint16_t)(v2 + 1);
          if ( *(uint8_t *)(a1 + 181) )
            a2 |= 0x200u;
        }
        return a2;
      case 5u:
        if ( *(uint8_t *)(a1 + 176) > v2
          && 2 * (((int)*(uint16_t *)(a1 + 170) >> (2 * ((a2 >> 4) & 7))) & 3u) + 7 > v2 )
        {
          v3 = ((v2 + 1) & 0x4000 | a2 & 0x4000) != 0;
          a2 = (uint16_t)((v2 + 1) | a2 & 0xFFF0);
          if ( v3 )
          {
            if ( v2 != 1 )
              goto LABEL_29;
            return a2 & 0xBFFF;
          }
        }
        return a2;
      case 7u:
        if ( (a2 & 0x180) != 0 )
        {
          if ( ((a2 >> 7) & 3) == 1 )
            return a2 & 0xFE7F;
        }
        else if ( (a2 & 0xE) == 0 )
        {
          v3 = ((v2 + 1) & 0x4000 | a2 & 0x4000) != 0;
          a2 = (uint16_t)((v2 + 1) | a2 & 0xFFF0);
          if ( v3 && (v2 == 1 || !*(uint8_t *)(a1 + 195)) )
            return a2 & 0xBFFF;
          return a2;
        }
        v11 = a2 & 0xFFF0 | (v2 + 1) & 0xFFF0 | 5;
        a2 = v11;
        if ( (v11 & 0x4000) != 0 )
        {
LABEL_29:
          if ( *(uint8_t *)(a1 + 195) <= v2 )
            return a2 & 0xBFFF;
        }
        break;
      default:
        return a2;
    }
  }
  else if ( ((a2 >> 11) & 6) != 0 )
  {
    v9 = a2 & 7;
    while ( 1 )
    {
      v10 = *(uint8_t *)(a1 + 176) > v9;
      v9 = (uint8_t)(v9 + 1);
      if ( !v10 )
        break;
      if ( ((*(uint8_t *)(((a2 >> 3) & 3) + a1 + 170) >> v9) & 1) != 0 )
      {
        a2 = a2 & 0xFFFFFFF8 | v9;
        if ( *(uint8_t *)(a1 + 181) )
          return (uint16_t)a2 | 0x200;
        return a2;
      }
    }
  }
  else
  {
    v5 = a2 & 0x7F;
    if ( (a2 & 0x7C) != 0 )
    {
      v6 = *(uint8_t *)(a1 + 178);
    }
    else
    {
      v6 = *(uint8_t *)(a1 + 178);
      if ( v6 >= 3 )
        v6 = 3;
    }
    while ( 1 )
    {
      v7 = v5 >= v6;
      v5 = (uint8_t)(v5 + 1);
      if ( v7 )
        break;
      if ( ((*(uint16_t *)(a1 + 174) >> v5) & 1) != 0 )
        return a2 & 0xFFFFFF80 | v5;
    }
    v8 = *(uint8_t *)(a1 + 169);
    if ( v8 > 1 )
      return (uint16_t)((uint16_t)v8 << 11);
  }
  return a2;
}

