// fwstruct annotate: 10d660_sub_10D660.c
// sub_10D660 @ 0x10d660, size 1016 bytes
int __fastcall sub_10D660(int a1, int a2)
{
  int v2; // r4
  unsigned int CPSR; // r6
  int v4; // r0
  int v5; // r1
  int v6; // r7
  int v7; // r5
  int v8; // r3
  unsigned __int8 *v9; // r4
  _DWORD *v10; // r1
  _DWORD *v11; // r0
  unsigned __int8 *v12; // r5
  int v13; // r2
  int v14; // t1
  int v16; // r3
  _BYTE **v17; // r8
  int v18; // r0
  _DWORD *v19; // r2
  int *v20; // r4
  int v21; // r1
  int v22; // t1
  int v23; // r1
  _BYTE *v24; // r8
  int v25; // r9
  _BYTE *v26; // r0
  _BYTE *v27; // r8
  _BYTE *v28; // r9
  int v29; // r0
  _DWORD *v30; // r2
  int *v31; // r12
  int v32; // r1
  int v33; // t1
  unsigned __int16 *v34; // r10
  int v35; // r11
  int v36; // r0
  _DWORD *v37; // r2
  int *v38; // r5
  int v39; // r1
  int v40; // t1
  int *v41; // r3
  int v42; // r0
  int v43; // r8
  int v44; // r3
  _BYTE *v45; // r1
  unsigned int v46; // r2
  __int16 v47; // r0
  _DWORD *v48; // r5
  int v49; // r2
  int *v50; // r5
  int v51; // r0
  int v52; // r0
  int v53; // r3
  int v54; // r2
  int v55; // r0
  _DWORD *v56; // r2
  int *v57; // r4
  int v58; // r1
  int v59; // t1
  int v60; // r0
  _DWORD *v61; // r2
  int *v62; // r4
  int v63; // r1
  int v64; // t1
  int v65; // r0
  _DWORD *v66; // r2
  int *v67; // r12
  int v68; // r1
  int v69; // t1
  int v70; // r2
  __int64 v71; // r0
  int (__fastcall *v72)(_DWORD); // r2
  int v73; // r0
  _WORD *v74; // r2
  int v75; // r2
  unsigned __int16 v76; // r5
  int v77; // r1
  _DWORD *v78; // r2
  int *v79; // r0
  int v80; // t1
  int *v81; // [sp+Ch] [bp-108h]
  _BYTE v82[260]; // [sp+10h] [bp-104h] BYREF

  CPSR = __get_CPSR();
  v4 = sub_12E344(v82, 256, 0, a1, a2);
  v6 = v4;
  if ( v4 <= 0 )
    return v6;
  v7 = v4;
  if ( *(_DWORD *)off_10D92C )
  {
    if ( CPSR )
      goto LABEL_5;
  }
  else
  {
    sub_10D4A0();
    if ( CPSR )
      goto LABEL_5;
  }
  while ( !*(_DWORD *)off_10D930 )
    ;
LABEL_5:
  if ( !*(_DWORD *)off_10D934 )
  {
    do
      v5 = *(_DWORD *)off_10D938 << 12;
    while ( (*(_DWORD *)off_10D938 & 0x80000) != 0 );
    *(_DWORD *)off_10D93C = 95;
  }
  v8 = *((_WORD *)off_10D940 + 89) & 0x4000;
  if ( (*((_WORD *)off_10D940 + 89) & 0x4000) == 0 )
  {
    v9 = v82;
    v10 = off_10D938;
    v11 = off_10D93C;
    v12 = &v82[v7];
    do
    {
      v14 = *v9++;
      v13 = v14;
      if ( v14 == 10 && v8 != 13 )
      {
        while ( (*v10 & 0x80000) != 0 )
          ;
        *v11 = 13;
        v13 = *(v9 - 1);
      }
      while ( (*v10 & 0x80000) != 0 )
        ;
      *v11 = v13;
      v8 = *(v9 - 1);
    }
    while ( v9 != v12 );
    goto LABEL_13;
  }
  v16 = **(unsigned __int8 **)off_10D944;
  if ( v16 == 1 )
  {
    if ( **(_BYTE **)off_10D94C != 3 )
    {
      if ( v7 >= 124 )
        LOWORD(v7) = 124;
      sub_1110CC(19, v82, (unsigned __int16)v7);
    }
    goto LABEL_13;
  }
  if ( v16 != 2 )
    goto LABEL_13;
  v17 = (_BYTE **)off_10D94C;
  if ( **(_BYTE **)off_10D94C == 3 )
  {
LABEL_19:
    v18 = dword_10D948;
    v19 = off_10D938;
    v20 = (int *)off_10D93C;
    v21 = 110;
    do
    {
      while ( (*v19 & 0x80000) != 0 )
        ;
      *v20 = v21;
      v22 = *(unsigned __int8 *)++v18;
      v21 = v22;
    }
    while ( v22 );
    goto LABEL_13;
  }
  if ( (unsigned int)sub_12D594(dword_10D950, v5) <= 4 )
  {
    if ( **(_BYTE **)off_10D944 == 2 )
    {
      if ( **v17 != 3 )
      {
        if ( (unsigned int)sub_12D594(dword_10D950, v23) > 4 )
        {
          v60 = dword_10D97C;
          v61 = off_10D938;
          v62 = (int *)off_10D93C;
          v63 = 111;
          do
          {
            while ( (*v61 & 0x80000) != 0 )
              ;
            *v62 = v63;
            v64 = *(unsigned __int8 *)++v60;
            v63 = v64;
          }
          while ( v64 );
        }
        else
        {
          v55 = dword_10D978;
          v56 = off_10D938;
          v57 = (int *)off_10D93C;
          v58 = 102;
          do
          {
            while ( (*v56 & 0x80000) != 0 )
              ;
            *v57 = v58;
            v59 = *(unsigned __int8 *)++v55;
            v58 = v59;
          }
          while ( v59 );
        }
        goto LABEL_13;
      }
      goto LABEL_19;
    }
LABEL_13:
    if ( !CPSR )
      *(_DWORD *)off_10D930 = 1;
    return v6;
  }
  v24 = v82;
  v25 = dword_10D980;
  while ( 1 )
  {
    v26 = v24++;
    if ( !sub_1437AC(v26, v25, 20) )
      break;
    if ( &v82[v7] == v24 )
    {
      v27 = off_10D984;
      goto LABEL_37;
    }
  }
  v65 = dword_10DA58;
  v66 = off_10DA5C;
  v67 = (int *)off_10DA74;
  v68 = 70;
  do
  {
    while ( (*v66 & 0x80000) != 0 )
      ;
    *v67 = v68;
    v69 = *(unsigned __int8 *)++v65;
    v68 = v69;
  }
  while ( v69 );
  v27 = off_10DA78;
  v70 = *(_DWORD *)off_10DA60;
  v81 = (int *)off_10DA64;
  v71 = *(_QWORD *)(v70 + 4);
  v72 = *(int (__fastcall **)(_DWORD))(HIDWORD(v71) + 16);
  *(_BYTE *)off_10DA78 = 1;
  v73 = v72(v71);
  v74 = off_10DA68;
  *v81 = v73;
  *v74 = 4;
LABEL_37:
  if ( *v27 )
  {
    v28 = off_10D988;
    if ( !sub_1437AC(v82, dword_10D954, 5) )
    {
      v29 = dword_10D958;
      v30 = off_10D938;
      v31 = (int *)off_10D93C;
      *v28 = 1;
      v32 = 80;
      do
      {
        while ( (*v30 & 0x80000) != 0 )
          ;
        *v31 = v32;
        v33 = *(unsigned __int8 *)++v29;
        v32 = v33;
      }
      while ( v33 );
    }
    v34 = (unsigned __int16 *)off_10D98C;
    v35 = *(unsigned __int16 *)off_10D98C;
    if ( v35 + v7 <= 1720 )
    {
      v81 = (int *)off_10DA64;
      sub_14380C(*(_DWORD *)off_10DA64 + v35, v82, v7);
      v75 = (unsigned __int8)*v28;
      v41 = v81;
      v76 = v7 + *v34;
      v35 = v76;
      *v34 = v76;
      if ( !v75 )
        return v6;
    }
    else
    {
      v36 = dword_10D95C;
      v37 = off_10D938;
      v38 = (int *)off_10D93C;
      v39 = 66;
      do
      {
        while ( (*v37 & 0x80000) != 0 )
          ;
        *v38 = v39;
        v40 = *(unsigned __int8 *)++v36;
        v39 = v40;
      }
      while ( v40 );
      v41 = (int *)off_10D960;
    }
    v42 = dword_10D950;
    *v27 = 0;
    *v28 = 0;
    v43 = *v41;
    *v34 = 4;
    *v41 = 0;
    v6 = v35;
    sub_12D4F8(v42);
    goto LABEL_48;
  }
  v2 = sub_12D4F8(dword_10DA6C);
  if ( v7 <= 122 )
    v43 = sub_113864();
  else
    v43 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)(*(_DWORD *)off_10DA60 + 8) + 16))(*(_DWORD *)(*(_DWORD *)off_10DA60
                                                                                                  + 4));
  if ( v43 )
  {
    sub_14380C(v43 + 4, v82, v7);
    LOWORD(v35) = v7;
LABEL_48:
    *(_WORD *)v43 = v6 + 1;
    *(_BYTE *)(v43 + 2) = 19;
    v44 = 0;
    v45 = off_10D964;
    *(_BYTE *)(v43 + 3) = 0;
    *(_BYTE *)(v43 + v6 + 4) = 0;
    v46 = *((unsigned __int16 *)v45 + 4122);
    if ( v46 > 0x186 )
    {
      LOWORD(v46) = 0;
      v47 = 1;
    }
    else
    {
      v47 = v46 + 1;
      v44 = 8 * v46;
    }
    v48 = off_10D968;
    *(_WORD *)(v2 + 12) = v46;
    v49 = *v48 + v44;
    *(_DWORD *)(v49 + 4) = v43;
    *(_WORD *)v49 = v35 + 5;
    *(_BYTE *)(v49 + 3) = *(_BYTE *)(v49 + 3) & 0x31 | 4;
    LOBYTE(v48) = v45[3074] + 1;
    *((_WORD *)v45 + 4122) = v47;
    v45[3074] = (_BYTE)v48;
    *(_DWORD *)(v2 + 4) = v49;
    *(_BYTE *)(v2 + 14) = 1;
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 8) = v6 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_10D96C = 1;
    }
    v50 = (int *)off_10D970;
    v51 = dword_10D974;
    ++*(_DWORD *)off_10D970;
    v52 = sub_12D470(v51);
    sub_113310(v52);
    if ( *v50 )
    {
      v53 = *v50 - 1;
      v54 = *(_DWORD *)off_10D96C;
      *v50 = v53;
      if ( !v53 )
      {
        if ( v54 )
          __enable_irq();
      }
    }
    goto LABEL_13;
  }
  v77 = dword_10DA70;
  v78 = off_10DA5C;
  v79 = (int *)off_10DA74;
  v6 = 110;
  do
  {
    while ( (*v78 & 0x80000) != 0 )
      ;
    *v79 = v6;
    v80 = *(unsigned __int8 *)++v77;
    v6 = v80;
  }
  while ( v80 );
  return v6;
}

