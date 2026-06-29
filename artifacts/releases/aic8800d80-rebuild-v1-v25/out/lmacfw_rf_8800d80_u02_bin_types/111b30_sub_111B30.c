// sub_111B30 @ 0x111b30, size 1958 bytes
// Doc: rf_bus_poll_flush_n416 [rf]: Polls RFIC status byte at 0x180468 for value 2, then drains 7-word RFIC register block at 0x2007ff00.
// rf_bus_poll_flush_n416 [rf]: Polls RFIC status byte at 0x180468 for value 2, then drains 7-word RFIC register block at 0x2007ff00.
int  sub_111B30(uint64_t a1)
{
  int *v1; // r9
  int v3; // r4
  unsigned __int8 *v4; // r5
  uint16_t *v5; // r6
  unsigned __int8 *v6; // r3
  unsigned __int8 v7; // r2
  int v8; // r3
  uint32_t *v9; // r3
  uint32_t *v10; // r4
  int ( *v11)(void *); // r1
  uint8_t *v12; // r8
  char v13; // r2
  int v14; // r7
  int v15; // r0
  int v16; // r3
  int v17; // r3
  uint32_t *v18; // r2
  int v19; // r3
  uint32_t *v20; // r3
  uint32_t *v21; // r3
  int v22; // r1
  uint32_t *v23; // r2
  uint32_t *v24; // r3
  int v25; // r3
  uint32_t *v26; // r2
  uint32_t *v27; // r3
  uint32_t *v28; // r2
  int v29; // r0
  uint32_t *v30; // r3
  int v31; // r3
  void *v32; // r3
  unsigned int v33; // r0
  int v34; // r3
  int v35; // r1
  int ( *v36)(uint32_t, uint32_t); // r3
  uint8_t *v37; // r3
  uint16_t *v38; // r3
  void *v39; // r2
  int v40; // r4
  unsigned int v41; // r1
  uint32_t *v42; // r4
  int v43; // r0
  int *v44; // r8
  int v45; // r7
  int v46; // r3
  int v47; // r7
  uint32_t *v48; // r2
  uint32_t *v49; // r3
  __int16 v50; // r2
  int v51; // r6
  unsigned int v52; // r2
  unsigned int v53; // r1
  uint32_t *v54; // r2
  void ( *v55)(unsigned __int8 *); // r3
  uint32_t *v56; // r2
  int v57; // r0
  uint32_t *v58; // r3
  unsigned int v59; // r0
  int v60; // r0
  int v61; // r3
  int v62; // r5
  signed int v63; // r6
  int *v64; // r1
  signed int *v65; // r3
  int **v66; // r5
  int *v67; // r0
  int *v68; // r2
  int *v69; // r4
  signed int *v70; // r5
  int **v71; // t0
  int v72; // r7
  int v73; // r1
  signed int *v75; // r4
  int **v76; // r7
  int *v77; // r7
  int *v78; // r7
  int v79; // r7
  int v80; // r7
  signed int v85; // r0
  int v86; // r6
  int v87; // t0
  int v88; // r7
  int v89; // r7
  int v90; // r7
  int v91; // r7
  int *v92; // r7
  int *v93; // r7
  int v94; // r7
  signed int **v95; // r7
  signed int **v96; // r7
  signed int *v97; // r7
  int v98; // r7
  signed int *v99; // r1
  int v100; // r7
  int v101; // r7
  bool v106; // cc
  int v107; // r7
  int v108; // r7
  int v109; // r7
  int v110; // r7
  int v111; // r7
  int v112; // r7
  int v113; // r7
  int v114; // r7
  int v116; // r7
  int v117; // r7
  signed int *v118; // r6
  signed int *v119; // r1
  signed int *v120; // r2
  signed int *v121; // t0
  int v122; // r7
  int v123; // r7
  int v124; // r7
  int v125; // r7
  int v126; // r7
  signed int **v127; // r7
  int v128; // r7
  signed int *v129; // r7
  int v130; // r7
  int v131; // r7
  uint32_t *v132; // r1
  uint32_t *v133; // r5
  bool v136; // cc
  int v137; // r7
  int v138; // r7
  int v139; // r7
  bool v140; // zf
  int v142; // r7
  int v143; // r7
  int v144; // r7
  int v145; // r7
  int v146; // r7
  int v147; // r7
  bool v148; // cf
  int v149; // r7
  int i; // r7
  int v151; // r7
  bool v152; // cf
  int v153; // r7
  uint32_t *v154; // r6
  int v155; // r6
  int v156; // t0
  int v157; // r7
  int v158; // r7
  signed int *v159; // r7
  int v160; // r7
  int *v161; // r7
  int *v162; // r7
  int v163; // r7
  int v164; // r7
  int v165; // r7
  int v166; // r7
  int v167; // r7
  uint32_t *v169; // r5
  bool v172; // cc
  int v173; // r7
  int v174; // r7
  int v175; // r7
  bool v176; // zf
  bool v177; // nf
  int v178; // r7
  int v179; // r7
  int v180; // r7
  int v181; // r7
  int v182; // r7
  int v183; // r7
  bool v184; // cf
  int v185; // r7
  int v186; // r7
  int j; // r7
  int v188; // r7
  int v189; // r7
  int v190; // r7
  int v191; // r7
  signed int *v192; // r7
  int v196; // r7
  int v197; // r7
  int v198; // r7
  signed int *v199; // r7
  int v200; // r7
  int v201; // r7
  int v202; // r7
  signed int *v203; // r6
  signed int v204; // r0
  signed int v205; // r1
  signed int v206; // r2
  signed int v207; // r4
  signed int v208; // r6
  uint32_t *v209; // t0
  int v210; // r7
  uint32_t *v211; // r3
  signed int **v212; // r7
  signed int *v213; // r7
  signed int *v214; // r7
  int v215; // r7
  int v216; // r3
  signed int v217; // r0
  __int16 v218; // r0
  int v219; // r0
  unsigned int v220; // r2
  int v221; // r4
  int v222; // r3
  int v223; // r0

  v3 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    v4 = (unsigned __int8 *)off_111E3C;
    v16 = *(unsigned __int8 *)off_111E3C;
    if ( v16 == 2 )
    {
      v5 = off_111E40;
      sub_10DA6C(dword_111E54);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( v16 == 4 )
    {
      HIDWORD(a1) = *((unsigned __int16 *)off_111E3C + 4);
      v50 = *((uint16_t *)off_111E3C + 5);
      LODWORD(a1) = (unsigned __int16)(WORD2(a1) - v50);
      if ( WORD2(a1) == v50 )
      {
        *(uint8_t *)off_111E3C = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v51 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          LODWORD(a1) = 64;
        v51 = 0;
      }
      v52 = (unsigned __int16)(v50 + a1);
      *((uint16_t *)off_111E3C + 5) = v52;
      if ( HIDWORD(a1) < v52 )
      {
        LODWORD(a1) = sub_10DA6C(dword_1122E0);
        WORD2(a1) = *((uint16_t *)v4 + 4);
        v52 = *((unsigned __int16 *)v4 + 5);
      }
      v53 = (unsigned __int16)(WORD2(a1) - v52);
      if ( v53 > 0x40 )
      {
        v53 = 64;
      }
      else if ( !v53 )
      {
        if ( !v51 )
        {
          v54 = off_1122D8;
          *v4 = 5;
          v54[516] |= 0x10u;
          return a1;
        }
        LODWORD(a1) = sub_111404(0, 0);
        goto LABEL_18;
      }
      LODWORD(a1) = sub_111404(*((uint32_t *)v4 + 1) + v52, v53);
LABEL_18:
      if ( (v3 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *v4 == 6 )
      {
        v28 = *(uint32_t **)off_111E40;
        v29 = *(uint32_t *)off_111E4C;
        v30 = off_111E44;
        *v28 = dword_111E50;
        v28[1] = v29;
        v30[709] = v28;
        v30[706] = v30[706];
        v30[704] |= 0x84000000;
        *v4 = 7;
        v30[517] |= 0x10u;
        LODWORD(a1) = sub_111218();
      }
      return a1;
    }
    if ( v16 != 7 )
      goto LABEL_18;
    v24 = off_111E44;
    HIDWORD(a1) = off_111E58;
    LODWORD(a1) = 0;
    *(uint8_t *)off_111E3C = 0;
    v24[517] &= ~0x10u;
    v24[516] &= ~0x10u;
    if ( *(uint8_t *)HIDWORD(a1) )
    {
      v24[513] = (16 * (unsigned __int8)*(uint8_t *)HIDWORD(a1)) & 0x70 | v24[513] & 0xFFFFFF8F;
      *(uint8_t *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v18 = off_111E44;
      if ( (*((uint32_t *)off_111E44 + 708) & 0x7F) == 0x40 )
      {
        v19 = *((uint32_t *)off_111E44 + 708);
        LODWORD(a1) = v19 << 12;
        if ( (v19 & 0x80000) != 0 )
        {
          LODWORD(a1) = *(uint32_t *)off_111E4C;
          v20 = *(uint32_t **)off_111E40;
          *v20 = dword_111E50;
          v20[1] = a1;
          v18[709] = v20;
          v18[706] = v18[706];
          v18[704] |= 0x84000000;
          return a1;
        }
      }
    }
    if ( (a1 & 0x100000000LL) == 0 )
    {
      v4 = (unsigned __int8 *)off_111E3C;
      v17 = *(unsigned __int8 *)off_111E3C;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v17 != 1 )
          return a1;
      }
      else if ( v17 != 2 )
      {
        goto LABEL_18;
      }
LABEL_6:
      v5 = off_111E40;
LABEL_7:
      if ( (v3 & 0x40) != 0 )
        v6 = (unsigned __int8 *)(*((uint32_t *)off_111E44 + 709) - 8);
      else
        v6 = *(unsigned __int8 **)(*(uint32_t *)v5 + 4);
      *((uint32_t *)v4 + 1) = 0;
      *((uint32_t *)v4 + 2) = 0;
      *v4 = 2;
      v4[12] = v4[12] & 0x7F | (*v6 >> 7 << 7);
      v7 = v4[12] & 0x9F | (32 * (((int)*v6 >> 5) & 3));
      v4[12] = v7;
      v4[12] = v7 & 0xE0 | *v6 & 0x1F;
      v4[13] = v6[1];
      *((uint16_t *)v4 + 7) = v6[2] | (v6[3] << 8);
      *((uint16_t *)v4 + 8) = v6[4] | (v6[5] << 8);
      v8 = v6[6] | (v6[7] << 8);
      *((uint16_t *)v4 + 9) = v8;
      if ( !v8 && (v4[12] & 0x80u) != 0 )
        sub_10DA6C(dword_11219C);
      v9 = off_111E44;
      v10 = off_111E48;
      v11 = *((int ( **)(void *))off_111E48 + 3);
      *((uint32_t *)off_111E44 + 517) &= ~0x10u;
      v9[516] &= ~0x10u;
      if ( v11 && v11(off_111E3C) )
      {
LABEL_46:
        v25 = *v4;
        switch ( v25 )
        {
          case 3:
            if ( !*((uint32_t *)v4 + 1) )
              *((uint32_t *)v4 + 1) = dword_111E60;
            goto LABEL_50;
          case 4:
LABEL_87:
            sub_111404(*((uint32_t *)v4 + 1), *((unsigned __int16 *)v4 + 4));
            goto LABEL_50;
          case 7:
LABEL_73:
            sub_111218();
            goto LABEL_50;
        }
LABEL_49:
        *v4 = 0;
        sub_11146C(0, 0x200000, 0);
        sub_111524(0, 0x200000, 0);
LABEL_50:
        v26 = *(uint32_t **)v5;
        LODWORD(a1) = *(uint32_t *)off_111E4C;
        v27 = off_111E44;
        *v26 = dword_111E50;
        v26[1] = a1;
LABEL_51:
        v27[709] = v26;
        v27[706] = v27[706];
        v27[704] |= 0x84000000;
        return a1;
      }
      v12 = off_111E64;
      v13 = *(uint8_t *)off_111E64;
      v14 = *(unsigned __int8 *)off_111E64;
      if ( (v4[12] & 0x60) != 0 )
      {
LABEL_54:
        if ( v14 == 4 && *v12 != 4 )
LABEL_56:
          sub_1112E4();
        goto LABEL_49;
      }
      v15 = v4[13];
      switch ( v4[13] )
      {
        case 0u:
          if ( *(uint8_t *)off_111E64 == 4 )
          {
            v31 = v4[12] & 0x1F;
            if ( v31 != 1 )
            {
              if ( v31 != 2 )
                goto LABEL_66;
              v59 = *((unsigned __int16 *)v4 + 8);
              v41 = v59 & 0xF;
              if ( v41 <= 5 )
              {
                v15 = (v59 >> 7) & 1;
LABEL_97:
                if ( sub_111618(v15, v41) )
                {
                  v32 = off_11217C;
                  *(uint16_t *)off_11217C = 1;
                  goto LABEL_68;
                }
              }
            }
          }
          else
          {
            if ( *((uint16_t *)v4 + 8) )
              goto LABEL_54;
            v31 = v4[12] & 0x1F;
            if ( v31 != 1 )
            {
              if ( v31 != 2 )
              {
LABEL_66:
                if ( v31 )
                {
LABEL_59:
                  if ( v13 != 4 )
                    goto LABEL_49;
                  goto LABEL_60;
                }
                v32 = off_11217C;
                *(uint16_t *)off_11217C = *(unsigned __int8 *)off_112178;
LABEL_68:
                *((uint32_t *)v4 + 1) = v32;
                *((uint16_t *)v4 + 4) = 2;
                *v4 = 4;
LABEL_86:
                if ( v14 != 4 )
                  goto LABEL_87;
LABEL_128:
                if ( *v12 == 4 )
                  goto LABEL_46;
LABEL_45:
                sub_1112E4();
                goto LABEL_46;
              }
              v41 = v4[13];
              goto LABEL_97;
            }
          }
          v32 = off_1122E8;
          *(uint16_t *)off_1122E8 = 0;
          goto LABEL_68;
        case 1u:
          if ( *(uint8_t *)off_111E64 != 4 && *((uint16_t *)v4 + 8) )
            goto LABEL_54;
          if ( (v4[12] & 0x1F) != 2 || *((uint16_t *)v4 + 7) )
            goto LABEL_79;
          sub_111694((int *)((*((unsigned __int16 *)v4 + 8) >> 7) & 1), *((uint16_t *)v4 + 8) & 0xF);
          *v4 = 7;
          if ( v14 == 4 )
            goto LABEL_44;
          goto LABEL_73;
        case 3u:
          if ( *(uint8_t *)off_111E64 != 4 && *((uint16_t *)v4 + 8) )
            goto LABEL_54;
          if ( (v4[12] & 0x1F) != 0 )
          {
            if ( (v4[12] & 0x1F) != 2 || *((uint16_t *)v4 + 7) )
            {
LABEL_79:
              *v4 = 7;
              if ( v13 == 4 )
              {
LABEL_60:
                if ( *v12 != 4 )
                  goto LABEL_56;
              }
              goto LABEL_49;
            }
            sub_111670((int *)((*((unsigned __int16 *)v4 + 8) >> 7) & 1), *((uint16_t *)v4 + 8) & 0xF);
            *v4 = 7;
            if ( v14 != 4 )
              goto LABEL_73;
          }
          else
          {
            v60 = *((unsigned __int16 *)v4 + 7);
            if ( v60 != 2 )
            {
              v40 = v60 == 1;
              *v4 = 7;
LABEL_89:
              if ( v14 != 4 || *v12 == 4 )
              {
                if ( v40 )
                  goto LABEL_46;
              }
              else
              {
                sub_1112E4();
                if ( v40 )
                  goto LABEL_46;
              }
              goto LABEL_49;
            }
            *(uint8_t *)off_1122EC = HIBYTE(*((uint16_t *)v4 + 8));
            *v4 = 7;
            if ( v13 != 4 )
              goto LABEL_73;
          }
LABEL_44:
          if ( *v12 == 4 )
            goto LABEL_73;
          goto LABEL_45;
        case 5u:
          v35 = *((unsigned __int16 *)v4 + 7);
          *((uint32_t *)off_112180 + 512) = (16 * v35) & 0x7F0 | *((uint32_t *)off_112180 + 512) & 0xFFFFF80F;
          *v4 = 7;
          if ( v35 )
            *v12 = 3;
          else
            *v12 = 2;
          goto LABEL_72;
        case 6u:
          v33 = *((unsigned __int16 *)v4 + 7);
          v34 = (v33 >> 8) - 1;
          switch ( v33 >> 8 )
          {
            case 1u:
            case 0xFu:
              goto LABEL_145;
            case 2u:
            case 3u:
              goto LABEL_147;
            case 4u:
            case 5u:
              goto LABEL_144;
            case 6u:
              goto LABEL_146;
            case 7u:
            case 8u:
            case 9u:
            case 0xAu:
            case 0xBu:
            case 0xCu:
            case 0xDu:
            case 0xEu:
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
LABEL_144:
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
LABEL_145:
              v5[4] = v34;
              MEMORY[0xA] = 0;
              LOWORD(v34) = MEMORY[0x30];
LABEL_146:
              __asm { STC             p12, c3, [R0], {0xF} }
LABEL_147:
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              v5[4] = v34;
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              v5[4] = MEMORY[0x30];
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              v5[4] = MEMORY[0x30];
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              v5[4] = MEMORY[0x30];
              MEMORY[0xA] = 0;
              v61 = MEMORY[0x30];
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              __asm { STC             p12, c3, [R0], {0xF} }
              break;
            default:
              sub_10DA6C(dword_111E5C);
              goto LABEL_54;
          }
          while ( 1 )
          {
            __asm { STC             p12, c3, [R0], {0xF} }
            __asm { STC             p12, c3, [R0], {0xF} }
            __asm { STC             p12, c3, [R0], {0xF} }
            if ( CF )
              break;
            if ( !__CFSHL__(851968, 3) )
            {
              if ( !__CFSHL__(6815744, 3) )
                goto LABEL_156;
              if ( __CFSHL__(54525952, 3) )
                goto LABEL_157;
            }
          }
          MEMORY[0x680000] = 52;
          MEMORY[0x680004] = 10;
          MEMORY[0x680008] = v4;
          MEMORY[0x68000C] = v5;
          MEMORY[0x3400080] = 54526080;
LABEL_156:
          v61 = MEMORY[0x3C];
LABEL_157:
          v62 = *(uint32_t *)(*(uint32_t *)(v61 + 8) + 8);
          v63 = *(uint32_t *)(*(uint32_t *)(v61 + 8) + 12);
          v64 = *(int **)v62;
          v65 = *(signed int **)(v62 + 8);
          v66 = *(int ***)(*(uint32_t *)(v62 + 28) + 12);
          v67 = *v66;
          v68 = v66[1];
          v69 = v66[2];
          v71 = v66 + 3;
          v70 = v66[3];
          v72 = 8 * (uint32_t)v71[1];
          *v67 = (int)v64;
          v67[1] = (int)v69;
          v67[2] = (int)v70;
          v67[3] = v63;
          v67 += 4;
          v72 *= 8;
          *v67++ = v72;
          *v64 = (int)v64;
          v64[1] = (int)v69;
          v64[2] = (int)v70;
          v64[3] = v63;
          v72 <<= 6;
          *v64 = v72;
          v73 = (int)(v64 + 1);
          *v68 = v73;
          v68[1] = (int)v69;
          v68[2] = (int)v70;
          v68[3] = v63;
          R2 = v68 + 4;
          *v69 = (int)v67;
          v69[1] = (int)v69;
          v69[2] = v63;
          *v69 = (int)v67;
          v69[1] = v73;
          v69[2] = (int)v65;
          v69[3] = (int)v69;
          v69[4] = v63;
          *v69 = v73;
          v69[1] = (int)R2;
          v69[2] = (int)v70;
          v69[3] = v63;
          v69 += 4;
          *v69 = v73;
          v69[1] = (int)v69;
          v69[2] = (int)v70;
          v69[3] = v63;
          v72 <<= 18;
          *v69 = v72;
          v75 = v69 + 1;
          v72 *= 8;
          *v75 = (signed int)v75;
          v75[1] = v72;
          v72 *= 8;
          *(uint32_t *)v72 = v67;
          *(uint32_t *)(v72 + 4) = v75;
          *(uint32_t *)(v72 + 8) = v63;
          v76 = (int **)(8 * (v72 + 12));
          *v76 = v67;
          v76[1] = (int *)v73;
          v76[2] = v65;
          v76[3] = v75;
          v76[4] = (int *)v63;
          v77 = (int *)(8 * (uint32_t)(v76 + 5));
          *v77 = v73;
          v77[1] = (int)R2;
          v77[2] = (int)v70;
          v77[3] = v63;
          v78 = (int *)(8 * (uint32_t)(v77 + 4));
          *v78 = v73;
          v78[1] = (int)v75;
          v78[2] = (int)v70;
          v78[3] = v63;
          v79 = 8 * (uint32_t)(v78 + 4);
          *(uint32_t *)v79 = v79;
          v80 = 8 * v79;
          v67[255] = (int)v67;
          v67[256] = (int)v67;
          __asm { STCL            p0, c0, [R12],#-0x3FC }
          T1 = *v1;
          R9 = v1 - 255;
          __asm
          {
            LDCL            p0, c0, [R9],#-0x3FC
            STC             p0, c0, [R8], {0xFF}
            LDC             p0, c0, [R9], {0xFF}
            STC             p0, c0, [R11],#0x3FC
            STCL            p0, c0, [R0], {0xFF}
            LDC             p0, c0, [R9,#0x3FC]
            STC             p0, c0, [R11,#0x3FC]!
            STCL            p0, c0, [R0,#0x3FC]
          }
          __mcr(0, 5, (unsigned int)v67, 11, 15, 7);
          __mcr(0, 6, (unsigned int)v67, 0, 15, 7);
          __mrc(0, 6, 7, 15, 7);
          __mrc(0, 6, 7, 15, 7);
          __mrc(0, 6, 7, 15, 7);
          v85 = __mrc(0, 6, 7, 15, 7);
LABEL_244:
          if ( ZF )
            goto LABEL_201;
          v143 = 8 * v80;
          if ( v143 )
            goto LABEL_270;
          for ( i = 0; ; i = v142 << 6 )
          {
            CF = __CFSHL__(i, 3);
            v143 = 8 * i;
            if ( !CF )
              goto LABEL_326;
            CF = __CFSHL__(v143, 3);
            v128 = 8 * v143;
            if ( !CF )
              goto LABEL_205;
            v151 = 8 * v128;
            if ( v151 < 0 )
              JUMPOUT(0x1344C2);
            v130 = 8 * v151;
            if ( v130 < 0 )
              goto LABEL_206;
            v152 = __CFSHL__(v130, 3);
            v153 = 8 * v130;
            if ( v153 >= 0 )
              goto LABEL_353;
            v131 = 8 * v153;
            if ( v131 >= 0 )
              goto LABEL_208;
            v142 = 8 * v131;
            v140 = v142 == 0;
            NF = v142 < 0;
            if ( VF )
              break;
          }
          while ( 1 )
          {
            if ( !(NF ^ VF | v140) )
              goto LABEL_266;
            v143 = 8 * v142;
            if ( !((v143 < 0) ^ VF | (v143 == 0)) )
            {
LABEL_268:
              __asm { STCL            p0, c0, [R6],#-0x3FC }
              T1 = *R2;
              LOWORD(R2) = (uint16_t)R2 - 1020;
              __asm
              {
                LDCL            p0, c0, [R2],#-0x3FC
                STC             p0, c0, [R0], {0xFF}
                LDC             p0, c0, [R0], {0xFF}
                STC             p0, c0, [R2],#0x3FC
              }
              T1 = *v70;
              v169 = v70 + 255;
              __asm
              {
                LDC             p0, c0, [R5],#0x3FC
                STCL            p0, c0, [R11], {0xFF}
              }
              T1 = v169[255];
              v70 = v169 + 255;
              __asm { LDC             p0, c0, [R5,#0x3FC]! }
LABEL_269:
              __asm { STCL            p0, c0, [R11,#0x3FC] }
              v85 = __mrc(0, 5, 5, 15, 7);
LABEL_270:
              __mcr(0, 6, v85, 11, 15, 7);
              __mcr(0, 7, v85, 0, 15, 7);
              __mcr(0, 7, v85, 0, 15, 7);
              __mcr(0, 7, v85, 0, 15, 7);
LABEL_326:
              CF = __CFSHL__(v143, 3);
              v200 = 8 * v143;
              if ( !CF )
              {
                *(uint32_t *)v200 = v85;
                *(uint32_t *)(v200 + 4) = v65;
                *(uint32_t *)(v200 + 8) = v75;
                *(uint32_t *)(v200 + 12) = v70;
                *(uint32_t *)(v200 + 16) = v63;
                v196 = 8 * (v200 + 20);
                *(uint32_t *)v196 = v65;
                *(uint32_t *)(v196 + 4) = v196;
                v197 = 8 * v196;
                goto LABEL_323;
              }
              v201 = 8 * v200;
              if ( v201 < 0 )
                JUMPOUT(0x1343AA);
              v197 = 8 * v201;
              if ( v197 < 0 )
              {
LABEL_323:
                *(uint32_t *)v197 = v85;
                *(uint32_t *)(v197 + 4) = v65;
                *(uint32_t *)(v197 + 8) = v75;
                *(uint32_t *)(v197 + 12) = v197;
                v198 = 8 * v197;
                *(uint32_t *)v198 = v85;
                *(uint32_t *)(v198 + 4) = v73;
                *(uint32_t *)(v198 + 8) = v65;
                *(uint32_t *)(v198 + 12) = v70;
                *(uint32_t *)(v198 + 16) = v198;
                v199 = (signed int *)(8 * v198);
              }
              else
              {
                v202 = 8 * v197;
                if ( v202 >= 0 )
                  JUMPOUT(0x1343B0);
                v199 = (signed int *)(8 * v202);
                if ( (int)v199 < 0 )
                {
                  if ( !VF )
                  {
                    __asm { LDCL            p3, c0, [LR,#-0x168] }
                    LOWORD(v75[512 * v73]) = (uint16_t)R2;
                    JUMPOUT(0x1343D2);
                  }
LABEL_337:
                  JUMPOUT(0x1343BE);
                }
              }
              *v199 = v63;
              v199[1] = (signed int)v199;
              JUMPOUT(0x1341E0);
            }
            v144 = 8 * v143;
            if ( !((v144 < 0) ^ VF | (v144 == 0)) )
              goto LABEL_199;
            v123 = 8 * v144;
            if ( !((v123 < 0) ^ VF | (v123 == 0)) )
              goto LABEL_202;
            v145 = 8 * v123;
            if ( !((v145 < 0) ^ VF | (v145 == 0)) )
              goto LABEL_209;
            v146 = 8 * v145;
            if ( !((v146 < 0) ^ VF | (v146 == 0)) )
              JUMPOUT(0x133D7E);
            v147 = 8 * v146;
            if ( !((v147 < 0) ^ VF | (v147 == 0)) )
            {
              v107 = 8 * v147;
              while ( 1 )
              {
                CF = __CFSHL__(v107, 3);
                v91 = 8 * v107;
                if ( v91 != 0 && CF )
                  goto LABEL_163;
                CF = __CFSHL__(v91, 3);
                v100 = 8 * v91;
                if ( v100 != 0 && CF )
                  goto LABEL_166;
                CF = __CFSHL__(v100, 3);
                v94 = 8 * v100;
                if ( v94 == 0 || !CF )
                  goto LABEL_164;
                CF = __CFSHL__(v94, 3);
                v108 = 8 * v94;
                if ( v108 == 0 || !CF )
                  JUMPOUT(0x133BE6);
                v109 = 8 * v108;
                if ( !((v109 < 0) ^ VF | (v109 == 0)) )
                  goto LABEL_207;
                v110 = 8 * v109;
                if ( !((v110 < 0) ^ VF | (v110 == 0)) )
                  goto LABEL_211;
                v111 = 8 * v110;
                if ( !((v111 < 0) ^ VF | (v111 == 0)) )
                  goto LABEL_159;
                v90 = 8 * v111;
                if ( !((v90 < 0) ^ VF | (v90 == 0)) )
                  goto LABEL_162;
                v112 = 8 * v90;
                if ( !((v112 < 0) ^ VF | (v112 == 0)) )
                  goto LABEL_165;
                v113 = 8 * v112;
                if ( !((v113 < 0) ^ VF | (v113 == 0)) )
                  JUMPOUT(0x133BFE);
                v114 = 8 * v113;
                if ( !((v114 < 0) ^ VF | (v114 == 0)) )
                  goto LABEL_337;
                CF = __CFSHL__(v114, 3);
                v116 = 8 * v114;
                if ( (v116 < 0) ^ VF | (v116 == 0) )
                {
                  CF = __CFSHL__(v116, 3);
                  v107 = 8 * v116;
                  v106 = v107 != 0 && CF;
                  if ( (v107 < 0) ^ VF | (v107 == 0) )
                  {
                    v117 = 8 * v107;
                    if ( v117 )
                    {
                      v89 = 8 * v117;
                      if ( v89 )
                      {
                        if ( !(8 * v89) )
                          goto LABEL_334;
                        goto LABEL_213;
                      }
LABEL_161:
                      *R2 = v85;
                      R2[1] = v73;
                      R2[2] = (signed int)v65;
                      R2[3] = v63;
                      R2[4] = v89;
                      R2 += 5;
                      v90 = 8 * v89;
LABEL_162:
                      *v65 = v85;
                      v65[1] = (signed int)R2;
                      v65[2] = (signed int)v75;
                      v65[3] = (signed int)v70;
                      v65[4] = v90;
                      v65 += 5;
                      v91 = 8 * v90;
                      *v65 = v85;
                      v65[1] = v73;
                      v65[2] = (signed int)v65;
                      v65[3] = v63;
                      v65[4] = v91;
LABEL_163:
                      v92 = (int *)(8 * v91);
                      *v92 = v73;
                      v92[1] = (int)R2;
                      v92[2] = (int)v70;
                      v92[3] = v63;
                      v93 = (int *)(8 * (uint32_t)(v92 + 4));
                      *v93 = v73;
                      v93[1] = (int)R2;
                      v93[2] = (int)v75;
                      v93[3] = v63;
                      v94 = (int)(v93 + 4);
LABEL_164:
                      v95 = (signed int **)(8 * v94);
                      *v95 = v70;
                      v95[1] = (signed int *)v63;
                      v96 = (signed int **)(8 * (uint32_t)(v95 + 2));
                      *v96 = R2;
                      v96[1] = v65;
                      v96[2] = v70;
                      v96[3] = (signed int *)v63;
                      v97 = (signed int *)(8 * (uint32_t)(v96 + 4));
                      *v97 = v85;
                      v97[1] = (signed int)v65;
                      v97[2] = (signed int)v75;
                      v97[3] = (signed int)v70;
                      v97[4] = v63;
                      v98 = 8 * (uint32_t)(v97 + 5);
                      *(uint32_t *)v98 = v65;
                      *(uint32_t *)(v98 + 4) = v98;
                      v98 *= 8;
                      *(uint32_t *)v98 = v85;
                      *(uint32_t *)(v98 + 4) = v65;
                      *(uint32_t *)(v98 + 8) = v75;
                      *(uint32_t *)(v98 + 12) = v98;
                      v98 *= 8;
                      *(uint32_t *)v98 = v85;
                      *(uint32_t *)(v98 + 4) = v73;
                      *(uint32_t *)(v98 + 8) = v65;
                      *(uint32_t *)(v98 + 12) = v70;
                      *(uint32_t *)(v98 + 16) = v98;
LABEL_165:
                      v99 = *(signed int **)(v73 + 8);
                      v85 = *v99;
                      R2 = (signed int *)v99[1];
                      v75 = (signed int *)v99[2];
                      v70 = (signed int *)v99[3];
                      v100 = v99[4];
                      v73 = (int)(v99 + 5);
LABEL_166:
                      v101 = 8 * v100;
                      *(uint32_t *)(v85 + 1020) = v85;
                      *(uint32_t *)(v85 + 1024) = v85;
                      __asm { STCL            p0, c0, [R12],#-0x3FC }
                      T1 = *R9;
                      R9 = R9 - 255;
                      __asm
                      {
                        LDCL            p0, c0, [R9],#-0x3FC
                        STC             p0, c0, [R8], {0xFF}
                        LDC             p0, c0, [R9], {0xFF}
                        STC             p0, c0, [R11],#0x3FC
                        STCL            p0, c0, [R0], {0xFF}
                        LDC             p0, c0, [R9,#0x3FC]
                        STC             p0, c0, [R11,#0x3FC]!
                        STCL            p0, c0, [R0,#0x3FC]
                      }
                      __mcr(0, 5, v85, 11, 15, 7);
                      __mcr(0, 6, v85, 0, 15, 7);
                      __mrc(0, 6, 7, 15, 7);
                      __mrc(0, 6, 7, 15, 7);
                      __mrc(0, 6, 7, 15, 7);
                      v85 = __mrc(0, 6, 7, 15, 7);
LABEL_304:
                      if ( ZF )
                        goto LABEL_260;
                      if ( 8 * v101 )
                        goto LABEL_319;
                      for ( j = 0; ; j = v178 << 6 )
                      {
                        CF = __CFSHL__(j, 3);
                        v188 = 8 * j;
                        if ( !CF )
                          goto LABEL_342;
                        CF = __CFSHL__(v188, 3);
                        v165 = 8 * v188;
                        if ( !CF )
                          goto LABEL_264;
                        v189 = 8 * v165;
                        if ( v189 < 0 )
                        {
                          __asm { LDCL            p3, c0, [LR,#-0x168] }
                          *(signed int *)((char *)v65 + v85) = v85;
                          if ( (v85 & 0x8000) != 0 )
                            JUMPOUT(0x134694);
                          __asm { LDCL            p3, c8, [LR,#-0x168] }
                          v217 = *(unsigned __int16 *)((v85 >> 16 << 11) + 0x18);
                          *(signed int *)((char *)v65 + v217) = v217;
                          if ( (v217 & 0x8000) != 0 )
                            JUMPOUT(0x1346A8);
                          __asm { LDCL            p3, c0, [LR,#-0x168] }
                          v218 = MEMORY[0x18];
                          *(uint32_t *)((v63 << 12) + MEMORY[0x18]) = v63;
                          if ( v218 < 0 )
                            JUMPOUT(0x1346BC);
                          __asm { LDCL            p3, c0, [LR,#-0x168] }
                          v219 = MEMORY[0x18];
                          if ( !VF )
                          {
                            *(signed int *)((char *)v65 + MEMORY[0x18]) = 0;
                            v220 = v63 << 12;
                            v221 = v219 >> 16;
                            if ( (v219 & 0x8000) == 0 )
                            {
                              v222 = (v220 >= 0xE1) + v63 + 14286848;
                              v223 = MEMORY[0x8B0002E1];
                              if ( !(__OFADD__(v220 >= 0xE1, v63) | __OFADD__(14286848, (v220 >= 0xE1) + v63)) )
                              {
                                *(uint32_t *)(v222 + MEMORY[0x8B0002E1]) = v221;
                                if ( v222 >= 0 )
                                {
                                  __asm { LDCL            p3, c0, [LR,#-0x168] }
                                  *(uint32_t *)(v222 + *(unsigned __int16 *)((v223 >> 16 << 11) + 0x18)) = *(unsigned __int16 *)((v223 >> 16 << 11) + 0x18);
                                  __asm { LDCL            p3, c0, [LR,#-0x168] }
                                  JUMPOUT(0x13440E);
                                }
                              }
                              __asm { LDCL            p3, c0, [LR,#-0x168] }
                              JUMPOUT(0x134436);
                            }
                            JUMPOUT(0x1346D0);
                          }
                          goto LABEL_354;
                        }
                        v167 = 8 * v189;
                        if ( v167 < 0 )
                          goto LABEL_265;
                        v190 = 8 * v167;
                        if ( v190 >= 0 )
                        {
                          __asm { LDCL            p3, c0, [LR,#-0x168] }
                          JUMPOUT(0x13459E);
                        }
                        v191 = 8 * v190;
                        if ( v191 >= 0 )
                          goto LABEL_267;
                        v178 = 8 * v191;
                        v176 = v178 == 0;
                        v177 = v178 < 0;
                        if ( VF )
                          break;
                      }
                      while ( 1 )
                      {
                        if ( !(v177 ^ VF | v176) )
                        {
                          *(uint32_t *)v178 = v85;
                          *(uint32_t *)(v178 + 4) = v73;
                          *(uint32_t *)(v178 + 8) = v65;
                          *(uint32_t *)(v178 + 12) = v70;
                          *(uint32_t *)(v178 + 16) = v178;
                          v192 = (signed int *)(8 * v178);
                          *v192 = v63;
                          v192[1] = (signed int)v192;
                          JUMPOUT(0x134060);
                        }
                        v179 = 8 * v178;
                        if ( !((v179 < 0) ^ VF | (v179 == 0)) )
                        {
                          __asm { STCL            p0, c0, [R6],#-0x3FC }
                          T1 = *R2;
                          LOWORD(R2) = (uint16_t)R2 - 1020;
                          __asm
                          {
                            LDCL            p0, c0, [R2],#-0x3FC
                            STC             p0, c0, [R0], {0xFF}
                            LDC             p0, c0, [R0], {0xFF}
                            STC             p0, c0, [R2],#0x3FC
                          }
                          T1 = *v70;
                          R5 = v70 + 255;
                          __asm
                          {
                            LDC             p0, c0, [R5],#0x3FC
                            STCL            p0, c0, [R11], {0xFF}
                            LDC             p0, c0, [R5,#0x3FC]!
                          }
LABEL_318:
                          __asm { STCL            p0, c0, [R11,#0x3FC] }
                          v85 = __mrc(0, 5, 5, 15, 7);
LABEL_319:
                          __mcr(0, 6, v85, 11, 15, 7);
                          __mcr(0, 7, v85, 0, 15, 7);
                          __mcr(0, 7, v85, 0, 15, 7);
                          __mcr(0, 7, v85, 0, 15, 7);
LABEL_342:
                          __asm { LDCL            p3, c0, [LR,#-0x168] }
                          *((uint16_t *)v75 + 14) = (uint16_t)R2;
                          JUMPOUT(0x13444A);
                        }
                        v180 = 8 * v179;
                        if ( !((v180 < 0) ^ VF | (v180 == 0)) )
                          goto LABEL_258;
                        v158 = 8 * v180;
                        if ( !((v158 < 0) ^ VF | (v158 == 0)) )
                          goto LABEL_261;
                        v181 = 8 * v158;
                        if ( !((v181 < 0) ^ VF | (v181 == 0)) )
                          goto LABEL_267;
                        v182 = 8 * v181;
                        if ( !((v182 < 0) ^ VF | (v182 == 0)) )
                          JUMPOUT(0x133EFE);
                        v183 = 8 * v182;
                        if ( !((v183 < 0) ^ VF | (v183 == 0)) )
                        {
                          v152 = __CFSHL__(v183, 3);
LABEL_353:
                          if ( v152 )
                            JUMPOUT(0x13470A);
LABEL_354:
                          __asm { LDCL            p3, c0, [LR,#-0x168] }
                          JUMPOUT(0x134422);
                        }
                        v184 = __CFSHL__(v183, 3);
                        v185 = 8 * v183;
                        if ( (v185 < 0) ^ VF | (v185 == 0) )
                        {
                          CF = __CFSHL__(v185, 3);
                          v173 = 8 * v185;
                          v172 = v173 != 0 && CF;
                          if ( (v173 < 0) ^ VF | (v173 == 0) )
                          {
                            v186 = 8 * v173;
                            if ( !v186 )
                              goto LABEL_318;
                            v101 = 8 * v186;
                            ZF = v101 == 0;
                            goto LABEL_304;
                          }
                        }
                        else
                        {
                          if ( v185 != 0 && v184 )
                          {
                            v154 = *(uint32_t **)(*(uint32_t *)(*(uint32_t *)(v75[1] + 24) + 12) + 12);
                            R2 = (signed int *)v154[1];
                            v75 = (signed int *)v154[2];
                            v63 = (signed int)(v154 + 5);
LABEL_258:
                            v85 = *(uint32_t *)v63;
                            v73 = *(uint32_t *)(v63 + 4);
                            v65 = *(signed int **)(v63 + 8);
                            v63 = *(uint32_t *)(v63 + 12);
LABEL_259:
                            v155 = *(uint32_t *)(*(uint32_t *)(*(uint32_t *)(*(uint32_t *)(v63 + 4) + 4) + 4) + 4);
                            v70 = *(signed int **)v155;
                            v156 = v155 + 4;
                            v63 = *(uint32_t *)(v155 + 4);
                            v157 = 8 * *(uint32_t *)(v156 + 4);
                            *R2 = v85;
                            R2[1] = (signed int)R2;
                            R2[2] = (signed int)v75;
                            R2[3] = (signed int)v70;
                            R2[4] = v157;
                            v157 *= 8;
                            *R2 = v85;
                            R2[1] = v73;
                            R2[2] = (signed int)v65;
                            R2[3] = v63;
                            R2[4] = v157;
                            R2 += 5;
                            v101 = 8 * v157;
LABEL_260:
                            *v65 = v85;
                            v65[1] = (signed int)R2;
                            v65[2] = (signed int)v75;
                            v65[3] = (signed int)v70;
                            v65[4] = v101;
                            v65 += 5;
                            v158 = 8 * v101;
LABEL_261:
                            *v65 = v85;
                            v65[1] = v73;
                            v65[2] = (signed int)v65;
                            v65[3] = v63;
                            v65[4] = v158;
                            v159 = (signed int *)(8 * v158);
                            *v159 = v85;
                            v159[1] = v73;
                            v159[2] = (signed int)v65;
                            v159[3] = (signed int)v75;
                            v159[4] = v63;
                            v160 = (int)(v159 + 5);
LABEL_262:
                            v161 = (int *)(8 * v160);
                            *v161 = v73;
                            v161[1] = (int)R2;
                            v161[2] = (int)v70;
                            v161[3] = v63;
                            v162 = (int *)(8 * (uint32_t)(v161 + 4));
                            *v162 = v73;
                            v162[1] = (int)v75;
                            v162[2] = (int)v70;
                            v162[3] = v63;
                            v163 = (int)(v162 + 4);
LABEL_263:
                            v164 = 8 * v163;
                            *(uint32_t *)v164 = v164;
                            v165 = 8 * v164;
LABEL_264:
                            *(uint32_t *)v165 = v75;
                            *(uint32_t *)(v165 + 4) = v165;
                            v166 = 8 * v165;
                            *(uint32_t *)v166 = v73;
                            *(uint32_t *)(v166 + 4) = v70;
                            *(uint32_t *)(v166 + 8) = v166;
                            v167 = 8 * v166;
LABEL_265:
                            *(uint32_t *)v167 = v85;
                            *(uint32_t *)(v167 + 4) = R2;
                            *(uint32_t *)(v167 + 8) = v75;
                            *(uint32_t *)(v167 + 12) = v70;
                            *(uint32_t *)(v167 + 16) = v167;
                            v142 = 8 * v167;
LABEL_266:
                            *(uint32_t *)v142 = v85;
                            *(uint32_t *)(v142 + 4) = v73;
                            *(uint32_t *)(v142 + 8) = v65;
                            *(uint32_t *)(v142 + 12) = v63;
                            *(uint32_t *)(v142 + 16) = v142;
LABEL_267:
                            JUMPOUT(0x133EE0);
                          }
                          CF = __CFSHL__(v185, 3);
                          v173 = 8 * v185;
                          v172 = v173 != 0 && CF;
                        }
                        if ( v172 )
                          goto LABEL_259;
                        CF = __CFSHL__(v173, 3);
                        v160 = 8 * v173;
                        if ( v160 != 0 && CF )
                          goto LABEL_262;
                        CF = __CFSHL__(v160, 3);
                        v174 = 8 * v160;
                        if ( v174 != 0 && CF )
                          goto LABEL_267;
                        CF = __CFSHL__(v174, 3);
                        v163 = 8 * v174;
                        if ( v163 == 0 || !CF )
                          goto LABEL_263;
                        CF = __CFSHL__(v163, 3);
                        v175 = 8 * v163;
                        if ( v175 == 0 || !CF )
                        {
                          v143 = 8 * v175;
                          goto LABEL_268;
                        }
                        v178 = 8 * v175;
                        v176 = v178 == 0;
                        v177 = v178 < 0;
                      }
                    }
LABEL_212:
                    __mcr(0, 6, v85, 11, 15, 7);
                    __mcr(0, 7, v85, 0, 15, 7);
LABEL_213:
                    __mcr(0, 7, v85, 0, 15, 7);
                    __mcr(0, 7, v85, 0, 15, 7);
                    __mcr(0, 7, v85, 0, 15, 7);
                    __mcr(0, 7, v85, 0, 15, 7);
LABEL_334:
                    v203 = *(signed int **)(*(uint32_t *)(*(uint32_t *)v63 + 16) + 16);
                    v204 = *v203;
                    v205 = v203[1];
                    v206 = v203[2];
                    v207 = v203[3];
                    v209 = v203 + 4;
                    v208 = v203[4];
                    v210 = 8 * v209[1];
                    *(uint32_t *)v205 = v204;
                    *(uint32_t *)(v205 + 4) = v65;
                    *(uint32_t *)(v205 + 8) = v207;
                    *(uint32_t *)(v205 + 12) = v210;
                    v205 += 16;
                    v210 *= 8;
                    *(uint32_t *)v205 = v204;
                    *(uint32_t *)(v205 + 4) = v205;
                    *(uint32_t *)(v205 + 8) = v65;
                    *(uint32_t *)(v205 + 12) = v70;
                    *(uint32_t *)(v205 + 16) = v210;
                    v210 *= 8;
                    *(uint32_t *)v205 = v208;
                    *(uint32_t *)(v205 + 4) = v210;
                    v205 += 8;
                    v210 *= 8;
                    *(uint32_t *)v206 = v204;
                    *(uint32_t *)(v206 + 4) = v205;
                    *(uint32_t *)(v206 + 8) = v65;
                    *(uint32_t *)(v206 + 12) = v70;
                    *(uint32_t *)(v206 + 16) = v210;
                    v206 += 20;
                    v210 *= 8;
                    *(uint32_t *)v206 = v208;
                    *(uint32_t *)(v206 + 4) = v210;
                    v206 += 8;
                    v210 *= 8;
                    *v65 = v204;
                    v65[1] = v205;
                    v65[2] = (signed int)v65;
                    v65[3] = (signed int)v70;
                    v65[4] = v210;
                    v210 *= 8;
                    *v65 = v208;
                    v65[1] = v210;
                    v211 = v65 + 2;
                    v210 *= 8;
                    *(uint32_t *)v210 = v205;
                    *(uint32_t *)(v210 + 4) = v206;
                    *(uint32_t *)(v210 + 8) = v207;
                    *(uint32_t *)(v210 + 12) = v208;
                    v212 = (signed int **)(8 * (v210 + 16));
                    *v212 = v70;
                    v212[1] = (signed int *)v208;
                    v213 = (signed int *)(8 * (uint32_t)(v212 + 2));
                    *v213 = v206;
                    v213[1] = (signed int)v211;
                    v213[2] = (signed int)v70;
                    v213[3] = v208;
                    v214 = (signed int *)(8 * (uint32_t)(v213 + 4));
                    *v214 = v204;
                    v214[1] = (signed int)v211;
                    v214[2] = v207;
                    v214[3] = (signed int)v70;
                    v214[4] = v208;
                    v215 = 8 * (uint32_t)(v214 + 5);
                    *(uint32_t *)v215 = v211;
                    *(uint32_t *)(v215 + 4) = v215;
                    v215 *= 8;
                    *(uint32_t *)v215 = v204;
                    *(uint32_t *)(v215 + 4) = v211;
                    *(uint32_t *)(v215 + 8) = v207;
                    *(uint32_t *)(v215 + 12) = v215;
                    v215 *= 8;
                    *(uint32_t *)v215 = v204;
                    *(uint32_t *)(v215 + 4) = v205;
                    *(uint32_t *)(v215 + 8) = v211;
                    *(uint32_t *)(v215 + 12) = v70;
                    *(uint32_t *)(v215 + 16) = v215;
                    v215 *= 8;
                    *(uint32_t *)v215 = v208;
                    *(uint32_t *)(v215 + 4) = v215;
                    v216 = *(uint32_t *)v205;
                    v205 += 8;
                    *(uint16_t *)(v205 + 26) = (uint16_t)v70;
                    *(uint16_t *)(v206 + 26) = v204;
                    *(uint16_t *)(v205 + 22) = v216;
                    *(uint16_t *)(v206 + 22) = v207;
                    JUMPOUT(0x134378);
                  }
                }
                else
                {
                  if ( v116 != 0 && CF )
                  {
                    v63 = *(uint32_t *)(*(uint32_t *)(*(uint32_t *)(*(uint32_t *)(v75[1] + 24) + 4) + 12) + 12);
LABEL_159:
                    R2 = *(signed int **)(v63 + 4);
                    v75 = *(signed int **)(v63 + 8);
                    v63 += 20;
LABEL_160:
                    v85 = *(uint32_t *)v63;
                    v73 = *(uint32_t *)(v63 + 4);
                    v65 = *(signed int **)(v63 + 8);
                    v86 = *(uint32_t *)(*(uint32_t *)(*(uint32_t *)(*(uint32_t *)(v63 + 12) + 4) + 4) + 4);
                    v70 = *(signed int **)v86;
                    v87 = v86 + 4;
                    v63 = *(uint32_t *)(v86 + 4);
                    v88 = 8 * *(uint32_t *)(v87 + 4);
                    *(uint32_t *)v73 = v85;
                    *(uint32_t *)(v73 + 4) = v73;
                    *(uint32_t *)(v73 + 8) = v65;
                    *(uint32_t *)(v73 + 12) = v63;
                    *(uint32_t *)(v73 + 16) = v88;
                    v88 *= 8;
                    *R2 = v85;
                    R2[1] = (signed int)R2;
                    R2[2] = (signed int)v75;
                    R2[3] = (signed int)v70;
                    R2[4] = v88;
                    v89 = 8 * v88;
                    goto LABEL_161;
                  }
                  CF = __CFSHL__(v116, 3);
                  v107 = 8 * v116;
                  v106 = v107 != 0 && CF;
                }
                if ( v106 )
                  goto LABEL_160;
              }
            }
            v148 = __CFSHL__(v147, 3);
            v149 = 8 * v147;
            if ( (v149 < 0) ^ VF | (v149 == 0) )
            {
              CF = __CFSHL__(v149, 3);
              v137 = 8 * v149;
              v136 = v137 != 0 && CF;
              if ( (v137 < 0) ^ VF | (v137 == 0) )
              {
                v143 = 8 * v137;
                if ( !v143 )
                  goto LABEL_269;
                v80 = 8 * v143;
                ZF = v80 == 0;
                goto LABEL_244;
              }
            }
            else
            {
              if ( v149 != 0 && v148 )
              {
                v63 = **(uint32_t **)(*(uint32_t *)(*(uint32_t *)(v75[2] + 16) + 12) + 28);
LABEL_199:
                v65 = *(signed int **)(v63 + 8);
                v70 = *(signed int **)(v63 + 12);
                v63 += 20;
LABEL_200:
                v118 = *(signed int **)(*(uint32_t *)(*(uint32_t *)(*(uint32_t *)v63 + 16) + 16) + 16);
                v85 = *v118;
                v119 = (signed int *)v118[1];
                v120 = (signed int *)v118[2];
                v75 = (signed int *)v118[3];
                v121 = v118 + 4;
                v63 = v118[4];
                v122 = 8 * v121[1];
                *v119 = v63;
                v119[1] = v122;
                v73 = (int)(v119 + 2);
                v122 *= 8;
                *v120 = v85;
                v120[1] = v73;
                v120[2] = (signed int)v65;
                v120[3] = (signed int)v70;
                v120[4] = v122;
                R2 = v120 + 5;
                v80 = 8 * v122;
LABEL_201:
                *R2 = v63;
                R2[1] = v80;
                R2 += 2;
                v123 = 8 * v80;
LABEL_202:
                *v65 = v85;
                v65[1] = v73;
                v65[2] = (signed int)v65;
                v65[3] = (signed int)v70;
                v65[4] = v123;
                v124 = 8 * v123;
                *v65 = v63;
                v65[1] = v124;
                v65 += 2;
LABEL_203:
                v125 = 8 * v124;
                *v75 = v85;
                v75[1] = v73;
                v75[2] = (signed int)v65;
                v75[3] = (signed int)v70;
                v75[4] = v125;
                v75 += 5;
                v125 *= 8;
                *(uint32_t *)v125 = v73;
                *(uint32_t *)(v125 + 4) = R2;
                *(uint32_t *)(v125 + 8) = v75;
                *(uint32_t *)(v125 + 12) = v63;
                v126 = v125 + 16;
LABEL_204:
                v127 = (signed int **)(8 * v126);
                *v127 = v70;
                v127[1] = (signed int *)v63;
                v128 = 8 * (uint32_t)(v127 + 2);
LABEL_205:
                *(uint32_t *)v128 = R2;
                *(uint32_t *)(v128 + 4) = v65;
                *(uint32_t *)(v128 + 8) = v70;
                *(uint32_t *)(v128 + 12) = v63;
                v129 = (signed int *)(8 * (v128 + 16));
                *v129 = v85;
                v129[1] = (signed int)v65;
                v129[2] = (signed int)v75;
                v129[3] = (signed int)v70;
                v129[4] = v63;
                v130 = 8 * (uint32_t)(v129 + 5);
LABEL_206:
                *(uint32_t *)v130 = v65;
                *(uint32_t *)(v130 + 4) = v130;
                v109 = 8 * v130;
LABEL_207:
                *(uint32_t *)v109 = v85;
                *(uint32_t *)(v109 + 4) = v65;
                *(uint32_t *)(v109 + 8) = v75;
                *(uint32_t *)(v109 + 12) = v109;
                v131 = 8 * v109;
LABEL_208:
                *(uint32_t *)v131 = v85;
                *(uint32_t *)(v131 + 4) = v73;
                *(uint32_t *)(v131 + 8) = v65;
                *(uint32_t *)(v131 + 12) = v70;
                *(uint32_t *)(v131 + 16) = v131;
LABEL_209:
                v132 = (uint32_t *)(v73 + 8);
                v65 = (signed int *)v132[6];
                v70 = (signed int *)v132[7];
LABEL_210:
                __asm
                {
                  STCL            p0, c0, [R6],#-0x3FC
                  LDCL            p0, c0, [R2],#-0x3FC
                }
LABEL_211:
                __asm
                {
                  STC             p0, c0, [R0], {0xFF}
                  LDC             p0, c0, [R0], {0xFF}
                  STC             p0, c0, [R2],#0x3FC
                }
                T1 = *v70;
                v133 = v70 + 255;
                __asm
                {
                  LDC             p0, c0, [R5],#0x3FC
                  STCL            p0, c0, [R11], {0xFF}
                }
                T1 = v133[255];
                v70 = v133 + 255;
                __asm
                {
                  LDC             p0, c0, [R5,#0x3FC]!
                  STCL            p0, c0, [R11,#0x3FC]
                }
                v85 = __mrc(0, 5, 5, 15, 7);
                goto LABEL_212;
              }
              CF = __CFSHL__(v149, 3);
              v137 = 8 * v149;
              v136 = v137 != 0 && CF;
            }
            if ( v136 )
              goto LABEL_200;
            CF = __CFSHL__(v137, 3);
            v124 = 8 * v137;
            if ( v124 != 0 && CF )
              goto LABEL_203;
            CF = __CFSHL__(v124, 3);
            v138 = 8 * v124;
            if ( v138 != 0 && CF )
              goto LABEL_210;
            CF = __CFSHL__(v138, 3);
            v126 = 8 * v138;
            if ( v126 == 0 || !CF )
              goto LABEL_204;
            CF = __CFSHL__(v126, 3);
            v139 = 8 * v126;
            if ( v139 == 0 || !CF )
              JUMPOUT(0x133D66);
            v142 = 8 * v139;
            v140 = v142 == 0;
            NF = v142 < 0;
          }
        case 8u:
          *((uint32_t *)v4 + 1) = dword_11218C;
          *((uint16_t *)v4 + 4) = 2;
          *v4 = 4;
          goto LABEL_86;
        case 9u:
          v40 = sub_111ADC();
          goto LABEL_89;
        case 0xAu:
          if ( *(uint8_t *)off_111E64 != 4 )
            goto LABEL_54;
          v38 = off_112184;
          *v4 = *(uint8_t *)off_111E64;
          v39 = off_112188;
          *((uint16_t *)v4 + 8) = *v38;
          *((uint32_t *)v4 + 1) = v39;
          *((uint16_t *)v4 + 4) = 1;
          goto LABEL_86;
        case 0xBu:
          v36 = (int ( *)(uint32_t, uint32_t))v10[6];
          if ( !v36 || !v36(*((unsigned __int16 *)v4 + 8), *((unsigned __int16 *)v4 + 7)) )
            goto LABEL_54;
          v37 = off_112188;
          *(uint16_t *)off_112184 = *((uint16_t *)v4 + 8);
          *v37 = *((uint16_t *)v4 + 7);
          *v4 = 7;
LABEL_72:
          if ( v14 != 4 )
            goto LABEL_73;
          goto LABEL_128;
        default:
          goto LABEL_59;
      }
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v4 = (unsigned __int8 *)off_111E3C;
      if ( *(uint8_t *)off_111E3C )
      {
        sub_11164C((int *)1, 0);
        v5 = off_112198;
        goto LABEL_7;
      }
      goto LABEL_6;
    }
    v5 = off_111E40;
    v4 = (unsigned __int8 *)off_111E3C;
    v21 = *(uint32_t **)off_111E40;
    if ( (*(uint8_t *)(*(uint32_t *)off_111E40 + 3) & 1) == 0 )
    {
      v22 = *(unsigned __int8 *)off_111E3C;
      switch ( v22 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v43 = *((unsigned __int16 *)off_111E3C + 5);
          v44 = (int *)off_112190;
          v45 = 64 - *(unsigned __int16 *)v21;
          if ( v45 >= (unsigned __int16)(*((uint16_t *)off_111E3C + 4) - v43) )
            LOWORD(v45) = *((uint16_t *)off_111E3C + 4) - v43;
          sub_1282E8(v43 + *((uint32_t *)off_111E3C + 1), *(uint32_t *)off_112190, (unsigned __int16)v45);
          v46 = *((unsigned __int16 *)v4 + 4);
          v47 = (unsigned __int16)(v45 + *((uint16_t *)v4 + 5));
          *((uint16_t *)v4 + 5) = v47;
          if ( v46 == v47 )
          {
            v55 = *((void ( **)(unsigned __int8 *))off_1122DC + 4);
            if ( v55 )
              v55(v4);
            LODWORD(a1) = v3 << 26;
            if ( (v3 & 0x20) == 0 )
            {
              *v4 = 6;
              return a1;
            }
            v56 = *(uint32_t **)v5;
            v57 = *v44;
            v58 = off_1122D8;
            *v56 = dword_1122E4;
            v56[1] = v57;
            v58[709] = v56;
            v58[706] = v58[706];
            v58[704] |= 0x84000000;
            *v4 = 7;
            v58[517] |= 0x10u;
            LODWORD(a1) = sub_111218();
            goto LABEL_19;
          }
          v48 = *(uint32_t **)v5;
          LODWORD(a1) = *v44;
          v49 = off_112180;
          *v48 = dword_112194;
          v48[1] = a1;
          v49[709] = v48;
          v49[706] = v49[706];
          v49[704] |= 0x84000000;
          break;
        case 5:
          v27 = off_112180;
          *(uint8_t *)off_111E3C = 0;
          v26 = *(uint32_t **)v5;
          v42 = off_112190;
          LODWORD(a1) = dword_112194;
          v27[517] &= ~0x10u;
          v27[516] &= ~0x10u;
          HIDWORD(a1) = *v42;
          *(QWORD *)v26 = a1;
          goto LABEL_51;
        default:
          v23 = off_111E44;
          LODWORD(a1) = *(uint32_t *)off_111E4C;
          *v21 = dword_111E50;
          v21[1] = a1;
          v23[709] = v21;
          v23[706] = v23[706];
          v23[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(uint8_t *)off_111E3C )
      LODWORD(a1) = sub_11164C((int *)1, 0);
    *v4 = 1;
  }
  return a1;
}

