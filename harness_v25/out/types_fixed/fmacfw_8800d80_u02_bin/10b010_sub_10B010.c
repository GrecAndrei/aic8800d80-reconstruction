// sub_10B010 @ 0x10b010, size 1046 bytes
int __fastcall sub_10B010(unsigned int *a1, _BYTE *a2, int a3)
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
  _DWORD *v18; // r4
  int v19; // r0
  _DWORD *v20; // r9
  int v21; // r10
  unsigned int v22; // r4
  int v23; // r5
  int v24; // r4
  int v25; // r7
  int v26; // r9
  int v27; // r0
  int *v28; // r10
  int v29; // r1
  int v30; // r12
  unsigned int *v31; // r2
  unsigned int *v32; // r8
  int *v33; // r12
  int v34; // t1
  _DWORD *v35; // r0
  int v36; // r1
  int v38; // r8
  unsigned int *v39; // r2
  int *v40; // lr
  unsigned int *v41; // r8
  int v42; // t1
  int v43; // r6
  unsigned int *v44; // r1
  int *v45; // r5
  unsigned int *v46; // r6
  unsigned int v47; // r3
  int v48; // s16
  int i; // r8
  int v50; // r10
  int v51; // r7
  int v52; // r5
  int v53; // r6
  int v54; // r1
  int v55; // lr
  int v56; // r10
  int v57; // r3
  unsigned int *v58; // r1
  int v59; // r12
  int v60; // r5
  unsigned int *v61; // r11
  unsigned int v62; // r2
  unsigned int v63; // t1
  int v64; // r6
  _DWORD *v65; // r0
  int v66; // r3
  int v67; // r0
  bool v68; // cc
  int v69; // r3
  int v70; // r0
  int v71; // [sp+0h] [bp-1CCh]
  int v72; // [sp+10h] [bp-1BCh]
  int v73; // [sp+14h] [bp-1B8h]
  unsigned int *v74; // [sp+18h] [bp-1B4h]
  _BYTE *v75; // [sp+1Ch] [bp-1B0h]
  int v76; // [sp+20h] [bp-1ACh]
  int v77; // [sp+24h] [bp-1A8h]
  int v80; // [sp+34h] [bp-198h]
  int v81; // [sp+38h] [bp-194h] BYREF
  int v82; // [sp+3Ch] [bp-190h]
  __int16 v83; // [sp+40h] [bp-18Ch]
  _DWORD *(_DWORD *)(v84 + 0x38); // [sp+44h] [bp-188h] BYREF
  int v85; // [sp+7Ch] [bp-150h]
  _BYTE *(_DWORD *)(v86 + 0x200); // [sp+88h] [bp-144h] BYREF
  _BYTE *(_DWORD *)(v87 + 0x310); // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10B354;
  v4 = dword_10B35C;
  v5 = dword_10B380;
  msg_parse(dword_10B338);
  v7 = *(_DWORD *)off_10B33C;
  v8 = *(_DWORD *)off_10B33C & 0xFFFFFFFE;
  v81 = 0;
  v82 = 0;
  v83 = 0;
  *(_DWORD *)off_10B33C = v8;
  v77 = v7 & 1;
  crypto_hw_enable_2ca8(0);
  v9 = dword_10B358;
  v10 = dword_10B360;
  v11 = 0;
  v12 = (int *)v87;
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
      v43 = v5;
    }
    else
    {
      v13 = v3;
      v43 = v9;
    }
    v44 = (unsigned int *)(v43 + 4);
    v45 = (int *)&v86[64 * v11];
    v46 = (unsigned int *)(v43 + 516);
    do
    {
      v47 = *v44;
      *v44 &= 0xFFF1FFFF;
      v44 += 8;
      *v45++ = (v47 >> 17) & 7;
    }
    while ( v44 != v46 );
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
  v18 = off_10B340;
  sub_102D0C(0);
  feature_guard_check(1, dword_10B344);
  v19 = dword_10B348;
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  msg_parse(v19);
  feature_guard_check(1, dword_10B34C);
  v20 = v18;
  v72 = a3 + 56;
  do
  {
    v21 = *(unsigned __int8 *)(a3 + 5);
    v22 = *(unsigned __int16 *)(a3 + 2);
    *v20 |= 0x400u;
    *v20 &= ~0x400u;
    if ( v21 == 1 )
    {
      feature_guard_check(1, dword_10B370, v22);
      if ( v22 > 0x1388 )
      {
        LOBYTE(v83) = 0;
        LOBYTE(v81) = 1;
        HIWORD(v81) = v22;
        LOWORD(v82) = v22;
        HIWORD(v82) = v22;
        sub_102A20((unsigned __int16 *)&v81, 0);
        v70 = sub_102B0C(v22);
        v76 = dword_10B428 + 384 * v70;
        v74 = &a1[316 * (unsigned __int8)(v70 + 1)];
        v48 = (unsigned __int8)(v70 + 1);
        v75 = &a2[v48];
      }
      else
      {
        LOWORD(v82) = v22;
        LOBYTE(v81) = 0;
        LOBYTE(v83) = 0;
        sub_102A20((unsigned __int16 *)&v81, 0);
        v76 = dword_10B374;
        v75 = a2;
        v48 = 0;
        v74 = a1;
        v21 = 0;
      }
      crypto_mac_core_8280((int)(v74 + 292), v74, 255, 0, 0, dword_10B378, 0);
      delay_us_0644(10000);
      v80 = a3;
      *v75 = 1;
      v73 = v21;
      for ( i = 0; i != 3; ++i )
      {
        if ( !v74[i] )
          feature_guard_check(1, dword_10B42C, i);
        if ( v73 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v50 = 1;
            else
              v50 = 2;
            if ( i == 1 )
              v51 = 8;
            else
              v51 = 9;
            if ( i == 1 )
              v52 = 64;
            else
              v52 = 96;
            if ( i == 1 )
              v53 = 32;
            else
              v53 = 64;
          }
          else
          {
            v50 = 0;
            v53 = 0;
            v51 = 9;
            v52 = 32;
          }
        }
        else
        {
          v50 = 2;
          v51 = 0;
          v52 = 96;
          v53 = 32;
        }
        v54 = dword_10B37C;
        v71 = (v74[v50] >> 17) & 1;
        *v75 &= (v74[v50] & 0x20000) != 0;
        feature_guard_check(1, v54, v48, i, v71);
        sub_1059E8(v74[v50], v84);
        if ( v53 < v52 )
        {
          v55 = v85;
          v56 = *(_DWORD *)(v84 + 0x28);
          v57 = v76 - 4 + 4 * v52;
          v58 = (unsigned int *)(v76 + 4 * (v53 + 0x3FFFFFFF));
          v59 = v85 - 1;
          v60 = 0;
          v61 = (unsigned int *)v57;
          do
          {
            v63 = *(_DWORD *)(v58 + 0x4);
            ++v58;
            v62 = v63;
            v64 = (v63 >> 8) & 0xF;
            if ( v51 <= v64 )
            {
              if ( v55 == 1 )
              {
                v60 = v56 == v64;
              }
              else if ( v59 > 0 )
              {
                v60 = 0;
                v65 = v84;
                v66 = 1;
                if ( v64 < v56 )
                {
LABEL_43:
                  v66 = v60 + 1;
                  if ( v73 != 1 )
                    v60 = 1;
                  goto LABEL_45;
                }
                while ( 1 )
                {
                  if ( *(_DWORD *)(v65 + 0x2c) > v64 )
                    v60 = v66;
                  else
                    v60 += 2;
LABEL_45:
                  v67 = v66;
                  v68 = v59 <= v66;
                  v69 = v66 + 10;
                  if ( v68 )
                    break;
                  v60 = v67;
                  v68 = v64 < v84[v69];
                  v65 = &v84[v67];
                  v66 = v60 + 1;
                  if ( v68 )
                    goto LABEL_43;
                }
              }
              *v58 = v62 & 0xE7FFFFFF | (v60 << 27);
            }
          }
          while ( v61 != v58 );
        }
      }
      a3 = v80;
    }
    a3 += 8;
  }
  while ( v72 != a3 );
  v23 = dword_10B354;
  v24 = dword_10B358;
  v25 = dword_10B35C;
  v26 = dword_10B380;
  msg_parse(dword_10B350);
  crypto_hw_enable_2ca8(0);
  v27 = dword_10B360;
  v28 = (int *)v87;
  v29 = 0;
  while ( 2 )
  {
    if ( v29 )
    {
      if ( v29 != 1 )
      {
        v30 = v27;
        goto LABEL_15;
      }
      v30 = v25;
      v38 = v26;
    }
    else
    {
      v30 = v23;
      v38 = v24;
    }
    v39 = (unsigned int *)(v38 + 4);
    v40 = (int *)&v86[64 * v29];
    v41 = (unsigned int *)(v38 + 484);
    do
    {
      v42 = *v40++;
      *v39 = *v39 & 0xFFF1FFFF | (v42 << 17);
      v39 += 8;
    }
    while ( v41 != v39 );
LABEL_15:
    v31 = (unsigned int *)(v30 + 4);
    v32 = (unsigned int *)(v30 + 484);
    v33 = v28;
    do
    {
      v34 = *v33++;
      *v31 = *v31 & 0xFFF1FFFF | (v34 << 17);
      v31 += 8;
    }
    while ( v32 != v31 );
    ++v29;
    v28 += 16;
    if ( v29 != 3 )
      continue;
    break;
  }
  sub_102D0C(0);
  v35 = off_10B364;
  v36 = dword_10B368;
  *(_DWORD *)off_10B33C = *(_DWORD *)off_10B33C & 0xFFFFFFFE | v77;
  feature_guard_check(1, v36, (*v35 >> 21) & 7);
  return msg_parse(dword_10B36C);
}
