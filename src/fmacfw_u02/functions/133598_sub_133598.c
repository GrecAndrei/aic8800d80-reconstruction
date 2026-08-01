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

extern uint32_t off_13245C;

// null_sub @ 0x133598, size 22 bytes
int  null_sub(int result, int a2, int a3, uint8_t *a4)
{
  unsigned int v4; // r4
  unsigned int v5; // r2
  int v6; // r1
  unsigned int v7; // r2
  int16_t v8; // r1
  int v9; // r1

  if ( (unsigned int)(result - 1) > 2 )
    return result;
  v4 = *a4;
  if ( *a4 )
  {
    if ( v4 == 1 )
    {
      if ( (uint8_t)(a2 - 1) > 0xB0u )
        v4 = 0;
      else
        v4 = 5 * a2 + 5000;
      *((uint16_t *)a4 + 2) = v4;
      if ( (uint8_t)(a3 - 1) <= 0xB0u )
      {
        v5 = 5 * a3 + 5000;
LABEL_15:
        *((uint16_t *)a4 + 3) = v5;
        if ( result != 2 )
        {
          if ( result != 3 )
          {
            if ( v5 < v4 )
            {
              v6 = v4 - v5;
              goto LABEL_19;
            }
            v9 = v5;
LABEL_36:
            v6 = v9 - v4;
LABEL_19:
            if ( v6 != 40 )
            {
              if ( v6 > 40 && *((uint8_t *)off_13245C + 373) == 4 )
                goto LABEL_22;
              goto LABEL_27;
            }
            if ( *((uint8_t *)off_13245C + 373) > 2u )
            {
              *((uint16_t *)a4 + 2) = v5;
              a4[1] = 3;
              *((uint16_t *)a4 + 3) = 0;
              return 3;
            }
LABEL_27:
            a4[1] = 2;
            *((uint16_t *)a4 + 3) = 0;
            return result;
          }
          goto LABEL_26;
        }
        goto LABEL_28;
      }
    }
    else
    {
      *((uint16_t *)a4 + 2) = 0;
      v4 = 0;
    }
  }
  else
  {
    if ( (unsigned int)(a2 - 1) <= 0xD )
    {
      if ( a2 == 14 )
        v4 = 2484;
      else
        v4 = 5 * a2 + 2407;
    }
    *((uint16_t *)a4 + 2) = v4;
    if ( a3 && a3 <= 14 )
    {
      if ( a3 == 14 )
      {
        v9 = 2484;
        *((uint16_t *)a4 + 3) = 2484;
        if ( result != 2 )
        {
          if ( result != 3 )
          {
            LOWORD(v5) = 2484;
            goto LABEL_36;
          }
LABEL_26:
          if ( *((uint8_t *)off_13245C + 373) == 4 )
          {
LABEL_22:
            a4[1] = 4;
            return result;
          }
          goto LABEL_27;
        }
        goto LABEL_28;
      }
      v5 = 5 * a3 + 2407;
      goto LABEL_15;
    }
  }
  *((uint16_t *)a4 + 3) = 0;
  if ( result != 2 )
  {
    if ( result != 3 )
      goto LABEL_27;
    goto LABEL_26;
  }
LABEL_28:
  if ( *((uint8_t *)off_13245C + 373) <= 2u )
  {
    v7 = *((uint16_t *)a4 + 1);
    a4[1] = 2;
    if ( v7 <= v4 )
      v8 = v4 - 40;
    else
      v8 = v4 + 40;
    *((uint16_t *)a4 + 2) = v8;
  }
  else
  {
    a4[1] = 3;
  }
  return result;
}

