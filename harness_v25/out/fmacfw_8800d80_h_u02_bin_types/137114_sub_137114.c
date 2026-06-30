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

// sub_137114 @ 0x137114, size 628 bytes
uint8_t * sub_137114(uint8_t *result, int a2, char a3, int a4)
{
  uint8_t *v5; // r6
  uint8_t *v7; // r0
  uint8_t *v8; // r4
  int v9; // r6
  int v10; // r8
  int v11; // r6
  unsigned int *i; // r4
  unsigned int *v13; // r4
  int v14; // r7
  int v15; // t1
  int v16; // r6
  int v17; // r2
  unsigned int *v18; // r3
  int v19; // r2
  uint8_t *v20; // r0
  uint8_t *v21; // r4
  int v22; // r6
  unsigned int v23; // r0
  int v24; // r8
  int v25; // r6
  unsigned int *j; // r4
  unsigned int *v27; // r7
  int v28; // r8
  unsigned int v29; // r4
  int v30; // r7
  int v31; // r4
  unsigned int *v32; // r6
  unsigned int *v33; // r6
  int v34; // r8
  int v35; // t1
  int v36; // r4
  uint8_t v37; // [sp+7h] [bp-1h] BYREF

  *(uint32_t *)(a4 + 48) = 0;
  *(uint32_t *)(a4 + 52) = 0;
  if ( (a3 & 0x10) == 0 )
  {
    *(uint32_t *)(a4 + 48) = 1;
    return result;
  }
  v5 = result;
  v7 = sub_12D854(result, a2, &v37);
  v8 = v7;
  if ( v7 )
  {
    v9 = v37;
    result = (uint8_t *)sub_12DF40(bswap32(*((uint32_t *)v7 + 1)));
    if ( result )
    {
      result = (uint8_t *)((1 << (char)result) | *(uint16_t *)(a4 + 52));
      *(uint16_t *)(a4 + 52) = (uint16_t)result;
    }
    v10 = *((uint16_t *)v8 + 4);
    v11 = v9 - 8;
    for ( i = (unsigned int *)(v8 + 10); v10 && v11 > 3; --v10 )
    {
      result = (uint8_t *)sub_12DF40(bswap32(*i));
      v11 -= 4;
      ++i;
      if ( result )
      {
        result = (uint8_t *)((1 << (char)result) | *(uint16_t *)(a4 + 54));
        *(uint16_t *)(a4 + 54) = (uint16_t)result;
      }
    }
    if ( v11 > 1 )
    {
      v15 = *(uint16_t *)i;
      v13 = (unsigned int *)((char *)i + 2);
      v14 = v15;
      v16 = v11 - 2;
      if ( v15 && v16 > 3 )
      {
        while ( 1 )
        {
          result = (uint8_t *)sub_12DE94((char *)bswap32(*v13));
          v16 -= 4;
          ++v13;
          if ( result )
          {
            result = (uint8_t *)((1 << (char)result) | *(uint32_t *)(a4 + 48));
            *(uint32_t *)(a4 + 48) = result;
          }
          if ( !--v14 )
            break;
          if ( v16 <= 3 )
          {
            if ( v16 <= 1 || (*(uint16_t *)v13 & 0xC0) == 0 )
              return result;
            goto LABEL_69;
          }
        }
      }
      if ( v16 > 1 )
      {
        v17 = v16 - 2;
        v18 = (unsigned int *)((char *)v13 + 2);
        if ( v16 - 2 > 1 )
        {
          v19 = *(uint16_t *)v18;
          v18 = &v13[4 * v19 + 1];
          v17 = v16 - 4 - 16 * v19;
        }
        if ( (*(uint16_t *)v13 & 0xC0) != 0 )
        {
          if ( v17 <= 3 )
          {
LABEL_69:
            *(uint16_t *)(a4 + 52) |= 0x20u;
            return result;
          }
          result = (uint8_t *)sub_12DF40(bswap32(*v18));
          if ( result )
LABEL_28:
            *(uint16_t *)(a4 + 52) |= 1 << (char)result;
        }
      }
    }
  }
  else
  {
    v20 = sub_12D890(v5, a2, &v37);
    v21 = v20;
    if ( v20 )
    {
      v22 = v37;
      v23 = bswap32(*((uint32_t *)v20 + 2));
      *(uint32_t *)(a4 + 48) = 2;
      result = (uint8_t *)sub_12DF40(v23);
      if ( result )
      {
        result = (uint8_t *)((1 << (char)result) | *(uint16_t *)(a4 + 52));
        *(uint16_t *)(a4 + 52) = (uint16_t)result;
      }
      v24 = *((uint16_t *)v21 + 6);
      v25 = v22 - 12;
      for ( j = (unsigned int *)(v21 + 14); v24 && v25 > 3; --v24 )
      {
        result = (uint8_t *)sub_12DF40(bswap32(*j));
        v25 -= 4;
        ++j;
        if ( result )
        {
          result = (uint8_t *)((1 << (char)result) | *(uint16_t *)(a4 + 54));
          *(uint16_t *)(a4 + 54) = (uint16_t)result;
        }
      }
      if ( v25 > 1 )
      {
        v27 = (unsigned int *)((char *)j + 2);
        v28 = *(uint16_t *)j;
        if ( *(uint16_t *)j )
        {
          if ( v25 > 5 )
          {
            v29 = (unsigned int)j + ((v25 - 6) & 0xFFFFFFFC) + 6;
            do
            {
              result = (uint8_t *)sub_12DE94((char *)bswap32(*v27++));
              if ( result )
              {
                result = (uint8_t *)((1 << (char)result) | *(uint32_t *)(a4 + 48));
                *(uint32_t *)(a4 + 48) = result;
              }
              --v28;
            }
            while ( v28 && v27 != (unsigned int *)v29 );
          }
        }
      }
    }
    else
    {
      result = sub_12D8BC(v5, a2, &v37);
      if ( !result )
      {
        *(uint32_t *)(a4 + 48) = 2;
        *(uint16_t *)(a4 + 52) = 1;
        return result;
      }
      v30 = *((uint16_t *)result + 2);
      v31 = v37 - 4;
      v32 = (unsigned int *)(result + 6);
      if ( *((uint16_t *)result + 2) && v31 > 3 )
      {
        do
        {
          result = (uint8_t *)sub_12DE94((char *)bswap32(*v32));
          v31 -= 4;
          ++v32;
          if ( result )
          {
            result = (uint8_t *)((1 << (char)result) | *(uint32_t *)(a4 + 48));
            *(uint32_t *)(a4 + 48) = result;
          }
          --v30;
        }
        while ( v30 && v31 > 3 );
      }
      if ( v31 > 1 )
      {
        v35 = *(uint16_t *)v32;
        v33 = (unsigned int *)((char *)v32 + 2);
        v34 = v35;
        v36 = v31 - 2;
        if ( v35 )
        {
          if ( v36 <= 3 )
            return result;
          while ( 1 )
          {
            result = (uint8_t *)sub_12DF40(bswap32(*v33));
            v36 -= 4;
            ++v33;
            if ( result )
            {
              result = (uint8_t *)((1 << (char)result) | *(uint16_t *)(a4 + 54));
              *(uint16_t *)(a4 + 54) = (uint16_t)result;
            }
            if ( !--v34 )
              break;
            if ( v36 <= 3 )
              return result;
          }
        }
        if ( v36 > 3 )
        {
          result = (uint8_t *)sub_12DF40(bswap32(*v33));
          if ( result )
            goto LABEL_28;
        }
      }
    }
  }
  return result;
}

