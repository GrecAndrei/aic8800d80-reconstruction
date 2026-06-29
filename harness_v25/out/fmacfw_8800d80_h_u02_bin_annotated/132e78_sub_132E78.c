// fwstruct annotate: 132e78_sub_132E78.c
// sub_132E78 @ 0x132e78, size 1500 bytes
_BYTE *__fastcall sub_132E78(int a1, __int16 a2, unsigned int a3)
{
  int v4; // r3
  int v5; // r6
  int v6; // r0
  int v7; // r7
  int *v8; // r4
  unsigned int v9; // r8
  unsigned __int8 *v10; // r9
  unsigned __int16 v11; // r11
  int v12; // r6
  _BYTE *v13; // r11
  unsigned __int8 *v14; // s17
  int v15; // r2
  int v16; // r1
  _BYTE *result; // r0
  int v18; // r6
  int v19; // r3
  int v20; // r1
  __int16 v21; // r3
  int v22; // r9
  __int16 **v23; // r10
  int v24; // r0
  int v25; // r2
  __int16 v26; // r3
  int v27; // r1
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r2
  int v31; // r2
  char v32; // r12
  int v33; // r3
  char v34; // r0
  int v35; // r1
  char v36; // r2
  int v37; // r3
  char v38; // r0
  int v39; // r0
  int v40; // r1
  char v41; // r0
  int v42; // r2
  char v43; // lr
  int v44; // r0
  char v45; // r2
  int v46; // r1
  char v47; // lr
  int v48; // r11
  int *v49; // r4
  int v50; // r0
  int v51; // t1
  _BYTE *v52; // r0
  char v53; // r2
  __int16 v54; // r3
  unsigned __int8 *v55; // r0
  unsigned int v56; // r3
  int v57; // r3
  int v58; // r0
  int *v59; // r0
  unsigned int v60; // r2
  int v61; // r3
  int v62; // r3
  unsigned __int8 *v63; // r0
  int v64; // r0
  __int64 v65; // kr00_8
  unsigned int v66; // [sp+4h] [bp-20h]
  int v67; // [sp+8h] [bp-1Ch]
  unsigned __int8 *v68; // [sp+Ch] [bp-18h]
  int v69; // [sp+Ch] [bp-18h]
  int *v70; // [sp+Ch] [bp-18h]
  int v72; // [sp+14h] [bp-10h]
  _BYTE *v73; // [sp+14h] [bp-10h]
  _BYTE v74[5]; // [sp+1Fh] [bp-5h] BYREF

  v4 = *(_DWORD *)(a1 + 468);
  v5 = *(unsigned __int8 *)(a1 + 464);
  v6 = *(unsigned __int8 *)(a1 + 412);
  v7 = *(unsigned __int16 *)(a1 + 462);
  v8 = *(int **)(a1 + 240);
  v9 = *(unsigned __int8 *)(a1 + 413);
  v67 = v5;
  *(_WORD *)(a1 + 462) = 0;
  v66 = v4 & 0xFF000000;
  v10 = (unsigned __int8 *)(a3 + 36);
  v11 = a2 - 36;
  if ( v6 )
    goto LABEL_2;
  v12 = v11;
  v52 = sub_12DAA0(v10, v11);
  if ( !v52 )
    goto LABEL_2;
  v53 = v52[2];
  v54 = *(_WORD *)(a1 + 462) & 0xFFF8;
  if ( (v53 & 1) != 0 )
    v54 |= 1u;
  *(_WORD *)(a1 + 462) = v54;
  if ( (v53 & 4) != 0 )
    *(_WORD *)(a1 + 462) |= 4u;
  else
LABEL_2:
    v12 = v11;
  if ( (*(_DWORD *)(a1 + 472) & 1) != 0 )
  {
    v48 = *(unsigned __int8 *)(a1 + 106);
    if ( !*(_BYTE *)(a1 + 106) )
    {
      sub_130F1C(v10, v12, a1 + 440, v74);
      if ( v74[0] )
      {
        v70 = v8;
        v49 = (int *)(a1 + 440);
        do
        {
          v50 = sub_12C7EC(26, 0, 5, 8u);
          v51 = *v49++;
          *(_DWORD *)v50 = v51;
          *(_BYTE *)(v50 + 5) = v48;
          *(_BYTE *)(v50 + 6) = *(_BYTE *)(a1 + 107);
          ++v48;
          *(_BYTE *)(v50 + 4) = 0;
          sub_12C84C(v50);
        }
        while ( v48 != 4 );
        v8 = v70;
      }
    }
  }
  v13 = off_1332E8;
  if ( (*((_BYTE *)off_1332E8 + 374) & 1) == 0 )
  {
    v14 = (unsigned __int8 *)(*((_BYTE *)off_1332E8 + 374) & 1);
    v68 = v14;
LABEL_6:
    sub_132BD8((int)v14, v68, a1 + 248);
    goto LABEL_7;
  }
  v14 = sub_12DD78(v10, v12);
  if ( (v13[374] & 6) != 0 )
  {
    v68 = sub_12DDB8(v10, v12);
    if ( !*(_BYTE *)(a1 + 106) )
    {
      v63 = sub_12DAE0(v10, v12);
      if ( v63
        && (*(_DWORD *)(dword_133454 + 696 * *(unsigned __int8 *)(a1 + 116) + 4) & 0x24) != 0
        && (v63[2] & 0x80u) == 0 )
      {
        sub_132C48(*(unsigned __int8 *)(a1 + 116), v63[2] & 3);
      }
      if ( (*(_DWORD *)(a1 + 472) & 8) != 0 )
      {
        v73 = (_BYTE *)sub_12C7EC(109, 0, 5, 2u);
        sub_131170(v10, v12, v73);
        sub_12C84C((int)v73);
        sub_131118(v10, v12, a1 + 348, v74);
        if ( v74[0] )
        {
          v64 = sub_12C7EC(107, 0, 5, 0x10u);
          v65 = *(_QWORD *)(a1 + 352);
          *(_DWORD *)v64 = *(_DWORD *)(a1 + 348);
          *(_DWORD *)(v64 + 12) = *(_DWORD *)(a1 + 360);
          *(_QWORD *)(v64 + 4) = v65;
          sub_12C84C(v64);
        }
      }
    }
    if ( (v13[374] & 4) == 0 )
      goto LABEL_6;
    v55 = sub_1310F0(v10, v12, a1 + 248);
    if ( v55 )
    {
      v56 = *(_DWORD *)(a1 + 468);
      v72 = (v56 >> 4) & 0x3FF;
      if ( *(_BYTE *)(a1 + 106) == 2 )
      {
        v57 = v56 | 0x10000;
        *(_DWORD *)(a1 + 468) = v57;
        *(_DWORD *)(v55 + 3) = v57;
      }
      if ( !v72 )
        goto LABEL_102;
    }
    else
    {
      LOWORD(v72) = 1023;
    }
    v58 = sub_12C7EC(111, 0, 5, 4u);
    *(_WORD *)v58 = v72;
    *(_BYTE *)(v58 + 2) = *(_BYTE *)(a1 + 107);
    sub_12C84C(v58);
LABEL_102:
    if ( (*(_DWORD *)(a1 + 468) & 0xFF000000) != v66 )
    {
      v59 = (int *)sub_12C7EC(113, 0, 5, 4u);
      v60 = *(_DWORD *)(a1 + 468);
      v61 = HIBYTE(v60) & 0x3F;
      if ( (v60 & 0x40000000) != 0 )
        v62 = v61 | 0x300;
      else
        v62 = v61 | 0x100;
      *v59 = v62;
      sub_12C84C((int)v59);
    }
    goto LABEL_6;
  }
  sub_132BD8((int)v14, nullptr, a1 + 248);
LABEL_7:
  v15 = (unsigned __int8)sub_130E10(v10, v12, v74, a1 + 1212);
  if ( v15 )
  {
    if ( *(_BYTE *)(a1 + 106) )
    {
      if ( *(_BYTE *)(a1 + 106) == 2 )
        *(_BYTE *)(a1 + 231) = v15;
    }
    else
    {
      v16 = *(unsigned __int8 *)(a1 + 146);
      if ( *(_BYTE *)(a1 + 146)
        || *(_BYTE *)(a1 + 148)
        && v74[0] == 1
        && (v69 = v15,
            sub_12249C(*(_BYTE *)(a1 + 107), v16),
            v16 = *(unsigned __int8 *)(a1 + 146),
            v15 = v69,
            *(_BYTE *)(a1 + 146)) )
      {
        if ( v15 != v16 )
          *(_BYTE *)(a1 + 148) = 1;
      }
      *(_BYTE *)(a1 + 146) = v15;
    }
  }
  result = sub_130D04(v10, v12, a1 + 248);
  if ( *(unsigned __int8 *)(a1 + 464) != v67 )
    result = (_BYTE *)sub_12C444(a1);
  if ( *(unsigned __int8 *)(a1 + 413) > v9 )
  {
    if ( !*(_DWORD *)(a1 + 72) )
      sub_12E9D8(a3, 32, 1, 0);
    v18 = sub_12C7EC(59, 0, 5, 0xCu);
    v19 = *(_DWORD *)(a1 + 72);
    if ( **(__int16 **)off_1332CC < 0 && !v19 )
    {
      sub_12F32C(dword_1332E4, dword_1332E0, 70);
      v19 = *(_DWORD *)(a1 + 72);
    }
    *(_BYTE *)v18 = *(_BYTE *)(v19 + 24);
    v20 = *(_DWORD *)(a1 + 416);
    v21 = *(_WORD *)(a1 + 420);
    *(_DWORD *)(v18 + 2) = *(_DWORD *)(a1 + 412);
    *(_DWORD *)(v18 + 6) = v20;
    *(_WORD *)(v18 + 10) = v21;
    result = (_BYTE *)sub_12C84C(v18);
  }
  if ( v8 )
  {
    v22 = dword_1332EC;
    v23 = (__int16 **)off_1332CC;
    do
    {
      if ( *(unsigned __int16 *)(a1 + 462) != v7 )
      {
        sub_12E948(v22, v7);
        v24 = *((unsigned __int8 *)v8 + 35);
        v25 = *(unsigned __int16 *)(a1 + 462) << 29;
        v26 = *((unsigned __int8 *)v8 + 350) | 2;
        v27 = 0;
        *((_BYTE *)v8 + 350) = v26;
        if ( v25 >= 0 )
          v26 = 1024;
        v8[86] = 0;
        if ( v25 >= 0 )
        {
          *((_WORD *)v8 + 174) = v26;
          v27 = 1;
        }
        else
        {
          *((_WORD *)v8 + 174) = 0;
        }
        result = (_BYTE *)sub_13F104(v24, v27);
      }
      v28 = *(unsigned __int8 *)(a1 + 413);
      if ( v28 == v9 )
        goto LABEL_48;
      v29 = *((unsigned __int8 *)v8 + 308);
      if ( v28 == 4 )
      {
        if ( v29 <= 3 )
        {
          if ( v29 >= 2 )
            v29 = 2;
          goto LABEL_38;
        }
      }
      else
      {
        if ( v28 >= v29 )
          v28 = *((unsigned __int8 *)v8 + 308);
        if ( v28 != 4 )
        {
          v29 = (unsigned __int8)v28;
          goto LABEL_38;
        }
      }
      v29 = 3;
LABEL_38:
      if ( *((unsigned __int8 *)v8 + 309) != v29 )
      {
        v30 = v8[1];
        if ( (v30 & 0x20) != 0 )
        {
          if ( **v23 < 0 && (v13[374] & 4) == 0 )
            sub_12F32C(dword_1332D4, dword_1332D0, 463);
          v31 = 14;
          v32 = 7;
          do
          {
            v33 = ((int)*((unsigned __int16 *)v8 + 135) >> v31) & 3;
            v34 = v32 - 1;
            v31 -= 2;
            if ( v33 != 3 )
              break;
            --v32;
          }
          while ( v34 );
          v35 = 14;
          v36 = 7;
          do
          {
            v37 = ((int)*((unsigned __int16 *)v13 + 40) >> v35) & 3;
            v38 = v36 - 1;
            v35 -= 2;
            if ( v37 != 3 )
              break;
            --v36;
          }
          while ( v38 );
        }
        else if ( (v30 & 4) != 0 )
        {
          if ( **v23 < 0 && (v13[374] & 2) == 0 )
            sub_12F32C(dword_1332DC, dword_1332D0, 476);
          v40 = 14;
          v41 = 7;
          do
          {
            v42 = ((int)*((unsigned __int16 *)v8 + 122) >> v40) & 3;
            v43 = v41 - 1;
            v40 -= 2;
            if ( v42 != 3 )
              break;
            --v41;
          }
          while ( v43 );
          v44 = 14;
          v45 = 7;
          do
          {
            v46 = ((int)*((unsigned __int16 *)v13 + 28) >> v44) & 3;
            v47 = v45 - 1;
            v44 -= 2;
            if ( v46 != 3 )
              break;
            --v45;
          }
          while ( v47 );
        }
        else if ( **v23 < 0 && (v13[374] & 1) == 0 )
        {
          sub_12F32C(dword_1332D8, dword_1332D0, 487);
        }
        v39 = *((unsigned __int8 *)v8 + 35);
        *((_BYTE *)v8 + 309) = v29;
        result = (_BYTE *)sub_13F03C(v39);
        *((_BYTE *)v8 + 350) |= 8u;
      }
LABEL_48:
      if ( (*(_DWORD *)(a1 + 468) & 0xFF000000) != v66 && (v8[1] & 0x20) != 0 )
        *((_BYTE *)v8 + 350) |= 0x40u;
      v8 = (int *)*v8;
    }
    while ( v8 );
  }
  return result;
}

