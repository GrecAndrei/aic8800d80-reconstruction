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

extern uint32_t off_132D84;
extern uint32_t off_13245C;

// scan_interval_update @ 0x132d18, size 106 bytes
// Doc: scan_interval_update [util]: Clear/reset a 16-bit state structure fields
// scan_interval_update [util]: Clear/reset a 16-bit state structure fields
int  scan_interval_update(int result, uint8_t *a2, int a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r2
  int v5; // r1
  unsigned int v6; // r2
  int16_t v7; // r1
  int v8; // r1
  int16_t v9; // r4
  int16_t v10; // r3
  uint8_t *v11; // r3
  int v12; // r2
  int v13; // r1

  v9 = *(uint16_t *)(a3 + 166);
  *(uint16_t *)(a3 + 168) = v9;
  *(uint8_t *)(a3 + 165) = 0;
  *(uint16_t *)(a3 + 170) = 0;
  if ( result )
  {
    if ( !*((uint8_t *)off_132D84 + 373) )
      return result;
    if ( (*(uint8_t *)(result + 3) & 3) != 0 )
    {
      v10 = -10;
      if ( (*(uint8_t *)(result + 3) & 3) == 1 )
        v10 = 10;
      *(uint16_t *)(a3 + 168) = v9 + v10;
      *(uint8_t *)(a3 + 165) = 1;
    }
  }
  if ( a2 )
  {
    if ( *((uint8_t *)off_132D84 + 373) > 1u )
    {
      result = a2[2] & 3;
      if ( (unsigned int)(result - 1) <= 2 )
      {
        v11 = (uint8_t *)(a3 + 164);
        v12 = (uint8_t)a2[4];
        v13 = (uint8_t)a2[3];
        v3 = *v11;
        if ( *v11 )
        {
          if ( v3 == 1 )
          {
            if ( (uint8_t)(v13 - 1) > 0xB0u )
              v3 = 0;
            else
              v3 = 5 * v13 + 5000;
            *((uint16_t *)v11 + 2) = v3;
            if ( (uint8_t)(v12 - 1) <= 0xB0u )
            {
              v4 = 5 * v12 + 5000;
LABEL_25:
              *((uint16_t *)v11 + 3) = v4;
              if ( result != 2 )
              {
                if ( result != 3 )
                {
                  if ( v4 < v3 )
                  {
                    v5 = v3 - v4;
                    goto LABEL_29;
                  }
                  v8 = v4;
LABEL_46:
                  v5 = v8 - v3;
LABEL_29:
                  if ( v5 != 40 )
                  {
                    if ( v5 > 40 && *((uint8_t *)off_13245C + 373) == 4 )
                      goto LABEL_32;
                    goto LABEL_37;
                  }
                  if ( *((uint8_t *)off_13245C + 373) > 2u )
                  {
                    *((uint16_t *)v11 + 2) = v4;
                    v11[1] = 3;
                    *((uint16_t *)v11 + 3) = 0;
                    return 3;
                  }
LABEL_37:
                  v11[1] = 2;
                  *((uint16_t *)v11 + 3) = 0;
                  return result;
                }
                goto LABEL_36;
              }
              goto LABEL_38;
            }
          }
          else
          {
            *((uint16_t *)v11 + 2) = 0;
            v3 = 0;
          }
        }
        else
        {
          if ( (unsigned int)(v13 - 1) <= 0xD )
          {
            if ( v13 == 14 )
              v3 = 2484;
            else
              v3 = 5 * v13 + 2407;
          }
          *((uint16_t *)v11 + 2) = v3;
          if ( v12 && v12 <= 14 )
          {
            if ( v12 == 14 )
            {
              v8 = 2484;
              *((uint16_t *)v11 + 3) = 2484;
              if ( result != 2 )
              {
                if ( result != 3 )
                {
                  LOWORD(v4) = 2484;
                  goto LABEL_46;
                }
LABEL_36:
                if ( *((uint8_t *)off_13245C + 373) == 4 )
                {
LABEL_32:
                  v11[1] = 4;
                  return result;
                }
                goto LABEL_37;
              }
              goto LABEL_38;
            }
            v4 = 5 * v12 + 2407;
            goto LABEL_25;
          }
        }
        *((uint16_t *)v11 + 3) = 0;
        if ( result != 2 )
        {
          if ( result != 3 )
            goto LABEL_37;
          goto LABEL_36;
        }
LABEL_38:
        if ( *((uint8_t *)off_13245C + 373) <= 2u )
        {
          v6 = *((uint16_t *)v11 + 1);
          v11[1] = 2;
          if ( v6 <= v3 )
            v7 = v3 - 40;
          else
            v7 = v3 + 40;
          *((uint16_t *)v11 + 2) = v7;
        }
        else
        {
          v11[1] = 3;
        }
      }
    }
  }
  return result;
}

