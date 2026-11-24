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
  int v22; // r2
  int v23; // r3
  int v24; // r3
  unsigned int *v25; // r9
  int v26; // r10
  unsigned int v27; // r4
  unsigned int v28; // r3
  int v29; // r5
  int v30; // r4
  int v31; // r7
  int v32; // r9
  int v33; // r0
  int *v34; // r10
  int v35; // r1
  int v36; // r12
  unsigned int *v37; // r2
  unsigned int *v38; // r8
  int *v39; // r12
  int v40; // t1
  _DWORD *v41; // r0
  int v42; // r1
  unsigned int v43; // r3
  int v45; // r8
  unsigned int *v46; // r2
  int *v47; // lr
  unsigned int *v48; // r8
  int v49; // t1
  int v50; // r6
  unsigned int *v51; // r1
  int *v52; // r5
  unsigned int *v53; // r6
  unsigned int v54; // r3
  int v55; // s16
  int i; // r8
  int v57; // r10
  int v58; // r7
  int v59; // r5
  int v60; // r6
  int v61; // r1
  int v62; // lr
  int v63; // r10
  int v64; // r3
  unsigned int *v65; // r1
  int v66; // r12
  int v67; // r5
  unsigned int *v68; // r11
  unsigned int v69; // r2
  unsigned int v70; // t1
  int v71; // r6
  _DWORD *v72; // r0
  int v73; // r3
  int v74; // r0
  bool v75; // cc
  int v76; // r3
  int v77; // r0
  int v78; // [sp+10h] [bp-1BCh]
  int v79; // [sp+14h] [bp-1B8h]
  unsigned int *v80; // [sp+18h] [bp-1B4h]
  _BYTE *v81; // [sp+1Ch] [bp-1B0h]
  int v82; // [sp+20h] [bp-1ACh]
  int v83; // [sp+24h] [bp-1A8h]
  int v86; // [sp+34h] [bp-198h]
  int v87; // [sp+38h] [bp-194h] BYREF
  int v88; // [sp+3Ch] [bp-190h]
  __int16 v89; // [sp+40h] [bp-18Ch]
  _DWORD *(_DWORD *)(v90 + 0x38); // [sp+44h] [bp-188h] BYREF
  int v91; // [sp+7Ch] [bp-150h]
  _BYTE *(_DWORD *)(v92 + 0x200); // [sp+88h] [bp-144h] BYREF
  _BYTE *(_DWORD *)(v93 + 0x310); // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10AF6C;
  v4 = dword_10AF74;
  v5 = dword_10AF98;
  msg_parse(dword_10AF4C);
  v7 = *(_DWORD *)off_10AF50;
  v8 = *(_DWORD *)off_10AF50 & 0xFFFFFFFE;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  *(_DWORD *)off_10AF50 = v8;
  v83 = v7 & 1;
  sub_102ADC(0);
  v9 = dword_10AF70;
  v10 = dword_10AF78;
  v11 = 0;
  v12 = (int *)v93;
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
      v50 = v5;
    }
    else
    {
      v13 = v3;
      v50 = v9;
    }
    v51 = (unsigned int *)(v50 + 4);
    v52 = (int *)&v92[64 * v11];
    v53 = (unsigned int *)(v50 + 516);
    do
    {
      v54 = *v51;
      *v51 &= 0xFFF1FFFF;
      v51 += 8;
      *v52++ = (v54 >> 17) & 7;
    }
    while ( v51 != v53 );
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
  msg_parse(v21);
  sub_11F74C(1, dword_10AF60, v22, v23);
  if ( (*(_DWORD *)off_10AF64 & 2) != 0 )
    v24 = 8;
  else
    v24 = 56;
  v25 = v18;
  v78 = v24 + a3;
  do
  {
    v26 = *(unsigned __int8 *)(a3 + 5);
    v27 = *(unsigned __int16 *)(a3 + 2);
    *v25 |= 0x400u;
    v28 = *v25 & 0xFFFFFBFF;
    *v25 = v28;
    if ( v26 == 1 )
    {
      sub_11F74C(1, dword_10AF88, v27, v28);
      if ( v27 > 0x1388 )
      {
        LOBYTE(v89) = 0;
        LOBYTE(v87) = 1;
        HIWORD(v87) = v27;
        LOWORD(v88) = v27;
        HIWORD(v88) = v27;
        sub_102908((unsigned __int8 *)&v87, 0);
        v77 = sub_102968(v27);
        v82 = dword_10B040 + 384 * v77;
        v80 = &a1[316 * (unsigned __int8)(v77 + 1)];
        v55 = (unsigned __int8)(v77 + 1);
        v81 = &a2[v55];
      }
      else
      {
        LOWORD(v88) = v27;
        LOBYTE(v87) = 0;
        LOBYTE(v89) = 0;
        sub_102908((unsigned __int8 *)&v87, 0);
        v82 = dword_10AF8C;
        v81 = a2;
        v55 = 0;
        v80 = a1;
        v26 = 0;
      }
      sub_107C70((int)(v80 + 292), v80, 255, 0, 0, dword_10AF90, 0);
      delay_us(10000);
      v86 = a3;
      *v81 = 1;
      v79 = v26;
      for ( i = 0; i != 3; ++i )
      {
        if ( !v80[i] )
          sub_11F74C(1, dword_10B044, i, 0);
        if ( v79 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v57 = 1;
            else
              v57 = 2;
            if ( i == 1 )
              v58 = 8;
            else
              v58 = 9;
            if ( i == 1 )
              v59 = 64;
            else
              v59 = 96;
            if ( i == 1 )
              v60 = 32;
            else
              v60 = 64;
          }
          else
          {
            v57 = 0;
            v60 = 0;
            v58 = 9;
            v59 = 32;
          }
        }
        else
        {
          v57 = 2;
          v58 = 0;
          v59 = 96;
          v60 = 32;
        }
        v61 = dword_10AF94;
        *v81 &= (v80[v57] & 0x20000) != 0;
        sub_11F74C(1, v61, v55, i);
        crypto_key_schedule(v80[v57], v90);
        if ( v60 < v59 )
        {
          v62 = v91;
          v63 = *(_DWORD *)(v90 + 0x28);
          v64 = v82 - 4 + 4 * v59;
          v65 = (unsigned int *)(v82 + 4 * (v60 + 0x3FFFFFFF));
          v66 = v91 - 1;
          v67 = 0;
          v68 = (unsigned int *)v64;
          do
          {
            v70 = *(_DWORD *)(v65 + 0x4);
            ++v65;
            v69 = v70;
            v71 = (v70 >> 8) & 0xF;
            if ( v58 <= v71 )
            {
              if ( v62 == 1 )
              {
                v67 = v63 == v71;
              }
              else if ( v66 > 0 )
              {
                v67 = 0;
                v72 = v90;
                v73 = 1;
                if ( v71 < v63 )
                {
LABEL_46:
                  v73 = v67 + 1;
                  if ( v79 != 1 )
                    v67 = 1;
                  goto LABEL_48;
                }
                while ( 1 )
                {
                  if ( *(_DWORD *)(v72 + 0x2c) > v71 )
                    v67 = v73;
                  else
                    v67 += 2;
LABEL_48:
                  v74 = v73;
                  v75 = v66 <= v73;
                  v76 = v73 + 10;
                  if ( v75 )
                    break;
                  v67 = v74;
                  v75 = v71 < v90[v76];
                  v72 = &v90[v74];
                  v73 = v67 + 1;
                  if ( v75 )
                    goto LABEL_46;
                }
              }
              *v65 = v69 & 0xE7FFFFFF | (v67 << 27);
            }
          }
          while ( v68 != v65 );
        }
      }
      a3 = v86;
    }
    a3 += 8;
  }
  while ( v78 != a3 );
  v29 = dword_10AF6C;
  v30 = dword_10AF70;
  v31 = dword_10AF74;
  v32 = dword_10AF98;
  msg_parse(dword_10AF68);
  sub_102ADC(0);
  v33 = dword_10AF78;
  v34 = (int *)v93;
  v35 = 0;
  while ( 2 )
  {
    if ( v35 )
    {
      if ( v35 != 1 )
      {
        v36 = v33;
        goto LABEL_18;
      }
      v36 = v31;
      v45 = v32;
    }
    else
    {
      v36 = v29;
      v45 = v30;
    }
    v46 = (unsigned int *)(v45 + 4);
    v47 = (int *)&v92[64 * v35];
    v48 = (unsigned int *)(v45 + 484);
    do
    {
      v49 = *v47++;
      *v46 = *v46 & 0xFFF1FFFF | (v49 << 17);
      v46 += 8;
    }
    while ( v48 != v46 );
LABEL_18:
    v37 = (unsigned int *)(v36 + 4);
    v38 = (unsigned int *)(v36 + 484);
    v39 = v34;
    do
    {
      v40 = *v39++;
      *v37 = *v37 & 0xFFF1FFFF | (v40 << 17);
      v37 += 8;
    }
    while ( v38 != v37 );
    ++v35;
    v34 += 16;
    if ( v35 != 3 )
      continue;
    break;
  }
  sub_102B40(0);
  v41 = off_10AF7C;
  v42 = dword_10AF80;
  v43 = *(_DWORD *)off_10AF50 & 0xFFFFFFFE | v83;
  *(_DWORD *)off_10AF50 = v43;
  sub_11F74C(1, v42, (*v41 >> 21) & 7, v43);
  return msg_parse(dword_10AF84);
}
