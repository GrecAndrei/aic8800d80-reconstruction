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

extern uint32_t dword_131140;

// rf_set_cal_byte_a4 @ 0x131074, size 202 bytes
uint8_t * rf_set_cal_byte_a4(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0
  int v5; // r5
  int v6; // r3
  char v7; // r6
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // zf
  uint8_t v12[5]; // [sp+7h] [bp-5h] BYREF

  result = find_char_2(a1, a2, v12);
  if ( result )
  {
    v5 = *(uint8_t *)(a3 + 164);
    if ( *(uint8_t *)(a3 + 164) )
    {
      if ( v5 == 1 && (uint16_t)(*(uint16_t *)(a3 + 166) - 5005) <= 0x370u )
      {
        v5 = (uint8_t)((unsigned int)(((unsigned int)dword_131140
                                             * (unsigned uint64_t)((unsigned int)*(uint16_t *)(a3 + 166) - 5000)) >> 32) >> 2);
        v7 = 4;
      }
      else
      {
        v5 = 0;
        v7 = 4;
      }
    }
    else
    {
      v6 = *(uint16_t *)(a3 + 166);
      if ( (unsigned int)(v6 - 2412) > 0x48 )
      {
        v7 = 1;
      }
      else
      {
        v5 = v6 == 2484
           ? 14
           : (uint8_t)((unsigned int)(((unsigned int)dword_131140 * (unsigned uint64_t)(unsigned int)(v6 - 2407)) >> 32) >> 2);
        v7 = 1;
      }
    }
    v12[0] += 2;
    if ( v12[0] > 7u )
    {
      v8 = 5;
      do
      {
        v9 = (uint8_t)result[v8];
        if ( result[v8 + 1] )
        {
          if ( v9 == v5 )
          {
LABEL_7:
            *(uint8_t *)(a3 + 172) = result[v8 + 2];
            return result;
          }
          v10 = 0;
          while ( 1 )
          {
            v11 = v10 == (uint8_t)(result[v8 + 1] - 1);
            v9 = (uint8_t)(v9 + v7);
            ++v10;
            if ( v11 )
              break;
            if ( v9 == v5 )
              goto LABEL_7;
          }
        }
        v8 = (uint8_t)(v8 + 3);
      }
      while ( v12[0] > v8 + 2 );
    }
  }
  return result;
}

