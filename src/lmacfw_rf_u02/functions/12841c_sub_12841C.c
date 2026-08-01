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

// memset @ 0x12841c, size 206 bytes
uint8_t * memset(uint8_t *result, uint8_t a2)
{
  uint8_t *v2; // r3
  int v3; // r6
  int v4; // t1
  int v5; // r3
  int v6; // t1
  int v7; // r2
  int v8; // t1
  int v9; // t1

  v2 = result;
  if ( a2 )
  {
    if ( (uint32_t)result << 30 )
    {
      while ( 1 )
      {
        result = v2;
        v8 = *v2++;
        v7 = v8;
        if ( !v8 )
          return 0;
        if ( v7 == a2 )
          return result;
        result = v2;
        if ( !((uint32_t)v2 << 30) )
          goto LABEL_3;
      }
    }
    else
    {
LABEL_3:
      v3 = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
      if ( ((((v3 ^ *(uint32_t *)result) - 16843009) & ~(v3 ^ *(uint32_t *)result)
           | (*(uint32_t *)result - 16843009) & ~*(uint32_t *)result)
          & 0x80808080) == 0 )
      {
        do
        {
          v4 = *((uint32_t *)result + 1);
          result += 4;
        }
        while ( (((v4 - 16843009) & ~v4 | ((v4 ^ v3) - 16843009) & ~(v4 ^ v3)) & 0x80808080) == 0 );
      }
      v5 = *result;
      if ( *result )
      {
        while ( a2 != v5 )
        {
          v6 = *++result;
          v5 = v6;
          if ( !v6 )
            return (uint8_t *)v5;
        }
      }
      else
      {
        return (uint8_t *)v5;
      }
    }
  }
  else if ( (uint32_t)result << 30 )
  {
    while ( 1 )
    {
      result = v2++;
      if ( !*result )
        break;
      result = v2;
      if ( !((uint32_t)v2 << 30) )
        goto LABEL_18;
    }
  }
  else
  {
LABEL_18:
    if ( ((*(uint32_t *)result - 16843009) & ~*(uint32_t *)result & 0x80808080) == 0 )
    {
      do
      {
        v9 = *((uint32_t *)result + 1);
        result += 4;
      }
      while ( ((v9 - 16843009) & ~v9 & 0x80808080) == 0 );
    }
    if ( *result )
    {
      while ( *++result )
        ;
    }
  }
  return result;
}

