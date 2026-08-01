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

// process_entry_list @ 0x13e1d0, size 160 bytes
int  process_entry_list(int result, int a2)
{
  unsigned int v2; // r11
  int v4; // r9
  int v5; // r5
  int v6; // r7
  uint32_t *v7; // r4
  int v8; // r6
  unsigned int v9; // r1
  uint64_t v10; // r2
  unsigned int v11; // t1
  uint64_t v12; // kr00_8
  uint8_t v13[52]; // [sp+4h] [bp-34h] BYREF

  if ( *(uint16_t *)(result + 184) )
  {
    v2 = (uint16_t)(*(uint16_t *)(result + 184) - 1);
    v4 = result + 16;
    if ( v2 > 1 )
    {
      do
      {
        v5 = 1;
        v6 = 1;
        v7 = (uint32_t *)(a2 + 4);
        v8 = v4;
        v9 = 0;
        do
        {
          while ( 1 )
          {
            LODWORD(v10) = *v7;
            v11 = v7[1];
            ++v7;
            HIDWORD(v10) = v11;
            if ( (unsigned int)v10 > v11 || !v10 && !*(uint8_t *)(v8 + 9) && *(uint8_t *)(v8 + 21) == 1 )
              break;
            v6 = (uint16_t)++v5;
            v8 += 12;
            if ( (uint16_t)v5 >= v2 )
              goto LABEL_10;
          }
          memmove(v13, v8);
          memmove(v8, v8 + 12);
          result = memmove(v8 + 12, v13);
          ++v5;
          v12 = *(uint64_t *)(v7 - 1);
          v9 = v6;
          v6 = (uint16_t)v5;
          *(v7 - 1) = HIDWORD(v12);
          *v7 = v12;
          v8 += 12;
        }
        while ( (uint16_t)v5 < v2 );
LABEL_10:
        if ( !v9 )
          break;
        v2 = v9;
      }
      while ( v9 > 1 );
    }
  }
  return result;
}

