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

extern uint32_t off_137944;
extern uint32_t off_137934;
extern uint32_t dword_12DCD0;
extern uint32_t dword_137930;
extern uint32_t off_137BB8;
extern uint32_t dword_137BBC;
extern uint32_t dword_137BB4;
extern uint32_t off_137938;
extern uint32_t dword_13793C;
extern uint32_t dword_137940;
extern uint32_t dword_137BC0;

// sub_137500 @ 0x137500, size 1714 bytes
int  sub_137500(int a1)
{
  uint8_t *v1; // r11
  char v3; // r3
  char v4; // r1
  char v5; // r2
  char v6; // r0
  char v7; // r1
  char v8; // r2
  uint16_t v9; // r0
  int v10; // r4
  int16_t v11; // r3
  int16_t v12; // r2
  uint8_t *v13; // r0
  uint8_t *v14; // r6
  int v15; // r4
  uint8_t *v16; // r10
  uint8_t *v17; // r0
  uint8_t *v18; // r7
  int v19; // r3
  int v20; // r5
  uint8_t *v21; // r9
  uint8_t *v22; // r0
  uint8_t *v23; // r11
  int v24; // r8
  uint8_t *v25; // r7
  uint8_t *v26; // r0
  int v27; // r5
  int v28; // r6
  int v29; // r1
  char *v30; // r3
  char *v31; // r2
  char *v33; // r3
  char *v34; // r1
  int v35; // r3
  int v36; // r2
  uint8_t *v37; // r3
  int16_t v38; // r1
  int v39; // r0
  uint8_t *v40; // r0
  int v41; // r1
  int v42; // r0
  int v43; // r1
  char *v44; // r0
  int v45; // r5
  int v46; // r3
  int v47; // r0
  int v48; // r6
  char v49; // r9
  int v50; // r8
  uint16_t *v51; // r7
  int v52; // r1
  int v53; // r2
  int v54; // r3
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r1
  int v59; // r2
  char *v60; // r3
  int v61; // r1
  int v62; // r2
  int v63; // r3
  int v64; // r4
  int v65; // r5
  uint16_t *v66; // r10
  uint32_t *v67; // r4
  int16_t v68; // lr
  unsigned int v69; // r7
  int v70; // r8
  int v71; // r12
  unsigned int v72; // r2
  uint16_t *v73; // r3
  int v74; // r1
  int v75; // r2
  int v76; // r3
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r1
  int v81; // r2
  char *v82; // r3
  int v83; // r1
  int v84; // r2
  unsigned int v85; // r2
  uint16_t *v86; // r1
  int v87; // r0
  int v88; // r12
  int v89; // r1
  int v90; // r2
  int v91; // r3
  int v92; // r1
  int v93; // r2
  int v94; // r3
  int v95; // r1
  int v96; // r2
  char *v97; // r3
  int v98; // r1
  int v99; // r2
  int v100; // r0
  int v101; // r1
  int v102; // r2
  int v103; // r3
  int v104; // r1
  int v105; // r2
  int v106; // r3
  int v107; // r1
  int v108; // r2
  int v109; // r3
  int v110; // r1
  int v111; // r2
  int v112; // r1
  int v113; // r8
  int v114; // r1
  int v115; // r3
  uint16_t v116; // r1
  int v117; // r1
  char v118; // r2
  uint16_t **v119; // r3
  int v120; // r1
  int v121; // r2
  int v122; // r3
  uint16_t *v123; // lr
  int v124; // r1
  int v125; // r2
  int v126; // r3
  int v127; // r1
  int v128; // r2
  char *v129; // r3
  int v130; // r1
  int v131; // r2
  uint8_t *v132; // [sp+1Ch] [bp-98h]
  int v133; // [sp+20h] [bp-94h]
  uint8_t *v134; // [sp+24h] [bp-90h]
  uint8_t *v135; // [sp+28h] [bp-8Ch]
  int v136; // [sp+2Ch] [bp-88h]
  int v138; // [sp+34h] [bp-80h]
  int v139; // [sp+38h] [bp-7Ch]
  uint8_t *v140; // [sp+3Ch] [bp-78h]
  uint8_t v141; // [sp+47h] [bp-6Dh] BYREF
  uint16_t v142; // [sp+48h] [bp-6Ch] BYREF
  uint16_t v143; // [sp+4Ah] [bp-6Ah]
  uint16_t v144; // [sp+4Ch] [bp-68h]
  int v145; // [sp+50h] [bp-64h] BYREF
  int16_t v146; // [sp+54h] [bp-60h]
  int v147; // [sp+74h] [bp-40h] BYREF
  int v148; // [sp+78h] [bp-3Ch]
  int v149; // [sp+7Ch] [bp-38h] BYREF
  int v150; // [sp+80h] [bp-34h]
  int v151; // [sp+84h] [bp-30h]
  int v152; // [sp+88h] [bp-2Ch]
  int v153; // [sp+8Ch] [bp-28h]
  int v154; // [sp+90h] [bp-24h]
  int v155; // [sp+94h] [bp-20h]
  int v156; // [sp+98h] [bp-1Ch]
  int v157; // [sp+9Ch] [bp-18h]
  char *v158; // [sp+A0h] [bp-14h]
  int v159; // [sp+A4h] [bp-10h]
  int v160; // [sp+A8h] [bp-Ch]
  int v161; // [sp+ACh] [bp-8h]
  char v162; // [sp+B0h] [bp-4h] BYREF

  v1 = off_137944;
  v3 = *((uint8_t *)off_137944 + 3852);
  v4 = *(uint8_t *)(a1 + 29);
  v5 = *(uint8_t *)(a1 + 30);
  LOBYTE(v142) = *(uint8_t *)(a1 + 28);
  HIBYTE(v142) = v4;
  v6 = *(uint8_t *)(a1 + 31);
  v7 = *(uint8_t *)(a1 + 32);
  LOBYTE(v143) = v5;
  v8 = *(uint8_t *)(a1 + 33);
  LOBYTE(v144) = v7;
  HIBYTE(v143) = v6;
  HIBYTE(v144) = v8;
  v139 = v3 & 1;
  if ( (v3 & 1) != 0 )
  {
    v9 = v143;
    LOWORD(v10) = v144;
    v139 = 0;
  }
  else if ( *((uint16_t *)off_137944 + 1926) != v142
         || (v9 = v143, *((uint16_t *)off_137944 + 1927) != v143)
         || (v10 = *((uint16_t *)off_137944 + 1928), v144 != v10) )
  {
    if ( !*((uint8_t *)off_137934 + 408) || *((uint8_t *)off_137944 + 3850) )
      return 0;
    v9 = v143;
    LOWORD(v10) = v144;
    v139 = 1;
  }
  v11 = *(uint16_t *)(a1 + 46);
  v12 = *(uint16_t *)a1;
  HIWORD(v147) = v142;
  LOWORD(v148) = v9;
  v140 = (uint8_t *)(a1 + 48);
  v138 = (uint16_t)(v12 - 36);
  HIWORD(v148) = v10;
  HIWORD(v157) = 2 - (v11 & 1);
  v13 = sub_12D7D8((uint8_t *)(a1 + 48), v138, &v141);
  if ( v13 )
  {
    LOBYTE(v149) = v141;
    if ( v141 )
    {
      v33 = (char *)&v149;
      v34 = (char *)&v149 + v141;
      do
      {
        v33[1] = v33[(uint32_t)v13 + 54 - (uint32_t)&v162];
        ++v33;
      }
      while ( v34 != v33 );
    }
  }
  else
  {
    LOBYTE(v149) = 0;
  }
  v14 = 0;
  v1[4029] = 0;
  if ( v138 )
  {
    v133 = v138;
    v132 = (uint8_t *)(a1 + 48);
    v15 = 0;
    v16 = 0;
    v134 = v1;
    while ( 1 )
    {
      v17 = sub_12DC08(v132, v133);
      v18 = v17;
      if ( !v17 )
        goto LABEL_18;
      v19 = (uint8_t)v17[1];
      v134[4028] = v17[2];
      v20 = (uint16_t)(v19 - 1);
      v136 = v19 + 2;
      v21 = v17 + 3;
      if ( (uint16_t)v19 == 1 )
        goto LABEL_17;
      v135 = v17;
      while ( 1 )
      {
        v22 = sub_12DC48(v21, v20);
        v23 = v22;
        if ( !v22 )
          break;
        v24 = v22[1];
        v25 = v22 + 2;
        v20 = (uint16_t)(v20 - (v24 + 2));
        v21 += v24 + 2;
        if ( sub_12DC90(v22 + 2, 4) )
        {
          v16 = v23 + 4;
          v15 = ((int ( *)(uint8_t *, int))dword_12DCD0[0])(v25, v24);
          goto LABEL_13;
        }
        if ( v16 )
        {
          if ( v15 )
          {
            if ( !v14 )
            {
              v14 = sub_12D7D8(v25, v24, &v145);
              if ( !v14 )
                goto LABEL_15;
            }
            goto LABEL_40;
          }
          v39 = ((int ( *)(uint8_t *, int))dword_12DCD0[0])(v25, v24);
          v15 = v39;
          if ( v14 )
          {
            if ( v39 )
              goto LABEL_40;
            if ( !v20 )
              break;
          }
          else
          {
LABEL_13:
            v26 = sub_12D7D8(v25, v24, &v145);
            v14 = v26;
            if ( !v15 || !v26 )
              goto LABEL_15;
LABEL_40:
            v35 = (uint8_t)v134[4029];
            v36 = (uint8_t)(v35 + 1);
            v37 = &v134[8 * v35];
            v38 = *v16 | (v16[1] << 8);
            v37[3906] = *(uint8_t *)(v15 + 2);
            *((uint32_t *)v37 + 975) = v14;
            *((uint16_t *)v37 + 1952) = v38;
            v134[4029] = v36;
            if ( v36 == 16 )
              goto LABEL_18;
            v16 = 0;
            if ( !v20 )
              break;
          }
        }
        else
        {
LABEL_15:
          if ( !v20 )
            break;
        }
      }
      v18 = v135;
LABEL_17:
      v133 = (uint16_t)(v133 + (uint16_t)v132 - (uint16_t)v18 - v136);
      v132 = &v18[v136];
      if ( !v133 )
      {
LABEL_18:
        v1 = v134;
        break;
      }
    }
  }
  if ( !v139 && !sub_13709C((uint8_t *)&v149) )
  {
    if ( !v1[4029] )
      return 0;
    v27 = dword_137930;
    v28 = 0;
    while ( 1 )
    {
      v29 = *(uint32_t *)(v27 + 8 * v28);
      LOBYTE(v145) = *(uint8_t *)(v29 + 1);
      if ( (uint8_t)v145 )
      {
        v30 = (char *)&v145;
        v31 = (char *)&v145 + (uint8_t)v145;
        do
        {
          v30[1] = v30[v29 + 98 - (uint32_t)&v162];
          ++v30;
        }
        while ( v31 != v30 );
      }
      if ( sub_13709C((uint8_t *)&v145) )
        break;
      if ( ++v28 >= (uint8_t)v1[4029] )
        return 0;
    }
  }
  v40 = sub_12DA20(v140, v138);
  if ( v40 )
  {
    v41 = (uint8_t)v40[2];
    v42 = *(uint8_t *)(a1 + 6);
    if ( *(uint8_t *)(a1 + 6) )
    {
      if ( v42 == 1 && (uint8_t)(v41 - 1) <= 0xB0u )
      {
LABEL_53:
        v43 = 5 * v41 + 5000;
LABEL_56:
        v44 = sub_1320BC(v42, v43);
        v45 = 1;
        v158 = v44;
        goto LABEL_57;
      }
LABEL_55:
      v43 = 0;
      goto LABEL_56;
    }
LABEL_54:
    if ( (unsigned int)(v41 - 1) <= 0xD )
    {
      if ( v41 == 14 )
        v43 = 2484;
      else
        v43 = 5 * v41 + 2407;
      goto LABEL_56;
    }
    goto LABEL_55;
  }
  v45 = (int)sub_12DD78(v140, v138);
  if ( v45 )
  {
    v42 = *(uint8_t *)(a1 + 6);
    v41 = *(uint8_t *)(v45 + 2);
    if ( *(uint8_t *)(a1 + 6) )
    {
      if ( v42 != 1 || (uint8_t)(v41 - 1) > 0xB0u )
      {
        v43 = 0;
        goto LABEL_56;
      }
      goto LABEL_53;
    }
    goto LABEL_54;
  }
  v44 = sub_1320BC(*(uint8_t *)(a1 + 6), *(uint16_t *)(a1 + 4));
  v158 = v44;
LABEL_57:
  v46 = *(uint16_t *)v44;
  if ( *(uint16_t *)(a1 + 4) != v46 )
    *(uint16_t *)(a1 + 4) = v46;
  sub_137114(v140, v138, *(uint16_t *)(a1 + 46), (int)&v147);
  v47 = sub_1374B0(&v142, 1);
  v48 = v47;
  if ( !v47 )
    goto LABEL_78;
  v49 = *(uint8_t *)v47;
  v50 = *(char *)(a1 + 9);
  v51 = (uint16_t *)v158;
  if ( *(uint8_t *)v47 )
  {
    if ( *(uint8_t *)(v47 + 8) != (uint8_t)v149 )
    {
      if ( *(uint8_t *)(v47 + 8) && !(uint8_t)v149 )
      {
        LOBYTE(v50) = *(uint8_t *)(v47 + 56);
        v51 = *(uint16_t **)(v47 + 44);
      }
      goto LABEL_63;
    }
    v87 = sub_1435D0(*(uint32_t *)(v47 + 44), v158, 6);
    if ( *(uint8_t *)(v48 + 8) == (uint8_t)v149 )
    {
      v88 = *(char *)(v48 + 56);
      if ( v88 > v50 )
      {
LABEL_92:
        v51 = *(uint16_t **)(v48 + 44);
        LOBYTE(v50) = v88;
        if ( !v87 )
        {
          v89 = v148;
          v90 = v149;
          v91 = v150;
          *(uint32_t *)v48 = v147;
          *(uint32_t *)(v48 + 4) = v89;
          *(uint32_t *)(v48 + 8) = v90;
          *(uint32_t *)(v48 + 12) = v91;
          v92 = v152;
          v93 = v153;
          v94 = v154;
          *(uint32_t *)(v48 + 16) = v151;
          *(uint32_t *)(v48 + 20) = v92;
          *(uint32_t *)(v48 + 24) = v93;
          *(uint32_t *)(v48 + 28) = v94;
          v95 = v156;
          v96 = v157;
          v97 = v158;
          *(uint32_t *)(v48 + 32) = v155;
          *(uint32_t *)(v48 + 36) = v95;
          *(uint32_t *)(v48 + 40) = v96;
          *(uint32_t *)(v48 + 44) = v97;
          v98 = v160;
          v99 = v161;
          *(uint32_t *)(v48 + 48) = v159;
          *(uint32_t *)(v48 + 52) = v98;
          *(uint32_t *)(v48 + 56) = v99;
          *(uint8_t *)(v48 + 56) = v88;
          *(uint32_t *)(v48 + 44) = v51;
          *(uint8_t *)v48 = v49;
          goto LABEL_68;
        }
        goto LABEL_63;
      }
    }
    if ( *(uint8_t *)(v48 + 8) && !(uint8_t)v149 )
    {
      LOBYTE(v88) = *(uint8_t *)(v48 + 56);
      goto LABEL_92;
    }
    if ( v87 )
    {
LABEL_63:
      v52 = v148;
      v53 = v149;
      v54 = v150;
      *(uint32_t *)v48 = v147;
      *(uint32_t *)(v48 + 4) = v52;
      *(uint32_t *)(v48 + 8) = v53;
      *(uint32_t *)(v48 + 12) = v54;
      v55 = v152;
      v56 = v153;
      v57 = v154;
      *(uint32_t *)(v48 + 16) = v151;
      *(uint32_t *)(v48 + 20) = v55;
      *(uint32_t *)(v48 + 24) = v56;
      *(uint32_t *)(v48 + 28) = v57;
      v58 = v156;
      v59 = v157;
      v60 = v158;
      *(uint32_t *)(v48 + 32) = v155;
      *(uint32_t *)(v48 + 36) = v58;
      *(uint32_t *)(v48 + 40) = v59;
      *(uint32_t *)(v48 + 44) = v60;
      v61 = v160;
      v62 = v161;
      *(uint32_t *)(v48 + 48) = v159;
      *(uint32_t *)(v48 + 52) = v61;
      *(uint32_t *)(v48 + 56) = v62;
      *(uint8_t *)(v48 + 56) = v50;
      *(uint32_t *)(v48 + 44) = v51;
      *(uint8_t *)v48 = v49;
      goto LABEL_64;
    }
    v120 = v148;
    v121 = v149;
    v122 = v150;
    v123 = *(uint16_t **)(v48 + 44);
    *(uint32_t *)v48 = v147;
    *(uint32_t *)(v48 + 4) = v120;
    *(uint32_t *)(v48 + 8) = v121;
    *(uint32_t *)(v48 + 12) = v122;
    v124 = v152;
    v125 = v153;
    v126 = v154;
    *(uint32_t *)(v48 + 16) = v151;
    *(uint32_t *)(v48 + 20) = v124;
    *(uint32_t *)(v48 + 24) = v125;
    *(uint32_t *)(v48 + 28) = v126;
    v127 = v156;
    v128 = v157;
    v129 = v158;
    *(uint32_t *)(v48 + 32) = v155;
    *(uint32_t *)(v48 + 36) = v127;
    *(uint32_t *)(v48 + 40) = v128;
    *(uint32_t *)(v48 + 44) = v129;
    v130 = v160;
    v131 = v161;
    *(uint32_t *)(v48 + 48) = v159;
    *(uint32_t *)(v48 + 52) = v130;
    *(uint32_t *)(v48 + 56) = v131;
    *(uint8_t *)(v48 + 56) = v50;
    *(uint32_t *)(v48 + 44) = v51;
    *(uint8_t *)v48 = v49;
    if ( v123 == v51 )
      goto LABEL_68;
  }
  else
  {
    v74 = v148;
    v75 = v149;
    v76 = v150;
    *(uint32_t *)v47 = v147;
    *(uint32_t *)(v47 + 4) = v74;
    *(uint32_t *)(v47 + 8) = v75;
    *(uint32_t *)(v47 + 12) = v76;
    v77 = v152;
    v78 = v153;
    v79 = v154;
    *(uint32_t *)(v47 + 16) = v151;
    *(uint32_t *)(v47 + 20) = v77;
    *(uint32_t *)(v47 + 24) = v78;
    *(uint32_t *)(v47 + 28) = v79;
    v80 = v156;
    v81 = v157;
    v82 = v158;
    *(uint32_t *)(v47 + 32) = v155;
    *(uint32_t *)(v47 + 36) = v80;
    *(uint32_t *)(v47 + 40) = v81;
    *(uint32_t *)(v47 + 44) = v82;
    v83 = v160;
    v84 = v161;
    *(uint32_t *)(v47 + 48) = v159;
    *(uint32_t *)(v47 + 52) = v83;
    *(uint32_t *)(v47 + 56) = v84;
    *(uint8_t *)(v47 + 56) = v50;
    *(uint32_t *)(v47 + 44) = v51;
    ++*((uint16_t *)v1 + 2);
    *(uint8_t *)v47 = 1;
    v85 = *((uint8_t *)v51 + 2);
    if ( v85 <= 1 )
    {
      v63 = *(uint8_t *)(v47 + 8);
      if ( !*(uint8_t *)(v47 + 8) )
      {
        if ( (**(uint16_t **)off_137BB8 & 8) == 0 )
          goto LABEL_68;
        v64 = dword_137BBC;
        goto LABEL_67;
      }
      v86 = *(uint16_t **)off_137BB8;
      ++*(uint16_t *)(dword_137BB4 + 2 * v85 + 4);
      if ( (*v86 & 8) == 0 )
        goto LABEL_68;
      goto LABEL_83;
    }
  }
LABEL_64:
  if ( (**(uint16_t **)off_137938 & 8) != 0 )
  {
    v63 = *(uint8_t *)(v48 + 8);
    if ( !*(uint8_t *)(v48 + 8) )
    {
      v51 = *(uint16_t **)(v48 + 44);
      v50 = *(char *)(a1 + 9);
      v64 = dword_13793C;
LABEL_67:
      sub_12E948(
        dword_137940,
        *((uint16_t *)v1 + 2),
        *v51,
        v45,
        *(uint8_t *)(a1 + 12),
        *(uint16_t *)(a1 + 34) >> 4,
        v50,
        v63,
        v64);
      goto LABEL_68;
    }
LABEL_83:
    v64 = v48 + 9;
    if ( sub_143D00(v48 + 9) )
    {
      v63 = *(uint8_t *)(v48 + 8);
      *(uint8_t *)(v48 + v63 + 9) = 0;
      v51 = *(uint16_t **)(v48 + 44);
      v50 = *(char *)(a1 + 9);
    }
    else
    {
      v51 = *(uint16_t **)(v48 + 44);
      v50 = *(char *)(a1 + 9);
      v64 = dword_137BBC;
      v63 = *(uint8_t *)(v48 + 8);
    }
    goto LABEL_67;
  }
LABEL_68:
  v65 = 0;
  *(uint8_t *)(v48 + 57) = 0;
  *(uint8_t *)(v48 + 58) = 0;
  v66 = (uint16_t *)off_137944;
  if ( v1[4029] )
  {
    v67 = off_137944;
    while ( 2 )
    {
      v68 = *((uint8_t *)v67 + 3906);
      if ( *((uint8_t *)v67 + 3906) )
      {
        v69 = *((uint8_t *)v66 + 4028);
        if ( v69 <= 8 )
        {
          v70 = *(uint8_t *)(v67[975] + 1);
          v145 = *(uint32_t *)(v48 + 2);
          v146 = *(uint16_t *)(v48 + 6);
          v71 = (1 << v69) - 1;
          v72 = (uint16_t)(v146 ^ ((*(uint16_t *)(v48 + 6) + (v68 << 8)) ^ v146) & ((uint16_t)v71 << 8));
          v146 ^= ((*(uint16_t *)(v48 + 6) + (v68 << 8)) ^ v146) & (uint16_t)((uint16_t)v71 << 8);
          v73 = v66;
          do
          {
            if ( *((uint8_t *)v73 + 8)
              && v73[5] == (uint16_t)v145
              && __PAIR64__(v73[7], v73[6]) == __PAIR64__(v72, HIWORD(v145)) )
            {
              goto LABEL_77;
            }
            v73 += 30;
          }
          while ( v66 + 1920 != v73 );
          v100 = sub_1374B0((uint16_t *)&v145, 1);
          if ( !v100 )
            break;
          v101 = *(uint32_t *)(v48 + 4);
          v102 = *(uint32_t *)(v48 + 8);
          v103 = *(uint32_t *)(v48 + 12);
          *(uint32_t *)v100 = *(uint32_t *)v48;
          *(uint32_t *)(v100 + 4) = v101;
          *(uint32_t *)(v100 + 8) = v102;
          *(uint32_t *)(v100 + 12) = v103;
          v104 = *(uint32_t *)(v48 + 20);
          v105 = *(uint32_t *)(v48 + 24);
          v106 = *(uint32_t *)(v48 + 28);
          *(uint32_t *)(v100 + 16) = *(uint32_t *)(v48 + 16);
          *(uint32_t *)(v100 + 20) = v104;
          *(uint32_t *)(v100 + 24) = v105;
          *(uint32_t *)(v100 + 28) = v106;
          v107 = *(uint32_t *)(v48 + 36);
          v108 = *(uint32_t *)(v48 + 40);
          v109 = *(uint32_t *)(v48 + 44);
          *(uint32_t *)(v100 + 32) = *(uint32_t *)(v48 + 32);
          *(uint32_t *)(v100 + 36) = v107;
          *(uint32_t *)(v100 + 40) = v108;
          *(uint32_t *)(v100 + 44) = v109;
          v110 = *(uint32_t *)(v48 + 52);
          v111 = *(uint32_t *)(v48 + 56);
          *(uint32_t *)(v100 + 48) = *(uint32_t *)(v48 + 48);
          *(uint32_t *)(v100 + 52) = v110;
          *(uint32_t *)(v100 + 56) = v111;
          *(uint32_t *)(v100 + 2) = v145;
          LOWORD(v109) = v146;
          *(uint8_t *)(v100 + 8) = v70;
          v112 = v67[975];
          *(uint16_t *)(v100 + 6) = v109;
          if ( v70 )
          {
            v113 = v70 + 8 + v100;
            v114 = v112 - 6 - v100;
            v115 = v100 + 8;
            do
            {
              *(uint8_t *)(v115 + 1) = *(uint8_t *)(v114 + v115);
              ++v115;
            }
            while ( v115 != v113 );
          }
          v116 = v66[2];
          *(uint8_t *)(v100 + 58) = v69;
          v117 = (uint16_t)(v116 + 1);
          v118 = *((uint8_t *)v67 + 3906);
          v66[2] = v117;
          *(uint8_t *)v100 = 1;
          v119 = (uint16_t **)off_137BB8;
          *(uint8_t *)(v100 + 57) = v118;
          if ( (**v119 & 8) == 0 )
          {
LABEL_77:
            ++v65;
            v67 += 2;
            if ( v65 < *((uint8_t *)v66 + 4029) )
              continue;
            break;
          }
          *(uint8_t *)(*(uint8_t *)(v48 + 8) + v100 + 9) = 0;
          sub_12E948(dword_137BC0, v117, **(uint16_t **)(v100 + 44), *(uint8_t *)(v100 + 8), v100 + 9);
          ++v65;
          v67 += 2;
          if ( v65 < *((uint8_t *)v66 + 4029) )
            continue;
        }
      }
      break;
    }
  }
LABEL_78:
  if ( v139 )
    return 0;
  sub_12C8E0(a1, 4100, 13, 4);
  return 1;
}

