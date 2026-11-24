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


extern uint32_t dword_13F154;

// sub_13ED0C @ 0x13ed0c, size 1094 bytes
int  sub_13ED0C(int a1, int a2)
{
  int v2; // r3
  unsigned int v3; // r2
  int v5; // r0
  int v6; // r5
  int v7; // r7
  int v8; // r7
  int v9; // r0
  unsigned int v10; // r9
  uint16_t v11; // r0
  signed int v12; // r3
  int v13; // r6
  int v14; // r7
  int v15; // r11
  unsigned int v16; // r5
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v20; // r12
  unsigned int v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r0
  unsigned int v24; // r12
  unsigned int v25; // r7
  unsigned int v26; // r10
  int v27; // r9
  unsigned int v28; // r6
  int v29; // r3
  int v30; // r0
  unsigned int v31; // r3
  unsigned int v32; // r6
  unsigned int v33; // r5
  int v34; // lr
  int v35; // r0
  int v36; // r0
  int v37; // r0
  int v38; // r3
  int v39; // r0
  int v40; // r11
  uint8_t *v41; // r3
  uint16_t v42; // r0
  unsigned int v43; // r3
  int v44; // r2
  unsigned int v45; // [sp+0h] [bp-40h]
  int v46; // [sp+0h] [bp-40h]
  int v47; // [sp+4h] [bp-3Ch]
  int v48; // [sp+4h] [bp-3Ch]
  int v49; // [sp+4h] [bp-3Ch]
  int v50; // [sp+4h] [bp-3Ch]
  int result; // [sp+Ch] [bp-34h] BYREF
  uint16_t v52; // [sp+10h] [bp-30h]
  uint16_t v53; // [sp+12h] [bp-2Eh]
  uint16_t v54; // [sp+14h] [bp-2Ch]
  uint16_t v55; // [sp+16h] [bp-2Ah]
  uint16_t v56[20]; // [sp+18h] [bp-28h] BYREF

  v2 = *(uint8_t *)(a1 + 166);
  v3 = v2 << 26;
  if ( (v2 & 0x20) != 0 )
    return 0;
  v5 = *(uint8_t *)(a1 + 154);
  if ( v5 )
    return 0;
  v6 = *(uint16_t *)(a1 + 152);
  if ( *(uint16_t *)(a1 + 152) )
  {
    *(uint16_t *)(a1 + 152) = v6 - 1;
    return v5;
  }
  if ( (v2 & 0x40) == 0 )
  {
    v7 = *(uint16_t *)(a1 + 136);
    goto LABEL_6;
  }
  v3 = *(uint16_t *)(a1 + 184);
  if ( v3 <= 9 )
  {
    v7 = *(uint16_t *)(a1 + 136);
    goto LABEL_31;
  }
  v25 = *(uint8_t *)(a1 + 178);
  v26 = *(uint8_t *)(a1 + 177);
  v27 = *(uint16_t *)(a1 + 12 * *(uint16_t *)(a1 + 138) + 10);
  v28 = *(uint16_t *)(a1 + 12 * *(uint16_t *)(a1 + 136) + 10);
  sub_100200(&result, 0xFFu, 0xCu);
  v3 = v25 - v26;
  v46 = v25 - v26 + 1;
  while ( 2 )
  {
    v29 = (uint8_t)v6 - 1;
    switch ( (char)v6 )
    {
      case 1:
        if ( v26 <= 3 && (*(uint8_t *)(a1 + 166) & 8) != 0 )
        {
          v42 = sub_143A18();
          v43 = (uint8_t)((v42 & 0x7F) % v46 + v26);
          v44 = *(uint16_t *)(a1 + 174) >> v43;
          a2 = v44 << 31;
          if ( (v44 & 1) != 0 )
          {
            if ( !((uint8_t)((v42 & 0x7F) % v46) + (uint8_t)v26) )
              v43 = v25;
          }
          else
          {
            v43 = v25;
          }
          v3 = v43 - 1;
          HIWORD(result) = v43;
          if ( v43 - 1 <= 2 )
          {
            a2 = *(uint8_t *)(a1 + 182);
            v3 = v42 & 0x400 | (a2 << 10);
            HIWORD(result) = v43 | v3;
          }
        }
        else
        {
          v3 = (v28 >> 11) & 5;
          if ( v3 == 5 )
          {
            v38 = ((v28 >> 9) & 3) + 1;
            a2 = ((unsigned int)dword_13F154 * (uint64_t)(unsigned int)v38) >> 32;
            v3 = (a2 & 0xFFFFFFFE) + ((unsigned int)a2 >> 1);
            LOWORD(v28) = v28 & 0xF9FF;
            HIWORD(result) = v28 | (((uint16_t)v38 - (uint16_t)v3) << 9);
            v28 = (uint16_t)v28;
          }
          else if ( ((v28 >> 11) & 6) != 0 && *(uint8_t *)(a1 + 181) == 1 )
          {
            HIWORD(result) = v28 ^ 0x200;
          }
        }
        goto LABEL_68;
      case 2:
        v37 = sub_13CF14(a1, v28, v3, v29);
        a2 = v37;
        if ( v37 != v28 )
        {
          v50 = v37;
          if ( sub_13D2F8(a1, v37) )
          {
            a2 = v50;
            v52 = v50;
          }
        }
        goto LABEL_68;
      case 3:
        v36 = sub_13D5E8(a1, v28, v3, v29);
        a2 = v36;
        if ( v36 != v28 )
        {
          v49 = v36;
          if ( sub_13D2F8(a1, v36) )
          {
            a2 = v49;
            v53 = v49;
          }
        }
        goto LABEL_68;
      case 4:
        v35 = sub_13CF14(a1, v27, v3, v29);
        a2 = v35;
        if ( v27 != v35 )
        {
          v48 = v35;
          if ( sub_13D2F8(a1, v35) )
          {
            a2 = v48;
            v54 = v48;
          }
        }
LABEL_68:
        if ( v25 <= 3 )
          goto LABEL_69;
        goto LABEL_71;
      case 5:
        v30 = sub_13D5E8(a1, v27, v3, v29);
        a2 = v30;
        if ( v27 != v30 )
        {
          v47 = v30;
          if ( sub_13D2F8(a1, v30) )
          {
            a2 = v47;
            v55 = v47;
          }
        }
        if ( v25 > 3 )
          goto LABEL_53;
        v3 = *((uint16_t *)&result + v6);
        if ( v3 != 0xFFFF )
          goto LABEL_53;
        goto LABEL_84;
      default:
        LOWORD(result) = sub_13D730(a1);
        if ( v25 <= 3 )
        {
LABEL_69:
          v3 = *((uint16_t *)&result + v6);
          if ( v3 == 0xFFFF )
LABEL_84:
            *((uint16_t *)&result + v6) = v25 | 0x400;
        }
        if ( (uint8_t)v6 != 5 )
        {
LABEL_71:
          ++v6;
          continue;
        }
LABEL_53:
        v31 = *(uint16_t *)(a1 + 184);
        if ( v31 <= 1 )
        {
          v7 = *(uint16_t *)(a1 + 136);
        }
        else
        {
          v32 = 0;
          v33 = 1;
          v7 = *(uint16_t *)(a1 + 136);
          do
          {
            v3 = a1 + 12 * v33;
            a2 = *(uint16_t *)(v3 + 8);
            if ( a2 < 0 && (a2 = *(uint8_t *)(v3 + 12), (unsigned int)a2 <= 0xA)
              || v33 == v7
              || (a2 = *(uint16_t *)(a1 + 138), a2 == v33)
              || (a2 = *(uint16_t *)(a1 + 140), a2 == v33)
              || v32 > 5 )
            {
              v33 = (uint16_t)(v33 + 1);
            }
            else
            {
              a2 = (int)&v56[v32];
              v34 = *(uint16_t *)(a2 - 12);
              if ( v34 != 0xFFFF )
              {
                if ( v31 )
                {
                  a2 = a1;
                  v39 = 0;
                  while ( 1 )
                  {
                    v40 = *(uint16_t *)(a2 + 10);
                    ++v39;
                    a2 += 12;
                    if ( v40 == v34 )
                      break;
                    if ( v39 == v31 )
                      goto LABEL_92;
                  }
                }
                else
                {
LABEL_92:
                  v41 = (uint8_t *)(a1 + 12 * v33);
                  *(uint16_t *)(v3 + 10) = v34;
                  *(uint16_t *)(v3 + 8) = 0;
                  v41[13] = 0;
                  *(uint16_t *)(v3 + 4) = 0;
                  *(uint16_t *)(v3 + 6) = 0;
                  v41[12] = 0;
                  v41[14] = 1;
                  sub_13DB2C(a1, v33);
                  v33 = (uint16_t)(v33 + 1);
                  v7 = *(uint16_t *)(a1 + 136);
                  v31 = *(uint16_t *)(a1 + 184);
                }
              }
              ++v32;
            }
          }
          while ( v31 > v33 );
        }
        LOBYTE(v2) = *(uint8_t *)(a1 + 166);
LABEL_31:
        *(uint8_t *)(a1 + 166) = v2 & 0xBF;
LABEL_6:
        v8 = 12 * v7;
        v9 = sub_13EBBC(v8 + 4 + a1, a2, v3);
        v10 = *(uint8_t *)(a1 + 169);
        v45 = v9;
        *(uint16_t *)(a1 + 152) = 10 * *(uint16_t *)(a1 + 150);
        v11 = sub_143A18();
        v12 = *(uint16_t *)(a1 + 184);
        v13 = (uint16_t)(v11 % *(uint16_t *)(a1 + 184));
        if ( *(uint16_t *)(a1 + 184) )
        {
          v14 = v8 + a1;
          v15 = 0;
          while ( 1 )
          {
            while ( 1 )
            {
              v16 = (v13 + v15) % (unsigned int)v12;
              v13 = (uint16_t)v16;
              if ( *(uint16_t *)(a1 + 136) == (uint16_t)v16 )
                goto LABEL_26;
              v17 = a1 + 12 * v16;
              if ( *(uint16_t *)(v17 + 8) > 0xF333u )
                goto LABEL_26;
              if ( v10 <= 1 )
                goto LABEL_24;
              v18 = *(uint8_t *)(a1 + 166);
              v19 = v18 << 30;
              if ( (v18 & 2) != 0 )
                break;
              v21 = *(uint16_t *)(a1 + 188);
              if ( !*(uint16_t *)(a1 + 188) )
              {
                v19 = *(uint16_t *)(a1 + 192);
                if ( !*(uint16_t *)(a1 + 192) )
                  goto LABEL_19;
              }
              v20 = *(uint16_t *)(v17 + 10);
              v17 = v20 >> 11;
              if ( ((v20 >> 11) & 6) != 0 )
                goto LABEL_15;
              if ( v12 <= ++v15 )
                return 0;
            }
            v20 = *(uint16_t *)(v17 + 10);
            v17 = v20 >> 11;
            if ( ((v20 >> 11) & 6) != 0 )
              break;
LABEL_26:
            if ( v12 <= ++v15 )
              return 0;
          }
          v21 = *(uint16_t *)(a1 + 188);
          if ( !*(uint16_t *)(a1 + 188) && !*(uint16_t *)(a1 + 192) )
            goto LABEL_19;
LABEL_15:
          v17 &= 7u;
          if ( v17 <= 3 )
          {
            if ( v17 <= 1 )
            {
              v22 = v20 & 0x7F;
              goto LABEL_18;
            }
            if ( (v20 & 0x10) != 0 )
              goto LABEL_19;
            v22 = v20 & 7;
LABEL_18:
            if ( sub_1172B0(v21) <= v22 )
              goto LABEL_19;
LABEL_25:
            v12 = *(uint16_t *)(a1 + 184);
            goto LABEL_26;
          }
          if ( (((int)v20 >> 4) & 6) == 0 )
          {
            v22 = v20 & 0xF;
            goto LABEL_18;
          }
LABEL_19:
          v23 = sub_13EBBC(12 * v16 + 4 + a1, v17, v19);
          if ( *(uint8_t *)(a1 + 12 * v16 + 13) )
            v24 = 32;
          else
            v24 = *(uint16_t *)(a1 + 150);
          if ( *(uint16_t *)(v14 + 8) <= 0xF333u )
          {
            if ( v45 <= v23 )
              goto LABEL_24;
          }
          else if ( v45 <= v23 )
          {
LABEL_23:
            if ( *(uint8_t *)(a1 + 12 * v16 + 12) >= v24 )
              goto LABEL_24;
            goto LABEL_25;
          }
          if ( !*(uint8_t *)(a1 + 12 * v16 + 13) )
          {
LABEL_24:
            *(uint8_t *)(a1 + 164) = v16;
            *(uint8_t *)(a1 + 154) = 1;
            return 1;
          }
          goto LABEL_23;
        }
        return 0;
    }
  }
}
