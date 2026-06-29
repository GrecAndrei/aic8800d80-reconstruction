// sub_10B010 @ 0x10b010, size 1046 bytes
// Doc: crypto_mac_dispatch [mac]: Dispatch crypto/MAC operation request
// crypto_mac_dispatch [mac]: Dispatch crypto/MAC operation request
int  sub_10B010(unsigned int *a1, uint8_t *a2, int a3)
{
  int v3; // r9
  int v4; // r10
  int v5; // r11
  int v6; // r8
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
  uint32_t *v18; // r4
  int v19; // r0
  int v20; // r1
  int v21; // r2
  unsigned int *v22; // r1
  unsigned int v23; // r2
  uint32_t *v24; // r9
  int v25; // r10
  unsigned int v26; // r4
  int v27; // r5
  int v28; // r4
  int v29; // r7
  int v30; // r9
  int v31; // r0
  int *v32; // r10
  int v33; // r1
  int v34; // r12
  unsigned int *v35; // r2
  unsigned int *v36; // r8
  int *v37; // r12
  int v38; // t1
  int v39; // r1
  int v40; // r1
  int v41; // r2
  int v43; // r8
  unsigned int *v44; // r2
  int *v45; // lr
  unsigned int *v46; // r8
  int v47; // t1
  int v48; // r6
  unsigned int *v49; // r1
  int *v50; // r5
  unsigned int *v51; // r6
  unsigned int v52; // r3
  int i; // r8
  int v54; // r10
  int v55; // r7
  int v56; // r5
  int v57; // r6
  int v58; // r1
  int v59; // lr
  int v60; // r10
  int v61; // r3
  int v62; // r12
  int v63; // r5
  unsigned int *v64; // r11
  unsigned int v65; // t1
  int v66; // r6
  uint32_t *v67; // r0
  int v68; // r3
  int v69; // r0
  bool v70; // cc
  int v71; // r3
  int v72; // r0
  int v73; // [sp+10h] [bp-1BCh]
  int v74; // [sp+14h] [bp-1B8h]
  unsigned int *v75; // [sp+18h] [bp-1B4h]
  uint8_t *v76; // [sp+1Ch] [bp-1B0h]
  int v77; // [sp+20h] [bp-1ACh]
  int v78; // [sp+24h] [bp-1A8h]
  int v81; // [sp+34h] [bp-198h]
  int v82; // [sp+38h] [bp-194h] BYREF
  int v83; // [sp+3Ch] [bp-190h]
  __int16 v84; // [sp+40h] [bp-18Ch]
  uint32_t v85[14]; // [sp+44h] [bp-188h] BYREF
  int v86; // [sp+7Ch] [bp-150h]
  uint8_t v87[128]; // [sp+88h] [bp-144h] BYREF
  uint8_t v88[196]; // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10B354;
  v4 = dword_10B35C;
  v5 = dword_10B380;
  v6 = a3;
  msg_parse(dword_10B338, a2, a3);
  v7 = *(uint32_t *)off_10B33C;
  v8 = *(uint32_t *)off_10B33C & 0xFFFFFFFE;
  v82 = 0;
  v83 = 0;
  v84 = 0;
  *(uint32_t *)off_10B33C = v8;
  v78 = v7 & 1;
  crypto_hw_enable_2ca8(0);
  v9 = dword_10B358;
  v10 = dword_10B360;
  v11 = 0;
  v12 = (int *)v88;
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
      v48 = v5;
    }
    else
    {
      v13 = v3;
      v48 = v9;
    }
    v49 = (unsigned int *)(v48 + 4);
    v50 = (int *)&v87[64 * v11];
    v51 = (unsigned int *)(v48 + 516);
    do
    {
      v52 = *v49;
      *v49 &= 0xFFF1FFFF;
      v49 += 8;
      *v50++ = (v52 >> 17) & 7;
    }
    while ( v49 != v51 );
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
  msg_parse(v19, v20, v21);
  feature_guard_check(1, dword_10B34C);
  v24 = v18;
  v73 = v6 + 56;
  do
  {
    v25 = *(unsigned __int8 *)(v6 + 5);
    v26 = *(unsigned __int16 *)(v6 + 2);
    *v24 |= 0x400u;
    *v24 &= ~0x400u;
    if ( v25 == 1 )
    {
      feature_guard_check(1, dword_10B370);
      if ( v26 > 0x1388 )
      {
        LOBYTE(v84) = 0;
        LOBYTE(v82) = 1;
        HIWORD(v82) = v26;
        LOWORD(v83) = v26;
        HIWORD(v83) = v26;
        sub_102A20((unsigned __int16 *)&v82, 0);
        v72 = sub_102B0C(v26);
        v77 = dword_10B428 + 384 * v72;
        v75 = &a1[316 * (unsigned __int8)(v72 + 1)];
        v76 = &a2[(unsigned __int8)(v72 + 1)];
      }
      else
      {
        LOWORD(v83) = v26;
        LOBYTE(v82) = 0;
        LOBYTE(v84) = 0;
        sub_102A20((unsigned __int16 *)&v82, 0);
        v77 = dword_10B374;
        v76 = a2;
        v75 = a1;
        v25 = 0;
      }
      crypto_mac_core_8280((int)(v75 + 292), v75, 255, 0, 0, dword_10B378, 0);
      delay_us_0644(10000);
      v81 = v6;
      *v76 = 1;
      v74 = v25;
      for ( i = 0; i != 3; ++i )
      {
        if ( !v75[i] )
          feature_guard_check(1, dword_10B42C);
        if ( v74 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v54 = 1;
            else
              v54 = 2;
            if ( i == 1 )
              v55 = 8;
            else
              v55 = 9;
            if ( i == 1 )
              v56 = 64;
            else
              v56 = 96;
            if ( i == 1 )
              v57 = 32;
            else
              v57 = 64;
          }
          else
          {
            v54 = 0;
            v57 = 0;
            v55 = 9;
            v56 = 32;
          }
        }
        else
        {
          v54 = 2;
          v55 = 0;
          v56 = 96;
          v57 = 32;
        }
        v58 = dword_10B37C;
        *v76 &= (v75[v54] & 0x20000) != 0;
        feature_guard_check(1, v58);
        sub_1059E8(v75[v54], v85);
        if ( v57 < v56 )
        {
          v59 = v86;
          v60 = v85[10];
          v61 = v77 - 4 + 4 * v56;
          v22 = (unsigned int *)(v77 + 4 * (v57 + 0x3FFFFFFF));
          v62 = v86 - 1;
          v63 = 0;
          v64 = (unsigned int *)v61;
          do
          {
            v65 = v22[1];
            ++v22;
            v23 = v65;
            v66 = (v65 >> 8) & 0xF;
            if ( v55 <= v66 )
            {
              if ( v59 == 1 )
              {
                v63 = v60 == v66;
              }
              else if ( v62 > 0 )
              {
                v63 = 0;
                v67 = v85;
                v68 = 1;
                if ( v66 < v60 )
                {
LABEL_43:
                  v68 = v63 + 1;
                  if ( v74 != 1 )
                    v63 = 1;
                  goto LABEL_45;
                }
                while ( 1 )
                {
                  if ( v67[11] > v66 )
                    v63 = v68;
                  else
                    v63 += 2;
LABEL_45:
                  v69 = v68;
                  v70 = v62 <= v68;
                  v71 = v68 + 10;
                  if ( v70 )
                    break;
                  v63 = v69;
                  v70 = v66 < v85[v71];
                  v67 = &v85[v69];
                  v68 = v63 + 1;
                  if ( v70 )
                    goto LABEL_43;
                }
              }
              v23 = v23 & 0xE7FFFFFF | (v63 << 27);
              *v22 = v23;
            }
          }
          while ( v64 != v22 );
        }
      }
      v6 = v81;
    }
    v6 += 8;
  }
  while ( v73 != v6 );
  v27 = dword_10B354;
  v28 = dword_10B358;
  v29 = dword_10B35C;
  v30 = dword_10B380;
  msg_parse(dword_10B350, v22, v23);
  crypto_hw_enable_2ca8(0);
  v31 = dword_10B360;
  v32 = (int *)v88;
  v33 = 0;
  while ( 2 )
  {
    if ( v33 )
    {
      if ( v33 != 1 )
      {
        v34 = v31;
        goto LABEL_15;
      }
      v34 = v29;
      v43 = v30;
    }
    else
    {
      v34 = v27;
      v43 = v28;
    }
    v44 = (unsigned int *)(v43 + 4);
    v45 = (int *)&v87[64 * v33];
    v46 = (unsigned int *)(v43 + 484);
    do
    {
      v47 = *v45++;
      *v44 = *v44 & 0xFFF1FFFF | (v47 << 17);
      v44 += 8;
    }
    while ( v46 != v44 );
LABEL_15:
    v35 = (unsigned int *)(v34 + 4);
    v36 = (unsigned int *)(v34 + 484);
    v37 = v32;
    do
    {
      v38 = *v37++;
      *v35 = *v35 & 0xFFF1FFFF | (v38 << 17);
      v35 += 8;
    }
    while ( v36 != v35 );
    ++v33;
    v32 += 16;
    if ( v33 != 3 )
      continue;
    break;
  }
  sub_102D0C(0);
  v39 = dword_10B368;
  *(uint32_t *)off_10B33C = *(uint32_t *)off_10B33C & 0xFFFFFFFE | v78;
  feature_guard_check(1, v39);
  return msg_parse(dword_10B36C, v40, v41);
}

