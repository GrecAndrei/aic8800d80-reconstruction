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

extern uint32_t dword_142318;
extern uint32_t off_14231C;
extern uint32_t dword_142334;
extern uint32_t dword_142330;
extern uint32_t dword_142320;
extern uint32_t off_142324;
extern uint32_t dword_14232C;
extern uint32_t dword_142328;

// sub_1420D0 @ 0x1420d0, size 582 bytes
unsigned int  sub_1420D0(unsigned int result)
{
  int v1; // r1
  int v2; // r2
  int v3; // r5
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r3
  int v7; // r3
  int v8; // r6
  int v9; // r5
  int v10; // r3
  int v11; // r5
  int v12; // r4
  uint8_t *v13; // r1
  char v14; // r3
  unsigned int v15; // r9
  int16_t v16; // r8
  uint16_t *v17; // r7
  unsigned int v18; // r10
  int v19; // r11
  unsigned int v20; // r8
  char *v21; // r8
  int v22; // r5
  int v23; // r7
  int16_t v24; // r2
  char v25; // r3
  int v26; // r0
  uint16_t *v27; // r3
  char v28; // r12
  char v29; // r0
  int v30; // r4
  char *v31; // r11
  char v32; // r3
  char v33; // r3
  uint64_t v34; // r0
  uint64_t v35; // r0
  uint8_t v36; // r0
  int16_t v37[38]; // [sp+0h] [bp-4Ch] BYREF

  v1 = *(uint8_t *)(result + 7);
  v2 = *(uint8_t *)(result + 8);
  v3 = dword_142318;
  v4 = result;
  v5 = v2;
  if ( (v1 != 255 || !*(uint8_t *)(dword_142318 + 1320 * v2 + 108))
    && (*(uint32_t *)(dword_142318 + 1320 * v2 + 472) & 8) != 0 )
  {
    if ( *(uint8_t *)(result + 12) == 22 )
    {
      v6 = *(uint8_t *)(result + 13);
      result += 12;
      if ( v6 == 6 )
      {
        v15 = *(uint8_t *)(v4 + 17);
        v16 = *(uint16_t *)v4;
        v17 = (uint16_t *)(v4 + 18);
        v18 = *(uint16_t *)(v4 + 18);
        if ( **(int16_t **)off_14231C < 0 && v2 == 255 )
        {
          result = sub_12F46C(dword_142334, dword_142330, 637);
          v5 = *(uint8_t *)(v4 + 8);
        }
        if ( (v15 & 0xC) == 0 )
        {
          v19 = (v18 >> 1) & 7;
          v20 = (uint16_t)(v16 - 6);
          if ( v19 == 4 )
          {
            if ( (v18 & 1) == 0 )
            {
              v26 = v3 + 1320 * v5;
              if ( *(uint64_t *)(v26 + 40) )
              {
                v27 = (uint16_t *)dword_142320;
                v28 = *(uint8_t *)(v26 + 107);
                v29 = *(uint8_t *)(v4 + 7);
                v30 = v18 & 1;
                do
                {
                  if ( (*v27 & 1) == 0 )
                    v30 = (int)v27;
                  v27 += 36;
                }
                while ( (uint16_t *)(dword_142320 + 576) != v27 );
                v31 = (char *)off_142324;
                *(uint8_t *)(v30 + 47) = v28;
                v32 = *v31;
                *(uint8_t *)(v30 + 46) = v29;
                *(uint8_t *)(v30 + 2) = v32;
                *(uint8_t *)(v30 + 41) = 0;
                memset_thunk((int *)(v30 + 32), 0, 9u);
                v33 = *v31;
                *(uint16_t *)v30 = 1;
                *v31 = v33 + 1;
                sub_141C80(v17, v20, v15, (int16_t *)v30);
                ke_msg_alloc_n2e4(4, v30);
                LODWORD(v34) = sub_12BE40();
                v35 = *(uint64_t *)(v30 + 24) - v34 - *(uint64_t *)(v3 + 1320 * v5 + 40);
                v36 = sub_143414(v35, HIDWORD(v35), *(uint32_t *)(v30 + 16), 0);
                return rx_desc_lookup_or_build(v30, v36);
              }
              else
              {
                return sub_141FE0(*(uint8_t *)(v26 + 107), *(uint8_t *)(v4 + 7), (v18 >> 7) & 7);
              }
            }
          }
          else if ( v19 == 7 )
          {
            sub_141C80((uint16_t *)(v4 + 18), v20, v15, v37);
            return ke_msg_alloc_n2e4((v18 >> 1) & 7, (int)v37);
          }
        }
      }
      else if ( v6 == 7 )
      {
        result = *(uint8_t *)(v4 + 14);
        v7 = (result >> 5) & 3;
        if ( (result & 0x60) == 0 )
        {
          v8 = dword_142320;
          if ( (result & 0x80) != 0 )
          {
            v21 = (char *)off_142324;
            v22 = (result >> 5) & 3;
            v23 = dword_142320 + 576;
            do
            {
              if ( (*(uint16_t *)v8 & 1) != 0
                && *(uint8_t *)(v8 + 46) == *(uint8_t *)(v4 + 7)
                && *(uint8_t *)(v8 + 47) == *(uint8_t *)(v4 + 8) )
              {
                result = msg_parse_top_nibble(v8);
                v24 = *(uint16_t *)v8;
                v25 = *v21;
                *(uint8_t *)(v8 + 2) = v22;
                *(uint16_t *)v8 = v24 & 0xFFFE;
                *v21 = v25 - 1;
              }
              v8 += 72;
            }
            while ( v8 != v23 );
          }
          else
          {
            v9 = result & 7;
            result = dword_142320;
            while ( (*(uint16_t *)result & 1) == 0
                 || *(uint8_t *)(result + 47) != v2
                 || *(uint8_t *)(result + 46) != v1
                 || *(uint8_t *)(result + 2) != v9 )
            {
              ++v7;
              result += 72;
              if ( v7 == 8 )
                return result;
            }
            v10 = 9 * v7;
            v11 = dword_142320 + 8 * v10;
            v12 = 8 * v10;
            msg_parse_top_nibble(v11);
            v13 = off_142324;
            v14 = *(uint8_t *)off_142324 - 1;
            *(uint16_t *)(v8 + v12) &= ~1u;
            *(uint8_t *)(v11 + 2) = 0;
            *v13 = v14;
            return 0;
          }
        }
      }
    }
    else if ( **(int16_t **)off_14231C < 0 )
    {
      return sub_12F46C(dword_14232C, dword_142328, 828);
    }
  }
  return result;
}

