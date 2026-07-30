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

extern uint32_t dword_12A164;
extern uint32_t dword_12A160;

// sub_129FAC @ 0x129fac, size 434 bytes
// Doc: sub_1229FAC [unknown]: Complex setup with index scaling and large table computation
// sub_1229FAC [unknown]: Complex setup with index scaling and large table computation
int  sub_129FAC(int result, int a2, unsigned int a3)
{
  int v3; // r8
  int v4; // r9
  int v5; // r5
  int v6; // r4
  int v8; // r3
  int v10; // r2
  uint8_t *v11; // r7
  int v12; // r3
  int v13; // r7
  int v14; // r3
  int v15; // r3
  uint64_t v16; // kr00_8
  unsigned int v17; // r7
  uint8_t *v18; // r9
  uint8_t v19; // r11
  unsigned int v20; // r3
  int v21; // r5
  int v22; // r2
  char v23; // r3
  uint8_t *v24; // r7
  int v25; // r3
  int v26; // r6
  int v27; // r3
  int v28; // [sp+0h] [bp-Ch]
  int v29; // [sp+4h] [bp-8h]

  v3 = dword_12A164;
  v4 = 140 * result;
  v5 = result;
  v6 = dword_12A164 + 140 * result;
  if ( !a2 )
  {
    v24 = (uint8_t *)(dword_12A164 + 140 * result);
    v25 = (uint8_t)v24[121];
    v24[132] = 0;
    if ( v25 )
    {
      if ( v24[16] )
      {
        timestamp_remove_058(v6);
        v24[16] = 0;
      }
      v26 = v3 + 140 * v5;
      v27 = *(uint8_t *)(v26 + 64);
      *(uint8_t *)(v26 + 121) = 0;
      if ( v27 )
      {
        timestamp_remove_058(v4 + 48 + v3);
        *(uint8_t *)(v26 + 64) = 0;
      }
      *(uint8_t *)(v3 + 140 * v5 + 121) = 0;
      sub_129A28((uint8_t *)v6);
    }
    goto LABEL_19;
  }
  v8 = dword_12A164 + 140 * result;
  v10 = *(uint8_t *)(a2 + 3);
  if ( !*(uint8_t *)(v8 + 132) || *(uint8_t *)(v8 + 120) != v10 )
  {
    v11 = (uint8_t *)(dword_12A164 + 140 * result);
    v12 = (uint8_t)v11[121];
    v11[120] = v10;
    v11[132] = 1;
    if ( v12 )
    {
      if ( v11[16] )
      {
        timestamp_remove_058(v6);
        v11[16] = 0;
      }
      v13 = v3 + 140 * v5;
      v14 = *(uint8_t *)(v13 + 64);
      *(uint8_t *)(v13 + 121) = 0;
      if ( v14 )
      {
        timestamp_remove_058(v4 + 48 + v3);
        *(uint8_t *)(v13 + 64) = 0;
      }
      *(uint8_t *)(v3 + 140 * v5 + 121) = 0;
      sub_129A28((uint8_t *)v6);
    }
    v15 = *(uint16_t *)(a2 + 1) - 2;
    v16 = dword_12A160 * (uint64_t)v15;
    v17 = (uint8_t)((SHIDWORD(v16) >> 2) - (v15 >> 31));
    if ( (uint8_t)(SHIDWORD(v16) >> 2) != (uint8_t)(v15 >> 31) )
    {
      v28 = v3 + 140 * v5;
      v18 = (uint8_t *)(a2 + 5);
      v19 = 0;
      v29 = v5;
      do
      {
        v20 = *v18;
        *(uint8_t *)(v6 + 20) = v20;
        ++v19;
        if ( v20 )
        {
          v21 = *(uint32_t *)(v18 + 5);
          if ( v20 <= 1 || v21 )
          {
            *(uint32_t *)(v6 + 24) = *(uint32_t *)(v18 + 1);
            v22 = v21 - 4000 - sub_10186C();
            v23 = *(uint8_t *)(v6 + 20);
            *(uint32_t *)(v6 + 28) = v22;
            *(uint8_t *)(v6 + 19) = v23;
            if ( fw_info_get_or_init(v6, *(uint8_t *)(v28 + 113), *(uint32_t *)(v18 + 9), a3) )
              ++*(uint8_t *)(v28 + 121);
          }
        }
        v18 += 13;
        v6 += 48;
      }
      while ( v19 < v17 );
      v5 = v29;
    }
    if ( *(char *)(a2 + 4) < 0 )
    {
      *(uint8_t *)(v3 + 140 * v5 + 115) = *(uint8_t *)(a2 + 4) & 0x7F;
      return 140;
    }
LABEL_19:
    *(uint8_t *)(v3 + 140 * v5 + 115) = 0;
    return 140;
  }
  return result;
}

