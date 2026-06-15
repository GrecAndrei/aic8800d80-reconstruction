// v23 annotated: sub_10AC18 @ 0x10ac18
// Original: 10ac18_sub_10AC18.c
// Primary struct: <unclustered>
//
// sub_10AC18 @ 0x10ac18, size 1062 bytes
int __fastcall sub_10AC18(unsigned int *a1, _BYTE *a2, int a3)
{
  int v3; // r9
  int v4; // r10
  int v5; // r11
  int v7; // r1
  unsigned int v8; // r2
  int v9; // lr
  int v10; // r12
  int v11; // r0
  int *v12; // r2
  int v13; // r4
  unsigned int *v14; // r1
  unsigned int *v15; // r6
  int *v16; // r4
  unsigned int v17; // r3
  unsigned int *v18; // r4
  int v19; // r2
  int v20; // r3
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  unsigned int *v25; // r1
  int v26; // r3
  unsigned int *v27; // r9
  int v28; // r10
  unsigned int v29; // r4
  unsigned int v30; // r3
  int v31; // r5
  int v32; // r4
  int v33; // r7
  int v34; // r9
  int v35; // r0
  int *v36; // r10
  int v37; // r1
  int v38; // r12
  unsigned int *v39; // r2
  unsigned int *v40; // r8
  int *v41; // r12
  int v42; // t1
  _DWORD *v43; // r0
  int v44; // r1
  unsigned int v45; // r3
  int v46; // r1
  int v48; // r8
  unsigned int *v49; // r2
  int *v50; // lr
  unsigned int *v51; // r8
  int v52; // t1
  int v53; // r6
  unsigned int *v54; // r1
  int *v55; // r5
  unsigned int *v56; // r6
  unsigned int v57; // r3
  int v58; // s16
  int i; // r8
  int v60; // r10
  int v61; // r7
  int v62; // r5
  int v63; // r6
  int v64; // r1
  int v65; // lr
  int v66; // r10
  int v67; // r3
  int v68; // r12
  int v69; // r5
  unsigned int *v70; // r11
  unsigned int v71; // r2
  unsigned int v72; // t1
  int v73; // r6
  _DWORD *v74; // r0
  int v75; // r3
  int v76; // r0
  bool v77; // cc
  int v78; // r3
  int v79; // r0
  int v80; // [sp+10h] [bp-1BCh]
  int v81; // [sp+14h] [bp-1B8h]
  unsigned int *v82; // [sp+18h] [bp-1B4h]
  _BYTE *v83; // [sp+1Ch] [bp-1B0h]
  int v84; // [sp+20h] [bp-1ACh]
  int v85; // [sp+24h] [bp-1A8h]
  int v88; // [sp+34h] [bp-198h]
  int v89; // [sp+38h] [bp-194h] BYREF
  int v90; // [sp+3Ch] [bp-190h]
  __int16 v91; // [sp+40h] [bp-18Ch]
  _DWORD v92[14]; // [sp+44h] [bp-188h] BYREF
  int v93; // [sp+7Ch] [bp-150h]
  _BYTE v94[128]; // [sp+88h] [bp-144h] BYREF
  _BYTE v95[196]; // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10AF6C;
  v4 = dword_10AF74;
  v5 = dword_10AF98;
  sub_11F504(dword_10AF4C, a2);
  v7 = *(_DWORD *)off_10AF50;
  v8 = *(_DWORD *)off_10AF50 & 0xFFFFFFFE;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  *(_DWORD *)off_10AF50 = v8;
  v85 = v7 & 1;
  sub_102ADC(0);
  v9 = dword_10AF70;
  v10 = dword_10AF78;
  v11 = 0;
  v12 = (int *)v95;
  do
  {
    if ( v11 )
    {
      if ( v11 != 1 )
      {
        v13 = v10;
        goto LABEL_5;
      }
      v13 = v4;
      v53 = v5;
    }
    else
    {
      v13 = v3;
      v53 = v9;
    }
    v54 = (unsigned int *)(v53 + 4);
    v55 = (int *)&v94[64 * v11];
    v56 = (unsigned int *)(v53 + 516);
    do
    {
      v57 = *v54;
      *v54 &= 0xFFF1FFFF;
      v54 += 8;
      *v55++ = (v57 >> 17) & 7;
    }
    while ( v54 != v56 );
LABEL_5:
    v14 = (unsigned int *)(v13 + 4);
    v15 = (unsigned int *)(v13 + 516);
    v16 = v12;
    do
    {
      v17 = *v14;
      *v14 &= 0xFFF1FFFF;
      v14 += 8;
      *v16++ = (v17 >> 17) & 7;
    }
    while ( v15 != v14 );
    ++v11;
    v12 += 16;
  }
  while ( v11 != 3 );
  v18 = (unsigned int *)off_10AF54;
  sub_102B40(0);
  sub_11F74C(1, dword_10AF58, v19, v20);
  v21 = dword_10AF5C;
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  sub_11F504(v21, v22);
  sub_11F74C(1, dword_10AF60, v23, v24);
  if ( (*(_DWORD *)off_10AF64 & 2) != 0 )
    v26 = 8;
  else
    v26 = 56;
  v27 = v18;
  v80 = v26 + a3;
  do
  {
    v28 = *(unsigned __int8 *)(a3 + 5);
    v29 = *(unsigned __int16 *)(a3 + 2);
    *v27 |= 0x400u;
    v30 = *v27 & 0xFFFFFBFF;
    *v27 = v30;
    if ( v28 == 1 )
    {
      sub_11F74C(1, dword_10AF88, v29, v30);
      if ( v29 > 0x1388 )
      {
        LOBYTE(v91) = 0;
        LOBYTE(v89) = 1;
        HIWORD(v89) = v29;
        LOWORD(v90) = v29;
        HIWORD(v90) = v29;
        sub_102908((unsigned __int8 *)&v89, 0);
        v79 = sub_102968(v29);
        v84 = dword_10B040 + 384 * v79;
        v82 = &a1[316 * (unsigned __int8)(v79 + 1)];
        v58 = (unsigned __int8)(v79 + 1);
        v83 = &a2[v58];
      }
      else
      {
        LOWORD(v90) = v29;
        LOBYTE(v89) = 0;
        LOBYTE(v91) = 0;
        sub_102908((unsigned __int8 *)&v89, 0);
        v84 = dword_10AF8C;
        v83 = a2;
        v58 = 0;
        v82 = a1;
        v28 = 0;
      }
      sub_107C70((int)(v82 + 292), v82, 255, 0, 0, dword_10AF90, 0);
      sub_100560(10000);
      v88 = a3;
      *v83 = 1;
      v81 = v28;
      for ( i = 0; i != 3; ++i )
      {
        if ( !v82[i] )
          sub_11F74C(1, dword_10B044, i, 0);
        if ( v81 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v60 = 1;
            else
              v60 = 2;
            if ( i == 1 )
              v61 = 8;
            else
              v61 = 9;
            if ( i == 1 )
              v62 = 64;
            else
              v62 = 96;
            if ( i == 1 )
              v63 = 32;
            else
              v63 = 64;
          }
          else
          {
            v60 = 0;
            v63 = 0;
            v61 = 9;
            v62 = 32;
          }
        }
        else
        {
          v60 = 2;
          v61 = 0;
          v62 = 96;
          v63 = 32;
        }
        v64 = dword_10AF94;
        *v83 &= (v82[v60] & 0x20000) != 0;
        sub_11F74C(1, v64, v58, i);
        sub_1053C0(v82[v60], v92);
        if ( v63 < v62 )
        {
          v65 = v93;
          v66 = v92[10];
          v67 = v84 - 4 + 4 * v62;
          v25 = (unsigned int *)(v84 + 4 * (v63 + 0x3FFFFFFF));
          v68 = v93 - 1;
          v69 = 0;
          v70 = (unsigned int *)v67;
          do
          {
            v72 = v25[1];
            ++v25;
            v71 = v72;
            v73 = (v72 >> 8) & 0xF;
            if ( v61 <= v73 )
            {
              if ( v65 == 1 )
              {
                v69 = v66 == v73;
              }
              else if ( v68 > 0 )
              {
                v69 = 0;
                v74 = v92;
                v75 = 1;
                if ( v73 < v66 )
                {
LABEL_46:
                  v75 = v69 + 1;
                  if ( v81 != 1 )
                    v69 = 1;
                  goto LABEL_48;
                }
                while ( 1 )
                {
                  if ( v74[11] > v73 )
                    v69 = v75;
                  else
                    v69 += 2;
LABEL_48:
                  v76 = v75;
                  v77 = v68 <= v75;
                  v78 = v75 + 10;
                  if ( v77 )
                    break;
                  v69 = v76;
                  v77 = v73 < v92[v78];
                  v74 = &v92[v76];
                  v75 = v69 + 1;
                  if ( v77 )
                    goto LABEL_46;
                }
              }
              *v25 = v71 & 0xE7FFFFFF | (v69 << 27);
            }
          }
          while ( v70 != v25 );
        }
      }
      a3 = v88;
    }
    a3 += 8;
  }
  while ( v80 != a3 );
  v31 = dword_10AF6C;
  v32 = dword_10AF70;
  v33 = dword_10AF74;
  v34 = dword_10AF98;
  sub_11F504(dword_10AF68, v25);
  sub_102ADC(0);
  v35 = dword_10AF78;
  v36 = (int *)v95;
  v37 = 0;
  while ( 2 )
  {
    if ( v37 )
    {
      if ( v37 != 1 )
      {
        v38 = v35;
        goto LABEL_18;
      }
      v38 = v33;
      v48 = v34;
    }
    else
    {
      v38 = v31;
      v48 = v32;
    }
    v49 = (unsigned int *)(v48 + 4);
    v50 = (int *)&v94[64 * v37];
    v51 = (unsigned int *)(v48 + 484);
    do
    {
      v52 = *v50++;
      *v49 = *v49 & 0xFFF1FFFF | (v52 << 17);
      v49 += 8;
    }
    while ( v51 != v49 );
LABEL_18:
    v39 = (unsigned int *)(v38 + 4);
    v40 = (unsigned int *)(v38 + 484);
    v41 = v36;
    do
    {
      v42 = *v41++;
      *v39 = *v39 & 0xFFF1FFFF | (v42 << 17);
      v39 += 8;
    }
    while ( v40 != v39 );
    ++v37;
    v36 += 16;
    if ( v37 != 3 )
      continue;
    break;
  }
  sub_102B40(0);
  v43 = off_10AF7C;
  v44 = dword_10AF80;
  v45 = *(_DWORD *)off_10AF50 & 0xFFFFFFFE | v85;
  *(_DWORD *)off_10AF50 = v45;
  sub_11F74C(1, v44, (*v43 >> 21) & 7, v45);
  return sub_11F504(dword_10AF84, v46);
}

