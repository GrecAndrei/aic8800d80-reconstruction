// sub_13F6F4 @ 0x13f6f4, size 2470 bytes
int __fastcall sub_13F6F4(int a1)
{
  __int16 **v1; // r11
  unsigned int v2; // r7
  int *v3; // r8
  int v5; // r6
  __int16 v6; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r5
  __int16 v10; // r0
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r0
  __int16 *v15; // r3
  __int16 v16; // r3
  __int16 v17; // r0
  unsigned int v18; // r0
  __int16 *v19; // r3
  int v20; // r0
  unsigned int v21; // r0
  __int16 *v22; // r2
  unsigned int v23; // r0
  __int16 *v24; // r2
  int v25; // r3
  int v26; // r3
  int v27; // r0
  unsigned int v28; // r0
  __int16 *v29; // r2
  unsigned int v30; // r0
  __int16 *v31; // r2
  unsigned int v32; // r3
  int v33; // r1
  unsigned int v34; // r0
  int v35; // r7
  __int16 *v36; // r5
  int *v37; // r2
  __int16 v38; // t1
  int v39; // r2
  int v40; // r3
  int result; // r0
  int v42; // r3
  unsigned int v43; // r0
  int v44; // r3
  __int16 *v45; // r1
  unsigned int v46; // r3
  __int16 v47; // r0
  int v48; // r0
  unsigned int v49; // r0
  __int16 *v50; // r2
  unsigned int v51; // r0
  __int16 *v52; // r2
  __int16 v53; // r3
  __int16 v54; // r2
  unsigned int v55; // r3
  int v56; // r1
  int v57; // r0
  unsigned int v58; // r0
  __int16 *v59; // r3
  __int16 v60; // r3
  __int16 v61; // r0
  unsigned int v62; // r0
  __int16 *v63; // r3
  int v64; // r0
  unsigned int v65; // r0
  __int16 *v66; // r2
  unsigned int v67; // r0
  __int16 *v68; // r2
  int v69; // r3
  int v70; // r3
  int v71; // r2
  int v72; // r3
  int v73; // r0
  int v74; // r1
  unsigned int v75; // r1
  unsigned int v76; // r3
  unsigned int v77; // r2
  char v78; // r0
  int v79; // r2
  unsigned int v80; // r3
  unsigned int v81; // r1
  unsigned int v82; // r3
  unsigned int v83; // r2
  __int16 v84; // r2
  int v85; // [sp+10h] [bp-1Ch]
  int v86; // [sp+14h] [bp-18h]
  unsigned int v87; // [sp+18h] [bp-14h]
  unsigned int v88; // [sp+18h] [bp-14h]
  unsigned int v89; // [sp+18h] [bp-14h]
  unsigned int v90; // [sp+18h] [bp-14h]
  unsigned int v91; // [sp+18h] [bp-14h]
  unsigned int v92; // [sp+18h] [bp-14h]
  __int16 *v93; // [sp+18h] [bp-14h]
  unsigned int v94; // [sp+18h] [bp-14h]
  unsigned int v95; // [sp+18h] [bp-14h]
  _WORD *v96; // [sp+1Ch] [bp-10h]
  int v97; // [sp+1Ch] [bp-10h]
  unsigned int v98; // [sp+20h] [bp-Ch]
  unsigned int v99; // [sp+20h] [bp-Ch]
  unsigned int v100; // [sp+20h] [bp-Ch]
  unsigned int v101; // [sp+20h] [bp-Ch]

  v1 = (__int16 **)off_13FAA4;
  v2 = *(unsigned __int8 *)(a1 + 35);
  v3 = *(int **)(a1 + 336);
  v86 = (unsigned __int8)(v2 + 16);
  if ( **(__int16 **)off_13FAA4 < 0 && v2 > 0x1F )
  {
    sub_12F32C(dword_13FA9C, dword_13FA94, 2825);
    v2 = *(unsigned __int8 *)(a1 + 35);
  }
  v5 = dword_13FA74;
  if ( (*(_DWORD *)(a1 + 4) & 0x40) != 0 )
    v6 = 0;
  else
    v6 = 1024;
  v7 = dword_13FA74 + 200 * v2;
  *(_WORD *)(a1 + 348) = v6;
  *(_DWORD *)(a1 + 340) = v7;
  v85 = sub_101A2C() << 14;
  v8 = sub_102AB0();
  sub_100200((int *)(v5 + 200 * v2), 0, 0xC8u);
  v9 = 200 * v2;
  if ( (*(_DWORD *)(a1 + 4) & 2) != 0 )
  {
    v10 = sub_132654((unsigned __int8 *)(a1 + 192), 0);
    v11 = *(_DWORD *)(a1 + 4);
    v12 = v5 + 200 * v2;
    *(_WORD *)(v12 + 174) = v10;
    if ( (v11 & 0x20) == 0 )
    {
      if ( (v11 & 4) != 0 )
      {
        v96 = off_13FA78;
        v13 = *(unsigned __int16 *)(a1 + 244);
        *(_BYTE *)(v12 + 169) = 4;
        v87 = sub_13248C(v13);
        v14 = sub_13248C((unsigned __int16)v96[28]);
        if ( v14 >= v87 )
          v14 = v87;
        v15 = *v1;
        *(_BYTE *)(v5 + 200 * v2 + 180) = v14;
        if ( *v15 < 0 && v14 > 7 )
          sub_12F32C(dword_1400BC, dword_14009C, 2992);
        v16 = sub_1326E0(*(unsigned __int16 *)(a1 + 244), (unsigned __int16)v96[28]);
        v17 = *(_WORD *)(a1 + 244);
        *(_WORD *)(v5 + 200 * v2 + 170) = v16;
        v88 = sub_13245C(v17);
        v18 = sub_13245C(v96[28]);
        if ( v18 >= v88 )
          v18 = v88;
        v19 = *v1;
        *(_BYTE *)(v5 + 200 * v2 + 176) = v18;
        if ( *v19 < 0 && v18 > 9 )
          sub_12F32C(dword_1400B8, dword_14009C, 2998);
        v89 = v5 + 200 * v2;
        v20 = *(_WORD *)(v89 + 174) & 0xF00F;
        *(_WORD *)(v89 + 174) = v20;
        v21 = sub_1324D0(v20);
        v22 = *v1;
        *(_BYTE *)(v89 + 177) = v21;
        if ( *v22 < 0 && v21 > 3 && v21 != 12 )
          sub_12F32C(dword_1400B0, dword_14009C, 3010);
        v90 = v5 + 200 * v2;
        v23 = sub_1324EC(*(unsigned __int16 *)(v90 + 174));
        v24 = *v1;
        *(_BYTE *)(v90 + 178) = v23;
        if ( *v24 < 0 && v23 > 3 && v23 != 12 )
          sub_12F32C(dword_1400AC, dword_14009C, 3012);
        *(_BYTE *)(v5 + 200 * v2 + 182) = (*(_WORD *)(a1 + 348) & 0x400) != 0;
        if ( sub_10198C() )
        {
          v25 = *(_DWORD *)(a1 + 240);
          if ( (*((_DWORD *)v96 + 12) & 0x10) != 0 && (v25 & 0x10) != 0 )
            v85 |= 0x40u;
        }
        else
        {
          v25 = *(_DWORD *)(a1 + 240);
        }
        v26 = v25 & 3;
        if ( v26 == 1 )
        {
          *(_WORD *)(v5 + 200 * v2 + 186) = 7917;
        }
        else if ( v26 == 2 )
        {
          *(_WORD *)(v5 + 200 * v2 + 186) = 11380;
        }
        else
        {
          *(_WORD *)(v5 + 200 * v2 + 186) = 3821;
        }
      }
      else
      {
        *(_BYTE *)(v12 + 169) = 2;
        v94 = sub_1324B4((unsigned __int8 *)(a1 + 211));
        v43 = sub_1324B4((unsigned __int8 *)dword_13FE28);
        v44 = a1 + 211;
        if ( v43 >= v94 )
          v43 = v94;
        v45 = *v1;
        *(_BYTE *)(v5 + 200 * v2 + 180) = v43;
        if ( *v45 < 0 && v43 > 3 )
        {
          sub_12F32C(dword_1400B4, dword_14009C, 3054);
          v44 = a1 + 211;
        }
        sub_143630(v9 + 170 + v5, v44, 4);
        v46 = v5 + 200 * v2;
        v47 = *(_WORD *)(v46 + 174);
        *(_BYTE *)(v46 + 170) = -1;
        v48 = v47 & 0xF00F;
        *(_BYTE *)(v46 + 176) = 7;
        *(_WORD *)(v46 + 174) = v48;
        v49 = sub_1324D0(v48);
        v50 = *v1;
        *(_BYTE *)(v5 + 200 * v2 + 177) = v49;
        if ( *v50 < 0 && v49 > 3 && v49 != 12 )
          sub_12F32C(dword_1400B0, dword_14009C, 3065);
        v95 = v5 + 200 * v2;
        v51 = sub_1324EC(*(unsigned __int16 *)(v95 + 174));
        v52 = *v1;
        *(_BYTE *)(v95 + 178) = v51;
        if ( *v52 < 0 && v51 > 3 && v51 != 12 )
          sub_12F32C(dword_1400AC, dword_14009C, 3067);
        *(_BYTE *)(v5 + 200 * v2 + 182) = (*(_WORD *)(a1 + 348) & 0x400) != 0;
        if ( sub_10198C() )
        {
          v53 = *(_WORD *)(a1 + 208);
          if ( (*((_WORD *)off_1400A8 + 6) & 1) != 0 && (v53 & 1) != 0 )
            v85 |= 0x40u;
        }
        else
        {
          v53 = *(_WORD *)(a1 + 208);
        }
        if ( (v53 & 0x800) != 0 )
          v54 = 4021;
        else
          v54 = 3839;
        *(_WORD *)(v5 + 200 * v2 + 186) = v54;
      }
      goto LABEL_53;
    }
    v56 = *(unsigned __int8 *)(a1 + 34);
    v57 = *(unsigned __int16 *)(a1 + 270);
    *(_BYTE *)(v12 + 169) = 5;
    v97 = v56;
    v98 = sub_13248C(v57);
    v58 = sub_13248C(*((unsigned __int16 *)off_13FE2C + 40));
    if ( v58 >= v98 )
      v58 = v98;
    v59 = *v1;
    *(_BYTE *)(v5 + 200 * v2 + 180) = v58;
    if ( *v59 < 0 && v58 > 7 )
      sub_12F32C(dword_1400BC, dword_14009C, 2869);
    v60 = sub_1326E0(*(unsigned __int16 *)(a1 + 270), *((unsigned __int16 *)off_13FE2C + 40));
    v61 = *(_WORD *)(a1 + 270);
    *(_WORD *)(v5 + 200 * v2 + 170) = v60;
    v99 = sub_132474(v61);
    v62 = sub_132474(*((_WORD *)off_13FE2C + 40));
    if ( v62 >= v99 )
      v62 = v99;
    v63 = *v1;
    *(_BYTE *)(v5 + 200 * v2 + 176) = v62;
    if ( *v63 < 0 && v62 > 0xB )
      sub_12F32C(dword_1400C0, dword_14009C, 2875);
    v100 = v5 + 200 * v2;
    v64 = *(_WORD *)(v100 + 174) & 0xF00F;
    *(_WORD *)(v100 + 174) = v64;
    v65 = sub_1324D0(v64);
    v66 = *v1;
    *(_BYTE *)(v100 + 177) = v65;
    if ( *v66 < 0 && v65 > 3 && v65 != 12 )
      sub_12F32C(dword_1400B0, dword_14009C, 2879);
    v101 = v5 + 200 * v2;
    v67 = sub_1324EC(*(unsigned __int16 *)(v101 + 174));
    v68 = *v1;
    *(_BYTE *)(v101 + 178) = v67;
    if ( *v68 < 0 && v67 > 3 && v67 != 12 )
      sub_12F32C(dword_1400AC, dword_14009C, 2881);
    *(_BYTE *)(v5 + 200 * v2 + 182) = (*(_WORD *)(a1 + 348) & 0x400) != 0;
    if ( sub_10198C()
      && (*((_BYTE *)off_13FE2C + 67) & 0x20) != 0
      && (*(_BYTE *)(a1 + 309) || (*(_BYTE *)(a1 + 259) & 0x20) != 0) )
    {
      v85 |= 0x40u;
    }
    if ( (*(_DWORD *)(a1 + 4) & 4) != 0 )
    {
      v69 = *(_DWORD *)(a1 + 240) & 3;
      if ( v69 == 1 )
      {
        *(_WORD *)(v5 + 200 * v2 + 186) = 7917;
      }
      else if ( v69 == 2 )
      {
        *(_WORD *)(v5 + 200 * v2 + 186) = 11380;
      }
      else
      {
        *(_WORD *)(v5 + 200 * v2 + 186) = 3821;
      }
    }
    else
    {
      if ( (*(_WORD *)(a1 + 208) & 0x800) != 0 )
        v84 = 7935;
      else
        v84 = 3839;
      *(_WORD *)(v5 + 200 * v2 + 186) = v84;
    }
    v70 = dword_13FE30 + 1320 * v97;
    v71 = *(unsigned __int8 *)(v70 + 106);
    if ( *(_BYTE *)(v70 + 106) )
    {
      v72 = *(_DWORD *)(v70 + 468);
      *(_DWORD *)(*(_DWORD *)(a1 + 336) + 60) &= ~0x80000000;
      if ( v72 < 0 )
      {
LABEL_73:
        if ( v71 == 2 )
        {
          v8 |= 0x10020000u;
LABEL_75:
          v75 = *((unsigned __int8 *)off_13FE2C + 69);
          v76 = (*(unsigned __int8 *)(a1 + 261) >> 3) & 3;
          if ( v76 >= (v75 & 3) )
            v76 = v75 & 3;
          v77 = v5 + 200 * v2;
          *(_BYTE *)(v77 + 194) = 1;
          switch ( v76 )
          {
            case 1u:
              *(_BYTE *)(v77 + 195) = 0;
              break;
            case 2u:
              *(_BYTE *)(v77 + 195) = 1;
              break;
            case 0u:
              *(_BYTE *)(v77 + 194) = 0;
LABEL_84:
              *(_BYTE *)(v5 + 200 * v2 + 183) = (*((_BYTE *)off_13FE2C + 72) & *(_BYTE *)(a1 + 264) & 0x20) != 0;
LABEL_53:
              v55 = *(unsigned __int8 *)(a1 + 309);
              v31 = *v1;
              *(_BYTE *)(v5 + 200 * v2 + 179) = v55;
              if ( *v31 < 0 && v55 > 3 )
              {
                sub_12F32C(dword_1400A0, dword_14009C, 3099);
                v55 = *(unsigned __int8 *)(a1 + 309);
                v31 = *v1;
              }
              switch ( v55 )
              {
                case 0u:
                  if ( (*(_WORD *)(a1 + 208) & 0x20) != 0 )
                    goto LABEL_86;
                  break;
                case 1u:
                  if ( (*(_WORD *)(a1 + 208) & 0x40) != 0 )
                    goto LABEL_86;
                  break;
                case 2u:
                  if ( (*(_DWORD *)(a1 + 240) & 0x20) != 0 )
                    goto LABEL_86;
                  break;
                case 3u:
                  if ( (*(_DWORD *)(a1 + 240) & 0x40) != 0 )
LABEL_86:
                    *(_BYTE *)(v5 + 200 * v2 + 181) = 1;
                  break;
                default:
                  goto LABEL_25;
              }
              goto LABEL_25;
            default:
              *(_BYTE *)(v77 + 195) = 4;
              break;
          }
          v78 = *((_BYTE *)off_13FE2C + 75);
          v79 = *((unsigned __int8 *)off_13FE2C + 74);
          v80 = v75 >> 2;
          v81 = v5 + 200 * v2;
          *(_BYTE *)(v81 + 196) = v80 & (*(_BYTE *)(a1 + 261) >> 5) & 1;
          v82 = ((int)*(unsigned __int8 *)(a1 + 266) >> 6) | (4 * (*(_BYTE *)(a1 + 267) & 1));
          v83 = (v79 >> 6) | (4 * (v78 & 1));
          if ( v82 >= v83 )
            LOBYTE(v82) = v83;
          *(_BYTE *)(v81 + 197) = v82;
          goto LABEL_84;
        }
LABEL_74:
        v8 |= 0x10060000u;
        goto LABEL_75;
      }
    }
    else
    {
      v72 = *(_DWORD *)(v70 + 468);
      v73 = *(_DWORD *)(a1 + 336);
      v74 = *(_DWORD *)(v73 + 60);
      if ( (v72 & 0x10000) != 0 )
      {
        *(_DWORD *)(v73 + 60) = v74 & 0x7FFFFFFF;
        if ( v72 < 0 )
          goto LABEL_74;
      }
      else
      {
        *(_DWORD *)(v73 + 60) = v74 | 0x80000000;
        if ( v72 < 0 )
          goto LABEL_74;
      }
    }
    v8 |= (HIBYTE(v72) & 0x3F) << 20;
    goto LABEL_73;
  }
  v27 = sub_132654((unsigned __int8 *)(a1 + 192), 0);
  v91 = v5 + 200 * v2;
  *(_WORD *)(v91 + 174) = v27;
  v28 = sub_1324D0(v27);
  v29 = *v1;
  *(_BYTE *)(v91 + 177) = v28;
  if ( *v29 < 0 && v28 > 0xB )
    sub_12F32C(dword_13FAA0, dword_13FA94, 3130);
  v92 = v5 + 200 * v2;
  v30 = sub_1324EC(*(unsigned __int16 *)(v92 + 174));
  v31 = *v1;
  *(_BYTE *)(v92 + 178) = v30;
  if ( *v31 < 0 && v30 > 0xB )
  {
    sub_12F32C(dword_13FE24, dword_13FE1C, 3132);
    v31 = *v1;
  }
  v32 = v5 + 200 * v2;
  *(_BYTE *)(v32 + 176) = -1;
  v33 = *(unsigned __int8 *)(a1 + 309);
  *(_BYTE *)(v32 + 179) = v33;
  if ( *v31 < 0 && v33 )
  {
    sub_12F32C(dword_13FE20, dword_13FE1C, 3135);
    v31 = *v1;
  }
  *(_BYTE *)(v5 + 200 * v2 + 182) = (*(_WORD *)(a1 + 348) & 0x400) != 0;
LABEL_25:
  v93 = v31;
  v34 = sub_13D20C(v7);
  *(_WORD *)(v5 + 200 * v2 + 184) = v34;
  if ( *v93 < 0 )
  {
    if ( !v34 )
    {
      sub_12F32C(dword_1400A4, dword_14009C, 3141);
      if ( **v1 >= 0 )
        goto LABEL_26;
      v34 = *(unsigned __int16 *)(v5 + 200 * v2 + 184);
    }
    if ( v34 > 0xA )
      sub_12F32C(dword_13FA98, dword_13FA94, 3142);
  }
LABEL_26:
  v35 = 200 * v2;
  sub_12EB90(
    4096,
    dword_13FA80,
    dword_13FA7C,
    *(unsigned __int8 *)(a1 + 35),
    *(unsigned __int8 *)(v5 + v35 + 169),
    *(unsigned __int8 *)(v5 + v35 + 182),
    *(unsigned __int8 *)(v5 + v35 + 181),
    *(unsigned __int8 *)(v5 + v35 + 179));
  sub_12EB90(
    4096,
    dword_13FA84,
    dword_13FA7C,
    *(unsigned __int8 *)(v5 + v35 + 176),
    *(unsigned __int8 *)(v5 + v35 + 177),
    *(unsigned __int8 *)(v5 + v35 + 178),
    *(unsigned __int8 *)(v5 + v35 + 194),
    *(unsigned __int8 *)(v5 + v35 + 183));
  sub_13F654(*(unsigned __int8 *)(a1 + 35));
  v36 = (__int16 *)(v9 + 136 + v5);
  v37 = v3 + 5;
  do
  {
    v38 = *v36++;
    *v37++ = *(unsigned __int16 *)(v35 + 12 * (unsigned __int8)v38 + v5 + 10) | 0x40000000;
  }
  while ( v3 + 9 != v37 );
  *(_WORD *)(v5 + v35 + 192) = 0;
  sub_13D33C(v7);
  v39 = dword_13FA8C;
  *(_DWORD *)(v5 + v35) = *((_DWORD *)off_13FA88 + 4);
  v40 = dword_13FA90;
  *v3 = v39;
  v3[3] = v86 << 10;
  v3[4] = v40;
  v3[1] = v85;
  v3[2] = v8;
  result = sub_101A18();
  if ( result )
    v3[2] |= 0x200u;
  v42 = *(_DWORD *)(a1 + 336);
  *(_DWORD *)(v42 + 56) = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(v42 + 52) = 8704;
  *(_BYTE *)(a1 + 350) |= 0x11u;
  return result;
}

