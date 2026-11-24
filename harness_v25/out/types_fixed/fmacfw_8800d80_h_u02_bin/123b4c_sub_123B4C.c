// sub_123B4C @ 0x123b4c, size 3268 bytes
int __fastcall sub_123B4C(unsigned int a1, unsigned __int8 *a2, _DWORD *a3, int a4)
{
  int v8; // r0
  __int16 **v10; // r8
  int v11; // r3
  _BYTE *v12; // r5
  _BYTE *v13; // r7
  int v14; // r6
  char v15; // r7
  unsigned int v16; // r2
  signed int v17; // r3
  unsigned int v18; // r8
  __int16 v19; // lr
  int v20; // r2
  int v21; // r3
  __int16 v22; // r1
  int v23; // r2
  int v24; // r3
  _BYTE *v25; // r0
  int v26; // r11
  int v27; // r10
  unsigned __int8 *v28; // r9
  int v29; // r0
  int v30; // r2
  int v31; // r1
  int v32; // r7
  int v33; // s16
  _DWORD *v34; // r1
  int v35; // r3
  int v36; // r12
  _DWORD *v37; // r0
  int v38; // r3
  _DWORD *v39; // r3
  int v40; // r2
  int v41; // r2
  int v42; // r2
  int v43; // r3
  _DWORD *v44; // r3
  int v45; // r2
  char *v46; // r3
  int v47; // r1
  int v48; // r0
  bool v49; // zf
  char *v50; // r5
  int v51; // r2
  unsigned int v52; // r1
  int v53; // r0
  _DWORD *v54; // r2
  int v55; // r0
  int v56; // r6
  int v57; // r2
  unsigned int v58; // r0
  _BYTE *v59; // r6
  int v60; // r1
  int v61; // r7
  unsigned __int8 *v62; // r3
  _BYTE *v63; // r2
  int v64; // r3
  int v65; // r1
  _BYTE *v66; // r2
  int v67; // r1
  unsigned __int8 *v68; // r3
  _DWORD *v69; // lr
  int v70; // r12
  _DWORD *v71; // r2
  int v72; // r0
  _DWORD *v73; // r3
  _BYTE *v74; // r3
  int v75; // r2
  unsigned __int8 *v76; // r3
  int v77; // r0
  int v78; // r7
  int *v79; // r12
  int v80; // r1
  unsigned __int8 *v81; // r3
  _DWORD *v82; // r12
  _DWORD *v83; // r2
  int v84; // r0
  int v85; // r3
  _BYTE *v86; // r8
  int v87; // r2
  _DWORD *v88; // r2
  _DWORD *v89; // r0
  int v90; // r1
  _BYTE *v91; // r8
  unsigned __int8 *v92; // r0
  int *v93; // r1
  unsigned int v94; // r12
  unsigned int v95; // r3
  _BYTE *v96; // r3
  int *v97; // r12
  unsigned int v98; // r3
  unsigned int v99; // r1
  int v100; // r6
  int v101; // r5
  int v102; // r4
  int v103; // r7
  int v104; // r0
  int v105; // r6
  int v106; // r5
  int v107; // r5
  int v108; // r4
  int v109; // r6
  int v110; // r0
  int v111; // r4
  int v112; // r0
  int v113; // r6
  int v114; // r5
  int v115; // r3
  int v116; // [sp+Ch] [bp-18h]
  unsigned __int8 *v117; // [sp+Ch] [bp-18h]
  unsigned __int8 *v118; // [sp+Ch] [bp-18h]
  char v119; // [sp+Ch] [bp-18h]
  unsigned __int8 v120; // [sp+Ch] [bp-18h]
  int v121; // [sp+10h] [bp-14h]
  int v122; // [sp+10h] [bp-14h]
  int v123; // [sp+14h] [bp-10h]
  int v124; // [sp+14h] [bp-10h]
  unsigned __int8 *(_DWORD *)(v125 + 0x20); // [sp+1Ch] [bp-8h] BYREF

  v8 = sub_12CD48((unsigned int)a3);
  if ( !v8 )
  {
    v10 = (__int16 **)off_123E50;
    v11 = **(__int16 **)off_123E50;
    if ( v11 >= 0 )
    {
      if ( a1 <= 0x3B )
      {
        if ( a1 > 5 )
        {
          switch ( a1 )
          {
            case 6u:
              goto LABEL_76;
            case 8u:
              goto LABEL_70;
            case 0xEu:
              goto LABEL_68;
            case 0x10u:
              goto LABEL_67;
            case 0x12u:
              goto LABEL_66;
            case 0x14u:
              goto LABEL_63;
            case 0x16u:
              goto LABEL_53;
            case 0x18u:
              goto LABEL_52;
            case 0x1Cu:
              goto LABEL_75;
            case 0x1Eu:
              goto LABEL_33;
            case 0x20u:
              goto LABEL_32;
            case 0x28u:
              goto LABEL_27;
            case 0x30u:
              goto LABEL_26;
            case 0x3Bu:
              goto LABEL_25;
            default:
              v13 = off_123E24;
              v14 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v13 = off_123E24;
        *((_BYTE *)off_123E24 + 48) = 0;
        v14 = sub_12BB80(*(_DWORD *)a2);
        if ( v14 )
        {
          sub_121844(*(_DWORD *)a2);
          v14 = 0;
        }
        else if ( *(_DWORD *)(v13 + 0xc4) )
        {
          *(_DWORD *)(v13 + 0xc4) = 0;
          if ( sub_126300(v125) )
            sub_12AA90(
              *(unsigned __int8 *)(*(_DWORD *)v125 + 1225),
              dword_123E28 + 38 * *(unsigned __int8 *)(*(_DWORD *)v125 + 107));
        }
        goto LABEL_10;
      }
      goto LABEL_24;
    }
    if ( *(_DWORD *)off_123E20 << 28 )
    {
      sub_12F32C(dword_1244E8, dword_1244E4, 2493);
      if ( a1 > 0x3B )
      {
        if ( a1 == 143 )
          goto LABEL_16;
      }
      else if ( a1 > 5 )
      {
        v61 = a1 - 6;
        switch ( v61 )
        {
          case 0:
            *(_DWORD *)(a4 + 20) = &jpt_1241FE;
            *((_DWORD *)a2 + 21) = a2;
            *(_DWORD *)(a3 + 0x30) = 103;
            *((_DWORD *)a2 + 5) = 103;
            v100 = *((_DWORD *)a2 + 25);
            v101 = *(_DWORD *)(a3 + 0x44);
            v102 = *(_DWORD *)(a3 + 0x74);
            *(_BYTE *)(v101 + 17) = v61;
            *(_DWORD *)(v101 + 116) = v100;
            v103 = v61 - 1374;
            v104 = *(_DWORD *)(v100 + 4);
            *(_BYTE *)(v101 + 29) = v104;
            *(&loc_124340 + 3) = v103;
            *(_BYTE *)(v102 + 17) = v101;
            loc_12436A = v103;
            *(_DWORD *)(v101 + 20) = v104;
            v105 = *(_DWORD *)(v101 + 100);
            v106 = *(_DWORD *)(v102 + 68);
            *(_DWORD *)(v106 + 68) = v106;
            v107 = *(__int16 *)(2 * v106);
            *(_BYTE *)(v107 + 17) = *(_DWORD *)(v107 + 100);
            *(_DWORD *)(v102 + 84) = v103;
            v108 = *(__int16 *)(v105 + v107);
            *(_DWORD *)(v105 + 100) = v60;
            loc_1243AA = v103;
            v109 = *(__int16 *)(2 * v107);
            *(_DWORD *)(v107 + 68) = *(_DWORD *)(v108 + 20);
            v110 = *(_DWORD *)(v109 + 4);
            *(_DWORD *)(v108 + 84) = v103;
            v111 = *(unsigned __int8 *)(v109 + 1);
            *(_BYTE *)(v109 + 29) = v110;
            *(_DWORD *)(v107 + 84) = v111;
            *(_DWORD *)(v109 + 84) = v109;
            v112 = *(_DWORD *)(v109 + 4);
            *(_BYTE *)(v107 + 29) = v112;
            *(&loc_124340 + 3) = v103;
            *(_BYTE *)(2 * v107 + 0x11) = v107;
            loc_12436A = v103;
            *(_DWORD *)(v107 + 20) = v112;
            v113 = *(_DWORD *)(v107 + 100);
            v114 = *(_DWORD *)(2 * v107 + 0x44);
            *(_DWORD *)(v113 + 84) = &loc_124336;
            *(_DWORD *)(v114 + 84) = v113;
            *(_DWORD *)(2 * v114 + 0x54) = v103;
            v115 = *(_DWORD *)(*(__int16 *)(v113 + v114) + 4);
            *(_DWORD *)(v114 + 84) = v113;
            *(_BYTE *)(v113 + 17) = v115;
            *(_BYTE *)(v114 + 1) = v103;
            JUMPOUT(0x144230);
          default:
            break;
        }
      }
      if ( **v10 >= 0 )
      {
LABEL_24:
        v13 = off_123E24;
        v14 = 2;
        goto LABEL_10;
      }
    }
    else if ( a1 > 0x3B )
    {
      if ( a1 == 143 )
        goto LABEL_16;
    }
    else if ( a1 > 5 )
    {
      switch ( a1 )
      {
        case 6u:
LABEL_76:
          v59 = (_BYTE *)sub_12C7EC(7, a4, (__int16)a3, 2u);
          v13 = off_124194;
          *v59 = sub_11F680((int *)(a2 + 2), *a2, *(_DWORD *)(a2 + 0x20), v59 + 1);
          sub_12C84C((int)v59);
          v14 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v58 = *a2;
          if ( v58 <= 3 )
            sub_11FA78(v58);
          if ( !*((_DWORD *)off_1241D0 + 2) )
            sub_12BAEC();
          sub_12C8D0(9, a4, (__int16)a3);
          v13 = off_124194;
          v14 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v13 = off_124194;
          v57 = *(_DWORD *)a2;
          *(_DWORD *)off_124194 = *(_DWORD *)a2;
          if ( v11 < 0 && *(_DWORD *)off_1244F4 << 28 )
          {
            sub_12F35C(dword_1244E8, dword_1244F8, 472);
            v57 = *(_DWORD *)v13;
          }
          *(_DWORD *)off_1241CC = v57 | *((_DWORD *)v13 + 1);
          sub_12C8D0(15, a4, (__int16)a3);
          v14 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v55 = sub_12C7EC(17, a4, (__int16)a3, 2u);
          v13 = off_124194;
          v56 = v55;
          sub_102970((unsigned __int16 *)a2, *(_DWORD *)(a2 + 0x28));
          sub_12C84C(v56);
          v14 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v54 = off_1241C8;
          v13 = off_124194;
          *(_DWORD *)off_1241C8 = *(_DWORD *)off_1241C8 & 0xFFFFFF00 | *a2;
          *v54 |= 0x80000000;
          sub_12C8D0(19, a4, (__int16)a3);
          v14 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v52 = *(unsigned __int16 *)a2;
          v53 = dword_1241C4 + 1320 * *(_DWORD *)(a2 + 0x8);
          if ( *(_BYTE *)(v53 + 106) )
            sub_120130(v53, v52);
          else
            *(_DWORD *)(dword_124180 + 696 * *(unsigned __int8 *)(v53 + 116) + 8) = v52 << 10;
          sub_12C8D0(21, a4, (__int16)a3);
          v13 = off_124194;
          v14 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v46 = *(char **)a2;
          v47 = *(_DWORD *)(a2 + 0x14);
          v13 = off_124194;
          v48 = *((_DWORD *)off_1241BC + 10);
          v50 = (char *)(*(_DWORD *)a2 & 0xFFFFF1FF);
          v49 = v50 == nullptr;
          v51 = v47 + 4;
          if ( v50 )
            v46 = (char *)off_124194 + 4 * v51;
          else
            v50 = (char *)off_124194 + 4 * v51;
          if ( v49 )
            *((_DWORD *)v50 + 1) = v46;
          else
            *((_DWORD *)v46 + 1) = v50;
          if ( v48 && *(unsigned __int8 *)(v48 + 4) == v47 )
            *(_DWORD *)off_1241C0 = *(_DWORD *)&v13[4 * v51 + 4];
          sub_12C8D0(23, a4, (__int16)a3);
          v14 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v13 = off_124194;
          sub_143630((char *)(dword_1241B0 + 1320 * *(_DWORD *)(a2 + 0x18)), (char *)a2, 6u);
          v44 = off_1241B8;
          v45 = *((unsigned __int16 *)a2 + 2);
          *(_DWORD *)off_1241B4 = *(_DWORD *)a2;
          *v44 = v45;
          sub_12C8D0(25, a4, (__int16)a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v13 = off_124194;
          *(_DWORD *)off_1241D4 = (*a2 << 14) & 0x1C000 | *(_DWORD *)off_1241D4 & 0xFFFE3FFF;
          sub_12C8D0(29, a4, (__int16)a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v26 = *(_DWORD *)(a2 + 0xc);
          v27 = dword_1241C4;
          v28 = (unsigned __int8 *)(dword_1241C4 + 1320 * v26);
          *(_DWORD *)(v125 + 0x0) = 0;
          v121 = 1320 * v26;
          v29 = sub_1202F8(v125);
          v30 = *(_DWORD *)(v28 + 0x1a8);
          v31 = *(_DWORD *)(a2 + 0x8);
          *(_DWORD *)(v28 + 0x1b0) = v31;
          v116 = v29;
          if ( !v30 )
          {
            v123 = *(_DWORD *)(v28 + 0x1d0);
            if ( v31 )
            {
              v32 = dword_124180 + 696 * *(_DWORD *)(v28 + 0x1d0);
              v33 = v121 + 24 + v27;
              sub_124BFC(v33, *((_DWORD *)off_124184 + 4) + *(_DWORD *)(v32 + 8));
              *(_WORD *)(v32 + 32) = *(_WORD *)a2;
              sub_1202D8();
              sub_12EB90(
                256,
                dword_124188,
                *(unsigned __int8 *)(v32 + 35),
                *(unsigned __int16 *)(v32 + 32),
                *(_DWORD *)(v28 + 0x1320),
                v116);
              v34 = off_124190;
              *(_DWORD *)off_12418C = (unsigned __int16)*(_DWORD *)off_12418C | (*(unsigned __int16 *)a2 << 16);
              if ( (*v34 & 0x8000) != 0 && sub_101950() && (*(_DWORD *)(v32 + 4) & 0x20) != 0 )
              {
                sub_1019DC(*(_WORD *)a2);
                sub_11C1D0();
                sub_12EB90(256, dword_124828);
                sub_11C210();
              }
              v13 = off_124194;
              v124 = dword_124180 + 696 * v123;
              v35 = v27 + 1320 * v26;
              v36 = *(_DWORD *)(v35 + 4) | 1;
              *(_WORD *)(v124 + 30) = (unsigned int)(((unsigned int)dword_1241D8
                                                    * (unsigned __int64)(*(_DWORD *)(v124 + 8)
                                                                       * ((unsigned int)*((unsigned __int16 *)off_124194
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v37 = off_124184;
              *(_WORD *)(v35 + 112) = 0;
              *(_BYTE *)(v35 + 114) = 0;
              *(_BYTE *)(v35 + 148) = 0;
              *(_BYTE *)(v35 + 128) = 0;
              *(_DWORD *)(v35 + 124) = 0;
              *(_DWORD *)(v35 + 4) = v36;
              *(_DWORD *)(v35 + 120) = *(_DWORD *)(v37 + 0x10);
              v122 = v35;
              sub_128294((int)v28);
              v38 = *(unsigned __int8 *)(v122 + 1224);
              if ( *(_BYTE *)(v122 + 1224) )
              {
                if ( !v116 )
                  goto LABEL_39;
                v74 = off_1244EC;
                if ( !*((_DWORD *)off_1244EC + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_1244EC + 8) = 0;
                *(_DWORD *)(v74 + 0x90) = 0;
                sub_129388();
LABEL_119:
                v75 = **v10;
                *((_DWORD *)v13 + 1) |= 0x10u;
                if ( v75 < 0 && *(_DWORD *)off_124838 << 28 )
                  sub_12F35C(dword_124840, dword_12483C, 472);
                *(_DWORD *)off_124520 = *(_DWORD *)v13 | *((_DWORD *)v13 + 1);
                v31 = *(_DWORD *)(a2 + 0x8);
                goto LABEL_40;
              }
              if ( v116 )
              {
                if ( v116 != 1 )
                  goto LABEL_39;
                v86 = off_124814;
                if ( v28 == *((unsigned __int8 **)off_124814 + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_124814 + 8) = v38;
                v119 = v38;
                sub_124CF4(v33);
                *(_DWORD *)(v86 + 0x90) = v119;
                sub_129388();
                v31 = *(_DWORD *)(a2 + 0x8);
              }
              else
              {
                if ( *((_DWORD *)off_124198 + 8) )
                {
LABEL_39:
                  v31 = *(_DWORD *)(a2 + 0x8);
                  goto LABEL_40;
                }
                if ( *(_DWORD *)(v125 + 0x0) )
                {
                  if ( *(_DWORD *)(v125 + 0x0) != 1 )
                    goto LABEL_39;
                  goto LABEL_119;
                }
                v97 = (int *)off_124834;
                v98 = *(_DWORD *)(v124 + 8);
                v99 = *(_DWORD *)off_124834;
                *((_DWORD *)off_124198 + 8) = v28;
                *v97 = (unsigned __int16)(v98 >> 10) | (HIWORD(v99) << 16);
                sub_124CF4(v33);
                *((_BYTE *)off_124814 + 36) = 0;
                sub_129254();
                v31 = *(_DWORD *)(a2 + 0x8);
              }
            }
            else
            {
              sub_124CF4(v121 + 24 + v27);
              nullsub_8();
              sub_12EB90(256, dword_124510, *(_DWORD *)(v28 + 0x1320), v116);
              if ( (*(_DWORD *)off_124514 & 0x8000) != 0
                && sub_101950()
                && (*(_DWORD *)(dword_124818 + 696 * v123 + 4) & 0x20) != 0
                && *(_DWORD *)(v28 + 0x1a8) != 4 )
              {
                sub_12ACC4(*(_DWORD *)(v28 + 0x1ac));
              }
              v64 = v27 + 1320 * v26;
              v65 = *(unsigned __int8 *)(v64 + 1224);
              *(_BYTE *)(v64 + 1227) = 0;
              *(_DWORD *)(v64 + 1228) = 0;
              if ( v65 )
              {
                if ( v116 )
                {
                  v76 = *((unsigned __int8 **)off_124810 + 2);
                  if ( v76 )
                  {
                    while ( *(_DWORD *)(v76 + 0x1a8) || !*(_DWORD *)(v76 + 0x1b0) || v28 == v76 || *(_DWORD *)(v76 + 0x1320) )
                    {
                      v76 = *(unsigned __int8 **)v76;
                      if ( !v76 )
                        goto LABEL_101;
                    }
                    if ( !*((_DWORD *)off_124814 + 8) )
                    {
                      v77 = *(_DWORD *)(v76 + 0x1d0);
                      v78 = dword_124818;
                      v79 = (int *)off_124834;
                      *((_DWORD *)off_124814 + 8) = v76;
                      *v79 = (unsigned __int16)(*(_DWORD *)(v78 + 696 * v77 + 8) >> 10) | (HIWORD(*v79) << 16);
                      v118 = v76;
                      sub_124CF4((int)(v76 + 24));
                      *((_BYTE *)off_124814 + 36) = 0;
                      v13 = off_12481C;
                      sub_129254();
                      v80 = **v10;
                      v81 = v118;
                      *((_DWORD *)v13 + 1) &= ~0x10u;
                      if ( v80 < 0 && *(_DWORD *)off_124838 << 28 )
                      {
                        sub_12F35C(dword_124840, dword_12483C, 472);
                        v81 = v118;
                      }
                      v82 = off_124844;
                      *(_DWORD *)off_124820 = *(_DWORD *)v13 | *((_DWORD *)v13 + 1);
                      v83 = off_124824;
                      v84 = *((_DWORD *)v81 + 16);
                      v85 = *((unsigned __int16 *)v81 + 34);
                      *v82 = v84;
                      *v83 = v85;
                      v31 = *(_DWORD *)(a2 + 0x8);
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v116 == 2 )
              {
                v91 = off_124814;
                if ( !*((_DWORD *)off_124814 + 8) )
                {
                  v92 = *((unsigned __int8 **)off_124810 + 2);
                  if ( !v92 )
LABEL_169:
                    __und(0xFFu);
                  while ( *(_DWORD *)(v92 + 0x1a8) || !*(_DWORD *)(v92 + 0x1b0) || v28 == v92 || *(_DWORD *)(v92 + 0x1320) )
                  {
                    v92 = *(unsigned __int8 **)v92;
                    if ( !v92 )
                      goto LABEL_169;
                  }
                  v93 = (int *)off_124834;
                  v120 = *(_DWORD *)(v92 + 0x1320);
                  v94 = *(_DWORD *)off_124834;
                  v95 = *(_DWORD *)(dword_124818 + 696 * *(_DWORD *)(v92 + 0x1d0) + 8);
                  *((_DWORD *)off_124814 + 8) = v92;
                  *v93 = (unsigned __int16)(v95 >> 10) | (HIWORD(v94) << 16);
                  sub_124CF4((int)(v92 + 24));
                  *(_DWORD *)(v91 + 0x90) = v120;
                  v13 = off_12481C;
                  sub_129254();
                  v31 = *(_DWORD *)(a2 + 0x8);
                  goto LABEL_40;
                }
              }
              else if ( v116 == 1 )
              {
                v96 = off_124814;
                if ( v28 == *((unsigned __int8 **)off_124814 + 8) )
                {
                  *((_DWORD *)off_124814 + 8) = 0;
                  *(_DWORD *)(v96 + 0x90) = 0;
                  v13 = off_12481C;
                  sub_129388();
                  v31 = *(_DWORD *)(a2 + 0x8);
                  goto LABEL_40;
                }
              }
LABEL_101:
              v31 = *(_DWORD *)(a2 + 0x8);
              v13 = off_1244F0;
            }
LABEL_40:
            sub_129F50(v28, v31);
            if ( *(_DWORD *)(a2 + 0x8) )
            {
              v39 = *(_DWORD **)off_12419C;
              v40 = **(_DWORD **)off_12419C;
              if ( v40 )
                *(_DWORD *)off_1241A0 = v40;
              else
                *(_DWORD *)off_12450C = *(_DWORD *)(v27 + 1320 * v26 + 8);
              v41 = *(_DWORD *)(v39 + 0x4);
              if ( v41 )
              {
                if ( (v41 & 0xFFF) != 0 )
                  *(_DWORD *)off_124508 = v41;
                else
                  *(_DWORD *)off_1241A4 = v41 & 0xFFFFF000 | *(_DWORD *)(v27 + 1320 * v26 + 12) & 0xFFF;
              }
              else
              {
                *(_DWORD *)off_124508 = *(_DWORD *)(v27 + 1320 * v26 + 12);
              }
              v42 = *(_DWORD *)(v39 + 0x8);
              if ( v42 )
                *(_DWORD *)off_1241A8 = v42;
              else
                *(_DWORD *)off_124504 = *(_DWORD *)(v27 + 1320 * v26 + 16);
              v43 = *(_DWORD *)(v39 + 0xc);
              if ( v43 )
                *(_DWORD *)off_1241AC = v43;
              else
                *(_DWORD *)off_124518 = *(_DWORD *)(v27 + 1320 * v26 + 20);
              sub_120368();
            }
            sub_12C8D0(31, a4, (__int16)a3);
            v14 = 0;
            goto LABEL_10;
          }
          if ( !v29 )
          {
            if ( v31 )
            {
              v62 = nullptr;
              goto LABEL_84;
            }
LABEL_85:
            v13 = off_1244F0;
            goto LABEL_40;
          }
          v62 = *((unsigned __int8 **)off_12451C + 2);
          if ( v62 )
          {
            do
            {
              if ( !*(_DWORD *)(v62 + 0x1a8) && *(_DWORD *)(v62 + 0x1b0) && v28 != v62 && !*(_DWORD *)(v62 + 0x1320) )
                break;
              v62 = *(unsigned __int8 **)v62;
            }
            while ( v62 );
            if ( !v31 )
            {
              v66 = off_1244EC;
              if ( !*((_DWORD *)off_1244EC + 8) && v62 )
              {
                *((_DWORD *)off_1244EC + 8) = v62;
                *(_DWORD *)(v66 + 0x90) = 0;
                v117 = v62;
                v13 = off_1244F0;
                sub_124CF4((int)(v62 + 24));
                sub_129254();
                v67 = **v10;
                v68 = v117;
                *((_DWORD *)v13 + 1) &= ~0x10u;
                if ( v67 < 0 && *(_DWORD *)off_124838 << 28 )
                {
                  sub_12F35C(dword_124840, dword_12483C, 472);
                  v68 = v117;
                }
                v69 = off_124530;
                v70 = *((_DWORD *)v68 + 16);
                *(_DWORD *)off_124520 = *(_DWORD *)v13 | *((_DWORD *)v13 + 1);
                v71 = off_124524;
                v72 = *((unsigned __int16 *)v68 + 34);
                *v69 = v70;
                v73 = off_124528;
                *v71 = v72;
                *v73 = dword_12452C;
                *(_DWORD *)(v71 + 0x8050) &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_85;
            }
          }
          else if ( !v31 )
          {
            goto LABEL_85;
          }
LABEL_84:
          v63 = off_1244EC;
          if ( v62 == *((unsigned __int8 **)off_1244EC + 8) )
          {
            *((_DWORD *)off_1244EC + 8) = 0;
            *(_DWORD *)(v63 + 0x90) = 0;
            v13 = off_12481C;
            sub_129388();
            v87 = **v10;
            *((_DWORD *)v13 + 1) |= 0x10u;
            if ( v87 < 0 && *(_DWORD *)off_124838 << 28 )
              sub_12F35C(dword_124840, dword_12483C, 472);
            v88 = off_124820;
            v89 = off_12482C;
            *(_DWORD *)off_124820 = *(_DWORD *)v13 | *((_DWORD *)v13 + 1);
            v90 = dword_124830;
            *v89 = dword_124830;
            *(_DWORD *)(v88 + 0x8014) |= v90;
            v31 = *(_DWORD *)(a2 + 0x8);
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v13 = off_123E24;
          *(_DWORD *)off_123E48 = *a2 | (((unsigned __int8)*(_DWORD *)off_123E44 * *a2) << 8);
          sub_12C8D0(33, a4, (__int16)a3);
          v14 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v15 = *a2;
          if ( *a2 )
          {
            if ( sub_13A2B4(dword_1244FC + 696 * *(_DWORD *)(a2 + 0x4), *(_DWORD *)(a2 + 0x8), *((_WORD *)a2 + 3)) )
            {
              *(_DWORD *)off_124500 |= 0x80u;
              v15 = 0;
            }
            else
            {
              v15 = 4;
            }
          }
          else
          {
            v16 = *((unsigned __int16 *)a2 + 2);
            v17 = *(_DWORD *)(dword_123E38 + 4 * *(unsigned __int8 *)(dword_123E34 + *(_DWORD *)(a2 + 0x8)));
            if ( (int)v16 >= v17 )
            {
              if ( v16 > 0x40 )
                LOWORD(v18) = *(_DWORD *)(dword_123E38 + 4 * *(unsigned __int8 *)(dword_123E34 + *(_DWORD *)(a2 + 0x8)));
              else
                LOWORD(v18) = v17 / 2;
            }
            else
            {
              v18 = v16 >> 1;
            }
            sub_12E948(dword_123E3C);
            v19 = *((_WORD *)a2 + 2);
            v20 = 696 * *(_DWORD *)(a2 + 0x4);
            v21 = *(unsigned __int8 *)(v20 + 12 * *(_DWORD *)(a2 + 0x8) + dword_123E4C + 453);
            v22 = *((_WORD *)a2 + 3);
            v23 = v20 + 6 * *(_DWORD *)(a2 + 0x8) + dword_123E4C;
            v24 = dword_123E40 + 32 * v21;
            *(_WORD *)(v23 + 354) = v18;
            *(_WORD *)(v23 + 356) = v19;
            *(_WORD *)(v24 + 12) = v22;
          }
          v25 = (_BYTE *)sub_12C7EC(41, a4, (__int16)a3, 3u);
          *v25 = *(_DWORD *)(a2 + 0x4);
          *(_DWORD *)(v25 + 0x4) = *(_DWORD *)(a2 + 0x8);
          *(_DWORD *)(v25 + 0x8) = v15;
          sub_12C84C((int)v25);
          v13 = off_123E24;
          v14 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          sub_12F378();
          v13 = off_123E24;
          v14 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          sub_127D64(a2);
          sub_12C8D0(60, a4, (__int16)a3);
          v13 = off_123E24;
          v14 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    v13 = off_123E24;
    sub_12F32C(dword_123E30, dword_123E2C, 2552);
    v14 = 2;
LABEL_10:
    *(_DWORD *)off_123E20 = (unsigned __int8)(16 * *(_DWORD *)(v13 + 0x4c));
    sub_12CBF4((unsigned int)a3, (unsigned __int8)*(_DWORD *)(v13 + 0x48));
    return v14;
  }
  if ( (unsigned __int16)(v8 - 2) > 2u )
  {
    v12 = off_123E24;
    *((_BYTE *)off_123E24 + 19) = *(_BYTE *)off_123E20 & 0xF;
    *(_DWORD *)(v12 + 0x48) = sub_12CD48((unsigned int)a3);
    sub_12B6C4();
    sub_12CBF4((unsigned int)a3, 2);
  }
  return 2;
}
