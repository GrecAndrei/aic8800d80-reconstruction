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

// parse_hex_or_dec @ 0x12f958, size 172 bytes
int  parse_hex_or_dec(uint8_t *a1, uint32_t *a2, unsigned int a3)
{
  int v3; // r5
  int v4; // r7
  int i; // r6
  unsigned int v6; // r3
  int v8; // t1
  int v9; // r3
  int v10; // r3

  v3 = *a1;
  if ( v3 == 48 )
  {
    v3 = a1[1];
    if ( (unsigned int)(v3 - 65) > 0x19 )
      v9 = a1[1];
    else
      v9 = (uint8_t)(v3 + 32);
    if ( v9 == 120 && ((v10 = a1[2], (unsigned int)(v10 - 48) <= 9) || (v10 & 0xFFFFFFDF) - 65 <= 5) )
    {
      a1 += 2;
      v3 = v10;
      a3 = 16;
    }
    else
    {
      ++a1;
      if ( !a3 )
      {
        a3 = 8;
        if ( v3 != 45 )
          goto LABEL_5;
LABEL_25:
        v4 = 1;
        v3 = *++a1;
        goto LABEL_6;
      }
    }
  }
  else if ( !a3 )
  {
    a3 = 10;
  }
  if ( v3 == 45 )
    goto LABEL_25;
LABEL_5:
  v4 = 0;
LABEL_6:
  for ( i = 0; ; i = v6 + i * a3 )
  {
    v6 = v3 - 48;
    if ( (uint8_t)(v3 - 48) > 9u )
    {
      if ( (v3 & 0xFFFFFFDF) - 65 > 5 )
        break;
      if ( (unsigned int)(v3 - 97) > 0x19 )
        v6 = v3 - 55;
      else
        v6 = (uint8_t)(v3 - 32) - 55;
    }
    if ( a3 <= v6 )
      break;
    v8 = *++a1;
    v3 = v8;
  }
  if ( v4 )
    i = -i;
  if ( a2 )
    *a2 = a1;
  return i;
}

