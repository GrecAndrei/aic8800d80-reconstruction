// v23 annotated: sub_123B4C @ 0x123b4c
// Original: 123b4c_sub_123B4C.c
// Primary struct: <unclustered>
//
// sub_123B4C @ 0x123b4c, size 3268 bytes
// write access to const memory has been detected, the output may be wrong!
int __fastcall sub_123B4C(unsigned int a1, unsigned __int8 *a2, _DWORD *a3, int a4)
{
  int v8; // r0
  int v9; // r1
  __int16 **v11; // r8
  int v12; // r3
  _BYTE *v13; // r5
  int v14; // r0
  _BYTE *v15; // r7
  int v16; // r6
  char v17; // r7
  int v18; // r1
  unsigned int v19; // r2
  signed int v20; // r3
  unsigned int v21; // r8
  __int16 v22; // lr
  int v23; // r2
  int v24; // r3
  __int16 v25; // r1
  int v26; // r2
  int v27; // r3
  _BYTE *v28; // r0
  int v29; // r11
  int v30; // r10
  unsigned __int8 *v31; // r9
  int v32; // r0
  int v33; // r2
  int v34; // r1
  int v35; // r7
  int v36; // s16
  _DWORD *v37; // r1
  int v38; // r3
  int v39; // r12
  _DWORD *v40; // r0
  int v41; // r0
  int v42; // r3
  _DWORD *v43; // r3
  int v44; // r2
  int v45; // r2
  int v46; // r2
  int v47; // r3
  _DWORD *v48; // r3
  int v49; // r2
  char *v50; // r3
  int v51; // r1
  int v52; // r0
  bool v53; // zf
  char *v54; // r5
  int v55; // r2
  unsigned int v56; // r1
  int v57; // r0
  _DWORD *v58; // r2
  int v59; // r0
  int v60; // r6
  int v61; // r2
  unsigned int v62; // r0
  _BYTE *v63; // r6
  int v64; // r1
  unsigned int v65; // r7
  unsigned __int8 *v66; // r3
  _BYTE *v67; // r2
  int v68; // r0
  int v69; // r0
  int v70; // r3
  int v71; // r1
  _BYTE *v72; // r2
  int v73; // r0
  int v74; // r1
  unsigned __int8 *v75; // r3
  _DWORD *v76; // lr
  int v77; // r12
  _DWORD *v78; // r2
  int v79; // r0
  _DWORD *v80; // r3
  _BYTE *v81; // r3
  int v82; // r2
  unsigned __int8 *v83; // r3
  int v84; // r0
  int v85; // r7
  int *v86; // r12
  int v87; // r0
  int v88; // r1
  unsigned __int8 *v89; // r3
  _DWORD *v90; // r12
  _DWORD *v91; // r2
  int v92; // r0
  int v93; // r3
  _BYTE *v94; // r8
  int v95; // r0
  int v96; // r2
  _DWORD *v97; // r2
  _DWORD *v98; // r0
  int v99; // r1
  _BYTE *v100; // r8
  unsigned __int8 *v101; // r0
  int *v102; // r1
  unsigned int v103; // r12
  unsigned int v104; // r3
  int v105; // r0
  _BYTE *v106; // r3
  int *v107; // r12
  unsigned int v108; // r3
  unsigned int v109; // r1
  int v110; // r0
  int v111; // r6
  int v112; // r5
  int v113; // r4
  unsigned int v114; // r7
  int v115; // r0
  int v116; // r6
  int v117; // r5
  int v118; // r5
  int v119; // r4
  int v120; // r6
  int v121; // r0
  int v122; // r4
  int v123; // r0
  int v124; // r6
  int v125; // r5
  int v126; // r3
  int v127; // [sp+Ch] [bp-18h]
  unsigned __int8 *v128; // [sp+Ch] [bp-18h]
  unsigned __int8 *v129; // [sp+Ch] [bp-18h]
  char v130; // [sp+Ch] [bp-18h]
  unsigned __int8 v131; // [sp+Ch] [bp-18h]
  int v132; // [sp+10h] [bp-14h]
  int v133; // [sp+10h] [bp-14h]
  int v134; // [sp+14h] [bp-10h]
  int v135; // [sp+14h] [bp-10h]
  unsigned __int8 v136[8]; // [sp+1Ch] [bp-8h] BYREF

  v8 = sub_12CD48(a3);
  if ( !v8 )
  {
    v11 = (__int16 **)off_123E50;
    v12 = **(__int16 **)off_123E50;
    if ( v12 >= 0 )
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
              v15 = off_123E24;
              v16 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v15 = off_123E24;
        *((_BYTE *)off_123E24 + 48) = 0;
        v16 = sub_12BB80(*(_DWORD *)a2);
        if ( v16 )
        {
          sub_121844(*(_DWORD *)a2);
          v16 = 0;
        }
        else if ( v15[49] )
        {
          v15[49] = 0;
          if ( sub_126300(v136) )
            sub_12AA90(
              *(unsigned __int8 *)(*(_DWORD *)v136 + 1225),
              dword_123E28 + 38 * *(unsigned __int8 *)(*(_DWORD *)v136 + 107));
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
        v65 = a1 - 6;
        switch ( v65 )
        {
          case 0u:
            *(_DWORD *)(a4 + 20) = &jpt_1241FE;
            *((_DWORD *)a2 + 21) = a2;
            a3[12] = 103;
            *((_DWORD *)a2 + 5) = 103;
            v111 = *((_DWORD *)a2 + 25);
            v112 = a3[17];
            v113 = a3[29];
            *(_BYTE *)(v112 + 17) = v65;
            *(_DWORD *)(v112 + 116) = v111;
            v114 = v65 - 1374;
            v115 = *(_DWORD *)(v111 + 4);
            *(_BYTE *)(v112 + 29) = v115;
            *(&loc_124340 + 3) = v114;
            *(_BYTE *)(v113 + 17) = v112;
            loc_12436A = v114;
            *(_DWORD *)(v112 + 20) = v115;
            v116 = *(_DWORD *)(v112 + 100);
            v117 = *(_DWORD *)(v113 + 68);
            *(_DWORD *)(v117 + 68) = v117;
            v118 = *(__int16 *)(2 * v117);
            *(_BYTE *)(v118 + 17) = *(_DWORD *)(v118 + 100);
            *(_DWORD *)(v113 + 84) = v114;
            v119 = *(__int16 *)(v116 + v118);
            *(_DWORD *)(v116 + 100) = v64;
            loc_1243AA = v114;
            v120 = *(__int16 *)(2 * v118);
            *(_DWORD *)(v118 + 68) = *(_DWORD *)(v119 + 20);
            v121 = *(_DWORD *)(v120 + 4);
            *(_DWORD *)(v119 + 84) = v114;
            v122 = *(unsigned __int8 *)(v120 + 1);
            *(_BYTE *)(v120 + 29) = v121;
            *(_DWORD *)(v118 + 84) = v122;
            *(_DWORD *)(v120 + 84) = v120;
            v123 = *(_DWORD *)(v120 + 4);
            *(_BYTE *)(v118 + 29) = v123;
            *(&loc_124340 + 3) = v114;
            *(_BYTE *)(2 * v118 + 0x11) = v118;
            loc_12436A = v114;
            *(_DWORD *)(v118 + 20) = v123;
            v124 = *(_DWORD *)(v118 + 100);
            v125 = *(_DWORD *)(2 * v118 + 0x44);
            *(_DWORD *)(v124 + 84) = &loc_124336;
            *(_DWORD *)(v125 + 84) = v124;
            *(_DWORD *)(2 * v125 + 0x54) = v114;
            v126 = *(_DWORD *)(*(__int16 *)(v124 + v125) + 4);
            *(_DWORD *)(v125 + 84) = v124;
            *(_BYTE *)(v124 + 17) = v126;
            *(_BYTE *)(v125 + 1) = v114;
            JUMPOUT(0x144230);
          default:
            break;
        }
      }
      if ( **v11 >= 0 )
      {
LABEL_24:
        v15 = off_123E24;
        v16 = 2;
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
          v63 = (_BYTE *)sub_12C7EC(7, a4, a3, 2);
          v15 = off_124194;
          *v63 = sub_11F680((int *)(a2 + 2), *a2, a2[8], v63 + 1);
          sub_12C84C(v63);
          v16 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v62 = *a2;
          if ( v62 <= 3 )
            v62 = sub_11FA78(v62);
          if ( !*((_DWORD *)off_1241D0 + 2) )
            sub_12BAEC(v62, v9);
          sub_12C8D0(9, a4, a3);
          v15 = off_124194;
          v16 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v15 = off_124194;
          v61 = *(_DWORD *)a2;
          *(_DWORD *)off_124194 = *(_DWORD *)a2;
          if ( v12 < 0 && *(_DWORD *)off_1244F4 << 28 )
          {
            sub_12F35C(dword_1244E8, dword_1244F8, 472);
            v61 = *(_DWORD *)v15;
          }
          *(_DWORD *)off_1241CC = v61 | *((_DWORD *)v15 + 1);
          sub_12C8D0(15, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v59 = sub_12C7EC(17, a4, a3, 2);
          v15 = off_124194;
          v60 = v59;
          sub_102970((unsigned __int16 *)a2, a2[10]);
          sub_12C84C(v60);
          v16 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v58 = off_1241C8;
          v15 = off_124194;
          *(_DWORD *)off_1241C8 = *(_DWORD *)off_1241C8 & 0xFFFFFF00 | *a2;
          *v58 |= 0x80000000;
          sub_12C8D0(19, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v56 = *(unsigned __int16 *)a2;
          v57 = dword_1241C4 + 1320 * a2[2];
          if ( *(_BYTE *)(v57 + 106) )
            sub_120130(v57, v56);
          else
            *(_DWORD *)(dword_124180 + 696 * *(unsigned __int8 *)(v57 + 116) + 8) = v56 << 10;
          sub_12C8D0(21, a4, a3);
          v15 = off_124194;
          v16 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v50 = *(char **)a2;
          v51 = a2[5];
          v15 = off_124194;
          v52 = *((_DWORD *)off_1241BC + 10);
          v54 = (char *)(*(_DWORD *)a2 & 0xFFFFF1FF);
          v53 = v54 == nullptr;
          v55 = v51 + 4;
          if ( v54 )
            v50 = (char *)off_124194 + 4 * v55;
          else
            v54 = (char *)off_124194 + 4 * v55;
          if ( v53 )
            *((_DWORD *)v54 + 1) = v50;
          else
            *((_DWORD *)v50 + 1) = v54;
          if ( v52 && *(unsigned __int8 *)(v52 + 4) == v51 )
            *(_DWORD *)off_1241C0 = *(_DWORD *)&v15[4 * v55 + 4];
          sub_12C8D0(23, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v15 = off_124194;
          sub_143630(dword_1241B0 + 1320 * a2[6], a2, 6);
          v48 = off_1241B8;
          v49 = *((unsigned __int16 *)a2 + 2);
          *(_DWORD *)off_1241B4 = *(_DWORD *)a2;
          *v48 = v49;
          sub_12C8D0(25, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v15 = off_124194;
          *(_DWORD *)off_1241D4 = (*a2 << 14) & 0x1C000 | *(_DWORD *)off_1241D4 & 0xFFFE3FFF;
          sub_12C8D0(29, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v29 = a2[3];
          v30 = dword_1241C4;
          v31 = (unsigned __int8 *)(dword_1241C4 + 1320 * v29);
          v136[0] = 0;
          v132 = 1320 * v29;
          v32 = sub_1202F8(v136);
          v33 = v31[106];
          v34 = a2[2];
          v31[108] = v34;
          v127 = v32;
          if ( !v33 )
          {
            v134 = v31[116];
            if ( v34 )
            {
              v35 = dword_124180 + 696 * v31[116];
              v36 = v132 + 24 + v30;
              sub_124BFC(v36, *((_DWORD *)off_124184 + 4) + *(_DWORD *)(v35 + 8));
              *(_WORD *)(v35 + 32) = *(_WORD *)a2;
              sub_1202D8();
              sub_12EB90(256, dword_124188);
              v37 = off_124190;
              *(_DWORD *)off_12418C = (unsigned __int16)*(_DWORD *)off_12418C | (*(unsigned __int16 *)a2 << 16);
              if ( (*v37 & 0x8000) != 0 && sub_101950() && (*(_DWORD *)(v35 + 4) & 0x20) != 0 )
              {
                sub_1019DC(*(_WORD *)a2);
                sub_11C1D0();
                sub_12EB90(256, dword_124828);
                sub_11C210();
              }
              v15 = off_124194;
              v135 = dword_124180 + 696 * v134;
              v38 = v30 + 1320 * v29;
              v39 = *(_DWORD *)(v38 + 4) | 1;
              *(_WORD *)(v135 + 30) = (unsigned int)(((unsigned int)dword_1241D8
                                                    * (unsigned __int64)(*(_DWORD *)(v135 + 8)
                                                                       * ((unsigned int)*((unsigned __int16 *)off_124194
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v40 = off_124184;
              *(_WORD *)(v38 + 112) = 0;
              *(_BYTE *)(v38 + 114) = 0;
              *(_BYTE *)(v38 + 148) = 0;
              *(_BYTE *)(v38 + 128) = 0;
              *(_DWORD *)(v38 + 124) = 0;
              *(_DWORD *)(v38 + 4) = v39;
              *(_DWORD *)(v38 + 120) = v40[4];
              v133 = v38;
              v41 = sub_128294(v31);
              v42 = *(unsigned __int8 *)(v133 + 1224);
              if ( *(_BYTE *)(v133 + 1224) )
              {
                if ( !v127 )
                  goto LABEL_39;
                v81 = off_1244EC;
                if ( !*((_DWORD *)off_1244EC + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_1244EC + 8) = 0;
                v81[36] = 0;
                sub_129388(v41);
LABEL_119:
                v82 = **v11;
                *((_DWORD *)v15 + 1) |= 0x10u;
                if ( v82 < 0 && *(_DWORD *)off_124838 << 28 )
                  sub_12F35C(dword_124840, dword_12483C, 472);
                *(_DWORD *)off_124520 = *(_DWORD *)v15 | *((_DWORD *)v15 + 1);
                v34 = a2[2];
                goto LABEL_40;
              }
              if ( v127 )
              {
                if ( v127 != 1 )
                  goto LABEL_39;
                v94 = off_124814;
                if ( v31 == *((unsigned __int8 **)off_124814 + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_124814 + 8) = v42;
                v130 = v42;
                v95 = sub_124CF4(v36);
                v94[36] = v130;
                sub_129388(v95);
                v34 = a2[2];
              }
              else
              {
                if ( *((_DWORD *)off_124198 + 8) )
                {
LABEL_39:
                  v34 = a2[2];
                  goto LABEL_40;
                }
                if ( v136[0] )
                {
                  if ( v136[0] != 1 )
                    goto LABEL_39;
                  goto LABEL_119;
                }
                v107 = (int *)off_124834;
                v108 = *(_DWORD *)(v135 + 8);
                v109 = *(_DWORD *)off_124834;
                *((_DWORD *)off_124198 + 8) = v31;
                *v107 = (unsigned __int16)(v108 >> 10) | (HIWORD(v109) << 16);
                v110 = sub_124CF4(v36);
                *((_BYTE *)off_124814 + 36) = 0;
                sub_129254(v110);
                v34 = a2[2];
              }
            }
            else
            {
              v68 = sub_124CF4(v132 + 24 + v30);
              nullsub_8(v68);
              v69 = sub_12EB90(256, dword_124510);
              if ( (*(_DWORD *)off_124514 & 0x8000) != 0 )
              {
                v69 = sub_101950();
                if ( v69 )
                {
                  if ( (*(_DWORD *)(dword_124818 + 696 * v134 + 4) & 0x20) != 0 && v31[106] != 4 )
                    v69 = sub_12ACC4(v31[107]);
                }
              }
              v70 = v30 + 1320 * v29;
              v71 = *(unsigned __int8 *)(v70 + 1224);
              *(_BYTE *)(v70 + 1227) = 0;
              *(_DWORD *)(v70 + 1228) = 0;
              if ( v71 )
              {
                if ( v127 )
                {
                  v83 = *((unsigned __int8 **)off_124810 + 2);
                  if ( v83 )
                  {
                    while ( v83[106] || !v83[108] || v31 == v83 || v83[1224] )
                    {
                      v83 = *(unsigned __int8 **)v83;
                      if ( !v83 )
                        goto LABEL_101;
                    }
                    if ( !*((_DWORD *)off_124814 + 8) )
                    {
                      v84 = v83[116];
                      v85 = dword_124818;
                      v86 = (int *)off_124834;
                      *((_DWORD *)off_124814 + 8) = v83;
                      *v86 = (unsigned __int16)(*(_DWORD *)(v85 + 696 * v84 + 8) >> 10) | (HIWORD(*v86) << 16);
                      v129 = v83;
                      v87 = sub_124CF4(v83 + 24);
                      *((_BYTE *)off_124814 + 36) = 0;
                      v15 = off_12481C;
                      sub_129254(v87);
                      v88 = **v11;
                      v89 = v129;
                      *((_DWORD *)v15 + 1) &= ~0x10u;
                      if ( v88 < 0 && *(_DWORD *)off_124838 << 28 )
                      {
                        sub_12F35C(dword_124840, dword_12483C, 472);
                        v89 = v129;
                      }
                      v90 = off_124844;
                      *(_DWORD *)off_124820 = *(_DWORD *)v15 | *((_DWORD *)v15 + 1);
                      v91 = off_124824;
                      v92 = *((_DWORD *)v89 + 16);
                      v93 = *((unsigned __int16 *)v89 + 34);
                      *v90 = v92;
                      *v91 = v93;
                      v34 = a2[2];
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v127 == 2 )
              {
                v100 = off_124814;
                if ( !*((_DWORD *)off_124814 + 8) )
                {
                  v101 = *((unsigned __int8 **)off_124810 + 2);
                  if ( !v101 )
LABEL_169:
                    __und(0xFFu);
                  while ( v101[106] || !v101[108] || v31 == v101 || v101[1224] )
                  {
                    v101 = *(unsigned __int8 **)v101;
                    if ( !v101 )
                      goto LABEL_169;
                  }
                  v102 = (int *)off_124834;
                  v131 = v101[1224];
                  v103 = *(_DWORD *)off_124834;
                  v104 = *(_DWORD *)(dword_124818 + 696 * v101[116] + 8);
                  *((_DWORD *)off_124814 + 8) = v101;
                  *v102 = (unsigned __int16)(v104 >> 10) | (HIWORD(v103) << 16);
                  v105 = sub_124CF4(v101 + 24);
                  v100[36] = v131;
                  v15 = off_12481C;
                  sub_129254(v105);
                  v34 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( v127 == 1 )
              {
                v106 = off_124814;
                if ( v31 == *((unsigned __int8 **)off_124814 + 8) )
                {
                  *((_DWORD *)off_124814 + 8) = 0;
                  v106[36] = 0;
                  v15 = off_12481C;
                  sub_129388(v69);
                  v34 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_101:
              v34 = a2[2];
              v15 = off_1244F0;
            }
LABEL_40:
            sub_129F50(v31, v34);
            if ( a2[2] )
            {
              v43 = *(_DWORD **)off_12419C;
              v44 = **(_DWORD **)off_12419C;
              if ( v44 )
                *(_DWORD *)off_1241A0 = v44;
              else
                *(_DWORD *)off_12450C = *(_DWORD *)(v30 + 1320 * v29 + 8);
              v45 = v43[1];
              if ( v45 )
              {
                if ( (v45 & 0xFFF) != 0 )
                  *(_DWORD *)off_124508 = v45;
                else
                  *(_DWORD *)off_1241A4 = v45 & 0xFFFFF000 | *(_DWORD *)(v30 + 1320 * v29 + 12) & 0xFFF;
              }
              else
              {
                *(_DWORD *)off_124508 = *(_DWORD *)(v30 + 1320 * v29 + 12);
              }
              v46 = v43[2];
              if ( v46 )
                *(_DWORD *)off_1241A8 = v46;
              else
                *(_DWORD *)off_124504 = *(_DWORD *)(v30 + 1320 * v29 + 16);
              v47 = v43[3];
              if ( v47 )
                *(_DWORD *)off_1241AC = v47;
              else
                *(_DWORD *)off_124518 = *(_DWORD *)(v30 + 1320 * v29 + 20);
              sub_120368();
            }
            sub_12C8D0(31, a4, a3);
            v16 = 0;
            goto LABEL_10;
          }
          if ( !v32 )
          {
            if ( v34 )
            {
              v66 = nullptr;
              goto LABEL_84;
            }
LABEL_85:
            v15 = off_1244F0;
            goto LABEL_40;
          }
          v66 = *((unsigned __int8 **)off_12451C + 2);
          if ( v66 )
          {
            do
            {
              if ( !v66[106] && v66[108] && v31 != v66 && !v66[1224] )
                break;
              v66 = *(unsigned __int8 **)v66;
            }
            while ( v66 );
            if ( !v34 )
            {
              v72 = off_1244EC;
              if ( !*((_DWORD *)off_1244EC + 8) && v66 )
              {
                *((_DWORD *)off_1244EC + 8) = v66;
                v72[36] = 0;
                v128 = v66;
                v15 = off_1244F0;
                v73 = sub_124CF4(v66 + 24);
                sub_129254(v73);
                v74 = **v11;
                v75 = v128;
                *((_DWORD *)v15 + 1) &= ~0x10u;
                if ( v74 < 0 && *(_DWORD *)off_124838 << 28 )
                {
                  sub_12F35C(dword_124840, dword_12483C, 472);
                  v75 = v128;
                }
                v76 = off_124530;
                v77 = *((_DWORD *)v75 + 16);
                *(_DWORD *)off_124520 = *(_DWORD *)v15 | *((_DWORD *)v15 + 1);
                v78 = off_124524;
                v79 = *((unsigned __int16 *)v75 + 34);
                *v76 = v77;
                v80 = off_124528;
                *v78 = v79;
                *v80 = dword_12452C;
                v78[8212] &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_85;
            }
          }
          else if ( !v34 )
          {
            goto LABEL_85;
          }
LABEL_84:
          v67 = off_1244EC;
          if ( v66 == *((unsigned __int8 **)off_1244EC + 8) )
          {
            *((_DWORD *)off_1244EC + 8) = 0;
            v67[36] = 0;
            v15 = off_12481C;
            ((void (*)(void))sub_129388)();
            v96 = **v11;
            *((_DWORD *)v15 + 1) |= 0x10u;
            if ( v96 < 0 && *(_DWORD *)off_124838 << 28 )
              sub_12F35C(dword_124840, dword_12483C, 472);
            v97 = off_124820;
            v98 = off_12482C;
            *(_DWORD *)off_124820 = *(_DWORD *)v15 | *((_DWORD *)v15 + 1);
            v99 = dword_124830;
            *v98 = dword_124830;
            v97[8197] |= v99;
            v34 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v15 = off_123E24;
          *(_DWORD *)off_123E48 = *a2 | (((unsigned __int8)*(_DWORD *)off_123E44 * *a2) << 8);
          sub_12C8D0(33, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v17 = *a2;
          if ( *a2 )
          {
            if ( sub_13A2B4(dword_1244FC + 696 * a2[1], a2[2], *((unsigned __int16 *)a2 + 3)) )
            {
              *(_DWORD *)off_124500 |= 0x80u;
              v17 = 0;
            }
            else
            {
              v17 = 4;
            }
          }
          else
          {
            v18 = a2[2];
            v19 = *((unsigned __int16 *)a2 + 2);
            v20 = *(_DWORD *)(dword_123E38 + 4 * *(unsigned __int8 *)(dword_123E34 + v18));
            if ( (int)v19 >= v20 )
            {
              if ( v19 > 0x40 )
                LOWORD(v21) = *(_DWORD *)(dword_123E38 + 4 * *(unsigned __int8 *)(dword_123E34 + v18));
              else
                LOWORD(v21) = v20 / 2;
            }
            else
            {
              v21 = v19 >> 1;
            }
            sub_12E948(dword_123E3C, v18, v19);
            v22 = *((_WORD *)a2 + 2);
            v23 = 696 * a2[1];
            v24 = *(unsigned __int8 *)(v23 + 12 * a2[2] + dword_123E4C + 453);
            v25 = *((_WORD *)a2 + 3);
            v26 = v23 + 6 * a2[2] + dword_123E4C;
            v27 = dword_123E40 + 32 * v24;
            *(_WORD *)(v26 + 354) = v21;
            *(_WORD *)(v26 + 356) = v22;
            *(_WORD *)(v27 + 12) = v25;
          }
          v28 = (_BYTE *)sub_12C7EC(41, a4, a3, 3);
          *v28 = a2[1];
          v28[1] = a2[2];
          v28[2] = v17;
          sub_12C84C(v28);
          v15 = off_123E24;
          v16 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          sub_12F378(a2);
          v15 = off_123E24;
          v16 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          sub_127D64(a2);
          sub_12C8D0(60, a4, a3);
          v15 = off_123E24;
          v16 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    v15 = off_123E24;
    sub_12F32C(dword_123E30, dword_123E2C, 2552);
    v16 = 2;
LABEL_10:
    *(_DWORD *)off_123E20 = (unsigned __int8)(16 * v15[19]);
    sub_12CBF4(a3);
    return v16;
  }
  if ( (unsigned __int16)(v8 - 2) > 2u )
  {
    v13 = off_123E24;
    *((_BYTE *)off_123E24 + 19) = *(_BYTE *)off_123E20 & 0xF;
    v14 = sub_12CD48(a3);
    v13[18] = v14;
    sub_12B6C4(v14);
    sub_12CBF4(a3);
  }
  return 2;
}

