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

extern uint32_t off_1263B0;
extern uint32_t off_1263C4;
extern uint32_t dword_126640;
extern uint32_t dword_12663C;
extern uint32_t off_1263B4;
extern uint32_t off_126648;
extern uint32_t dword_126644;
extern uint32_t dword_126660;
extern uint32_t off_1263B8;
extern uint32_t dword_12665C;
extern uint32_t dword_126654;
extern uint32_t dword_12664C;
extern uint32_t off_1263C8;
extern uint32_t off_126658;
extern uint32_t dword_1263BC;
extern uint32_t dword_126650;
extern uint32_t off_1263C0;

// sub_12609C @ 0x12609c, size 1438 bytes
// Doc: sub_122609C [bt]: BT firmware initialization or configuration routine
// sub_122609C [bt]: BT firmware initialization or configuration routine
uint32_t * sub_12609C(uint32_t *result)
{
  int16_t **v1; // r9
  int v2; // r3
  int v3; // r2
  int v4; // zf
  int v5; // r2
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r6
  unsigned int v10; // r11
  int v11; // r7
  int v12; // r3
  int v13; // r3
  int v14; // zf
  char *v15; // r4
  int v16; // r5
  uint64_t v17; // r0
  unsigned int v18; // r8
  unsigned int v19; // r2
  int v20; // r0
  uint32_t *v21; // r5
  char v22; // r1
  int v23; // r4
  unsigned int v24; // r2
  char *v25; // r1
  int v26; // r3
  uint32_t *v27; // r4
  uint32_t *v28; // r10
  unsigned int *v29; // r4
  int v30; // r11
  unsigned int v31; // r7
  int v32; // r0
  uint64_t v33; // kr00_8
  unsigned int v34; // r5
  int v35; // r0
  int v36; // r1
  int v37; // r7
  unsigned int i; // r3
  int v39; // r6
  char v40; // r7
  int j; // r5
  unsigned int v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r3
  int v45; // r3
  int v46; // r0
  uint8_t *v47; // r2
  char v48; // r3
  uint32_t *v49; // r2
  int v50; // r4
  unsigned int v51; // r2
  uint32_t *v52; // r4
  int v53; // r3
  uint32_t *v54; // r2
  int v55; // r0
  unsigned int v56; // r0
  unsigned int v57; // r2
  unsigned int v58; // r1
  int v59; // r5
  uint64_t v60; // kr08_8
  int v61; // r5
  int v62; // r3
  int v63; // r2
  int v64; // r2
  int v65; // r2
  unsigned int v66; // [sp+14h] [bp-58h]
  int v67; // [sp+14h] [bp-58h]
  unsigned int v68; // [sp+18h] [bp-54h]
  int v69; // [sp+18h] [bp-54h]
  int v70; // [sp+1Ch] [bp-50h]
  int v71; // [sp+20h] [bp-4Ch]
  unsigned int v72; // [sp+24h] [bp-48h]
  int v73; // [sp+24h] [bp-48h]
  unsigned int v74; // [sp+28h] [bp-44h]
  unsigned int v75; // [sp+2Ch] [bp-40h]
  uint32_t *v76; // [sp+30h] [bp-3Ch] BYREF
  char *v77; // [sp+34h] [bp-38h]
  int v78; // [sp+38h] [bp-34h] BYREF
  int v79; // [sp+3Ch] [bp-30h]
  char v80; // [sp+40h] [bp-2Ch] BYREF
  char v81; // [sp+48h] [bp-24h] BYREF
  uint32_t var4[2]; // [sp+68h] [bp-4h] BYREF
  int vars4; // [sp+70h] [bp+4h]
  int vars8; // [sp+74h] [bp+8h]

  v71 = (int)result;
  if ( *((uint8_t *)off_1263B0 + 90) <= 1u )
    return result;
  v1 = (int16_t **)off_1263C4;
  if ( **(int16_t **)off_1263C4 < 0 )
  {
    v53 = *(uint8_t *)(result[18] + 27);
    if ( v53 != 255 && *((uint8_t *)result + 107) != v53 )
      sub_12F694(dword_126640, dword_12663C, 691);
  }
  sub_126034(v71);
  v2 = *(uint32_t *)(v71 + 72);
  *(uint8_t *)(v2 + 27) = *(uint8_t *)(v71 + 107);
  v3 = *(uint8_t *)(v71 + 106);
  if ( *(uint8_t *)(v71 + 106) )
  {
    v4 = v3 == 2;
    if ( v3 == 2 )
      v3 = v71;
    result = off_1263B4;
    if ( v4 )
      v5 = *(uint16_t *)(v3 + 222);
    else
      v5 = 102400;
    if ( v4 )
      v5 <<= 10;
    v74 = v5;
    v6 = *(uint8_t *)(v2 + 24);
    v7 = v6 + 1;
    if ( v6 != 2 )
    {
LABEL_12:
      v8 = 8 * v7;
      if ( LOBYTE(result[7 * v7 + 6]) == 255 )
      {
        v7 = v6 + 2;
        if ( v6 == 1 )
          v7 = 0;
        goto LABEL_15;
      }
      goto LABEL_16;
    }
  }
  else
  {
    result = off_126648;
    v74 = *(uint32_t *)(dword_126644 + 696 * *(uint8_t *)(v71 + 116) + 8);
    v6 = *(uint8_t *)(v2 + 24);
    v7 = v6 + 1;
    if ( v6 != 2 )
      goto LABEL_12;
  }
  if ( *((uint8_t *)result + 24) == 255 )
  {
    v7 = 1;
LABEL_15:
    v8 = 8 * v7;
    if ( LOBYTE(result[7 * v7 + 6]) == 255 )
    {
      if ( **v1 < 0 )
        sub_12F694(dword_126660, dword_12663C, 698);
      __und(0xFFu);
    }
    goto LABEL_16;
  }
  v7 = 0;
  v8 = 0;
LABEL_16:
  v9 = *((uint32_t *)off_1263B8 + 2);
  v68 = BYTE1(result[v8 - v7 + 6]);
  if ( !v9 )
    return result;
  v10 = 0;
  v11 = 0;
  do
  {
    while ( 1 )
    {
      v12 = *(uint32_t *)(v9 + 72);
      if ( !v12 || v12 == *(uint32_t *)(v71 + 72) )
        goto LABEL_18;
      v13 = *(uint8_t *)(v9 + 106);
      if ( *(uint8_t *)(v9 + 106) )
      {
        v14 = v13 == 2;
        if ( v13 == 2 )
          v13 = *(uint16_t *)(v9 + 222);
        else
          v10 = 102400;
        if ( v14 )
          v10 = v13 << 10;
      }
      else
      {
        v10 = *(uint32_t *)(dword_126644 + 696 * *(uint8_t *)(v9 + 116) + 8);
      }
      if ( 2 * v74 <= v10 )
        v10 /= v10 / v74;
      v72 = (v10 >> 1) / v68;
      if ( sub_10186C() + 14000 <= v72 )
        break;
      v72 = sub_10186C() + 14000;
      if ( v11 )
        goto LABEL_31;
LABEL_59:
      if ( **v1 < 0 )
      {
        if ( v11 == 2 )
        {
          result = (uint32_t *)sub_12F694(dword_12665C, dword_12663C, 755);
          v65 = **v1;
          var4[0] = v10;
          var4[1] = v72;
          vars4 = *(uint32_t *)(v9 + 36);
          vars8 = vars4 + 10000;
          v50 = 8;
          if ( v65 >= 0 )
            goto LABEL_61;
        }
        else
        {
          result = *(uint32_t **)(v9 + 36);
          v54 = &var4[5 * v11];
          *(v54 - 10) = v10;
          *(v54 - 9) = v72;
          *(v54 - 8) = result;
          *(v54 - 7) = result + 2500;
          v50 = 4 * v11;
        }
        v51 = *(uint8_t *)(v9 + 107);
        if ( v51 <= 0x1F )
          goto LABEL_62;
        result = (uint32_t *)sub_12F694(dword_126654, dword_12663C, 761);
      }
      else
      {
        result = *(uint32_t **)(v9 + 36);
        v49 = &var4[5 * v11];
        *(v49 - 10) = v10;
        *(v49 - 9) = v72;
        *(v49 - 8) = result;
        *(v49 - 7) = result + 2500;
        v50 = 4 * v11;
      }
LABEL_61:
      LOBYTE(v51) = *(uint8_t *)(v9 + 107);
LABEL_62:
      v52 = &var4[v50 + v11++];
      *(v52 - 6) = 1 << v51;
LABEL_18:
      v9 = *(uint32_t *)v9;
      if ( !v9 )
        goto LABEL_39;
    }
    if ( !v11 )
      goto LABEL_59;
LABEL_31:
    v15 = &v80;
    v16 = 0;
    while ( 1 )
    {
      if ( *(uint32_t *)v15 == v10 )
      {
        v76 = *(uint32_t **)(v9 + 36);
        v17 = *((uint64_t *)v15 + 1);
        v78 = *((uint32_t *)v15 + 2);
        v79 = HIDWORD(v17);
        v77 = (char *)(v76 + 2500);
        v18 = sub_125F18((unsigned int *)&v76, (unsigned int *)&v78, (unsigned int *)&v76, v10);
        if ( **v1 < 0 && v68 <= 1 )
          sub_12F694(dword_12664C, dword_12663C, 735);
        v19 = v68 * v72 / (v68 - 1) - 4000 - sub_10186C();
        if ( v19 < *((uint32_t *)v15 + 1) )
          v19 = *((uint32_t *)v15 + 1);
        if ( v19 > v18 )
          break;
      }
      ++v16;
      v15 += 20;
      if ( v11 == v16 )
        goto LABEL_59;
    }
    v66 = v19;
    v20 = sub_10186C();
    v21 = &var4[5 * v16];
    v22 = *(uint8_t *)(v9 + 107);
    v9 = *(uint32_t *)v9;
    v23 = 1 << v22;
    v24 = v66 + v20;
    result = v76;
    v25 = v77;
    v26 = *(v21 - 6) | v23;
    v27 = v21 - 8;
    *v27 = v76;
    v27[1] = v25;
    *(v21 - 9) = v24 + 4000;
    *(v21 - 6) = v26;
  }
  while ( v9 );
LABEL_39:
  if ( !v11 )
    return result;
  v28 = off_1263C8;
  v70 = v9;
  v73 = v9;
  v69 = v9;
  v29 = (unsigned int *)&v81;
  v67 = v11;
  v30 = v9;
  while ( 2 )
  {
    v31 = *(v29 - 2);
    if ( !(v31 % v74) )
    {
      v55 = v28[4] + 32 * *(uint32_t *)off_126658;
      if ( v31 >= v74 )
        v31 = v74;
      v78 = v28[4] + 32 * *(uint32_t *)off_126658;
      v79 = v55 + 10000;
      v56 = sub_125F18(v29, (unsigned int *)&v78, 0, v31);
      v57 = v29[1];
      if ( (int)(*v29 - v78) >= 0 )
        v58 = v31 - v56;
      else
        v58 = v78 - v57;
      v59 = *(v29 - 1) + *v29 - 2000 - v57;
      v75 = v58;
      if ( sub_10186C() + 4000 > v59 )
        v59 = sub_10186C() + 4000;
      v60 = *((uint64_t *)v29 - 1);
      v61 = v59 - v75;
      v62 = v60 - 14000 - HIDWORD(v60) - sub_10186C() + v61;
      if ( !v69 )
      {
        v70 = v62;
        v73 = v61;
        v69 = 1;
        goto LABEL_42;
      }
      if ( v70 < v61 )
      {
        v61 -= v74;
        v62 -= v74;
      }
      else
      {
        if ( v73 <= v62 )
        {
LABEL_96:
          v63 = v73;
          if ( v73 < v61 )
            v63 = v61;
          v73 = v63;
          v64 = v70;
          if ( v70 >= v62 )
            v64 = v62;
          v70 = v64;
          goto LABEL_42;
        }
        v62 += v74;
        v61 += v74;
      }
      if ( v70 < v61 || v73 > v62 )
        goto LABEL_42;
      goto LABEL_96;
    }
LABEL_42:
    v32 = sub_10186C();
    v33 = *(uint64_t *)(v29 - 1);
    v34 = HIDWORD(v33) - 6000 - v32;
    v35 = sub_10186C();
    v36 = *(v29 - 2);
    v37 = v33 + 4000 + v35;
    if ( (int)(v34 - v28[4]) < 0 )
    {
      do
      {
        v34 += v36;
        if ( (int)(v34 - v28[4]) >= 0 )
          break;
        v34 += v36;
      }
      while ( (int)(v34 - v28[4]) < 0 );
    }
    else
    {
      for ( i = v34 - v36; (int)(i - v28[4]) >= 0; i -= v36 )
        v34 = i;
    }
    result = (uint32_t *)sub_12A818(v71, 1, 0, 255, v36, v37, v34);
    v39 = dword_1263BC;
    *v29 = v34;
    v29[1] = v34 + v37;
    v40 = (char)result;
    for ( j = 0; j != 4; ++j )
    {
      if ( ((v29[2] >> j) & 1) != 0 )
      {
        v42 = *(v29 - 2);
        v78 = *(uint32_t *)(v39 + 36);
        v79 = v78 + 10000;
        result = (uint32_t *)sub_125F18(v29, (unsigned int *)&v78, 0, v42);
        if ( **v1 < 0 && *(uint8_t *)(v39 + 86) != 255 )
          result = (uint32_t *)sub_12F694(dword_126650, dword_12663C, 876);
        v43 = v78;
        v44 = v29[1];
        *(uint8_t *)(v39 + 86) = *(uint8_t *)(v71 + 107);
        *(uint32_t *)(v39 + 92) = v44 - v43;
        *(uint8_t *)(v39 + 87) = v40;
        *(uint16_t *)(v39 + 96) = 0;
      }
      v39 += 1320;
    }
    ++v30;
    v29 += 5;
    if ( v67 != v30 )
      continue;
    break;
  }
  if ( v69 )
  {
    v45 = v70;
    if ( v70 >= v73 + 5000 )
      v45 = v73 + 5000;
    v46 = v45;
    if ( v45 > (int)v74 / 2 )
    {
      v46 = v45 - v74;
    }
    else if ( (int)v74 / -2 > v45 )
    {
      v46 = v45 + v74;
    }
    result = (uint32_t *)sub_121BE4(v46);
    v47 = off_1263C0;
    v48 = *(uint8_t *)(v71 + 85);
    *(uint32_t *)(v71 + 88) = result;
    *(uint8_t *)(v71 + 85) = v48 | 0x20;
    v47[49] = 1;
  }
  return result;
}

