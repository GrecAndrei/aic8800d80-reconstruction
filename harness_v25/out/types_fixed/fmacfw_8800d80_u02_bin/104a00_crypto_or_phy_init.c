// crypto_or_phy_init @ 0x104a00, size 978 bytes
// Doc: crypto_or_phy_init [util]: Large init routine with VFP usage (crypto/phy setup)
// crypto_or_phy_init [util]: Large init routine with VFP usage (crypto/phy setup)
int __fastcall crypto_or_phy_init(int a1, int a2, _DWORD *a3, _DWORD *a4, int a5, int a6)
{
  int *v7; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int inited; // r6
  int v19; // r5
  int v20; // r3
  _DWORD *v21; // r3
  float v22; // s23
  float v23; // s20
  float v24; // s19
  float v25; // s18
  float v26; // s21
  float v27; // s22
  int v28; // r8
  int v29; // r9
  int v30; // r3
  float v31; // s14
  int v32; // r7
  int v33; // r0
  float v34; // s17
  int i; // r5
  float v36; // s16
  float v37; // s15
  float v38; // s17
  float v39; // s17
  float v40; // s18
  float v41; // s17
  float v42; // s16
  float *v43; // r4
  int j; // r5
  float v45; // s15
  int v46; // r0
  _DWORD *v47; // r2
  float v48; // s15
  int v49; // r4
  int v50; // r5
  int result; // r0
  int v52; // r0
  int v53; // [sp+8h] [bp-14Ch]
  int v54; // [sp+Ch] [bp-148h]
  int v55; // [sp+10h] [bp-144h]
  int v56; // [sp+18h] [bp-13Ch]
  int v57; // [sp+1Ch] [bp-138h]
  int v58; // [sp+24h] [bp-130h]
  _DWORD *(_DWORD *)(v60 + 0x20); // [sp+30h] [bp-124h]
  _DWORD *(_DWORD *)(v61 + 0x80); // [sp+50h] [bp-104h] BYREF
  _BYTE *(_DWORD *)(v62 + 0x210); // [sp+D0h] [bp-84h] BYREF

  v7 = (int *)dword_104D2C;
  feature_guard_check(1, dword_104D28);
  sub_143770(v61, dword_104D30, 128);
  v11 = *v7;
  v12 = *(_DWORD *)(v7 + 0x4);
  v13 = *(_DWORD *)(v7 + 0x8);
  v14 = *(_DWORD *)(v7 + 0xc);
  v7 += 4;
  *(_DWORD *)(v60 + 0x0) = v11;
  *(_DWORD *)(v60 + 0x4) = v12;
  *(_DWORD *)(v60 + 0x8) = v13;
  *(_DWORD *)(v60 + 0xc) = v14;
  v15 = *(_DWORD *)(v7 + 0x4);
  v16 = *(_DWORD *)(v7 + 0x8);
  v17 = *(_DWORD *)(v7 + 0xc);
  *(_DWORD *)(v60 + 0x10) = *v7;
  *(_DWORD *)(v60 + 0x14) = v15;
  *(_DWORD *)(v60 + 0x18) = v16;
  *(_DWORD *)(v60 + 0x1c) = v17;
  sub_143770(v62, v7 + 4, 128);
  inited = scan_chan_set_init_n_28(0, 0, a3);
  v55 = a1 + 128;
  v56 = a1 + 384;
  if ( a2 == 1 )
  {
    v52 = scan_chan_set_init_n_28(0, 1, a4);
    if ( inited < v52 )
      inited += 1280;
    v19 = v52;
  }
  else
  {
    v19 = 0;
  }
  v20 = ((int)((unsigned __int64)(dword_104D34 * (__int64)(0x2000 - inited)) >> 32) >> 9) - ((0x2000 - inited) >> 31);
  if ( a6 )
  {
    if ( v20 >= 5 )
      v20 = 5;
    v57 = v20;
  }
  else
  {
    if ( v20 >= 10 )
      v20 = 10;
    v57 = v20;
  }
  feature_guard_check(1, dword_104D38);
  v21 = (_DWORD *)(a1 + 128);
  do
  {
    *v21++ = 0;
    *(_DWORD *)(v21 + 0xfc) = 0;
  }
  while ( v21 != (_DWORD *)(a1 + 256) );
  if ( v57 > 0 )
  {
    v22 = flt_104D3C;
    v23 = flt_104D40;
    v24 = flt_104D44;
    v25 = flt_104D48;
    v54 = inited;
    v26 = flt_104D3C;
    v58 = v19 - inited;
    do
    {
      v27 = flt_104D4C;
      v28 = 0;
      v29 = 2;
      while ( 1 )
      {
        if ( a6 == 1 && !*((_BYTE *)v60 + v29) )
          goto LABEL_13;
        v31 = flt_104D3C;
        v53 = *(_DWORD *)&v62[4 * v29];
        v32 = v53 + v54;
        do
        {
          v33 = sub_1045E8(v32++, 0, a3);
          v31 = v31 + (float)v33;
        }
        while ( v32 != v53 + v54 + 12 );
        *(float *)(v55 + 4 * v29) = *(float *)(v55 + 4 * v29) + v31;
        if ( v29 <= 1 )
        {
LABEL_13:
          v30 = v28 + 1;
          if ( v28 == 31 )
            break;
          goto LABEL_14;
        }
        v34 = flt_104D3C;
        for ( i = 1; ; ++i )
        {
          v36 = COERCE_FLOAT(sub_104618(v53 + v54 - 1 + i, 0, a3));
          v37 = v36 - COERCE_FLOAT(sub_104618(v53 + v58 + v54 - 1 + i, 1, a4));
          if ( v37 < v23 )
            v37 = v37 + v24;
          if ( v37 > v25 )
            v37 = v37 - v24;
          if ( i == 1 )
          {
            v34 = v34 + v37;
            v26 = v37;
            continue;
          }
          if ( (float)(v37 - v26) <= v25 )
            break;
          v34 = v34 + (float)(v37 - v24);
          if ( i == 12 )
            goto LABEL_35;
LABEL_25:
          ;
        }
        if ( (float)(v37 - v26) < v23 )
          v37 = v37 + v24;
        v34 = v34 + v37;
        if ( i != 12 )
          goto LABEL_25;
LABEL_35:
        v38 = v34 * v27;
        if ( v38 <= 1.0 )
        {
          if ( v38 < -1.0 )
            v38 = v38 + 2.0;
          if ( v29 == 2 )
            goto LABEL_49;
LABEL_37:
          v39 = v38 - v22;
          if ( v39 <= 1.0 )
          {
            if ( v39 < -1.0 )
              v39 = v39 + 2.0;
          }
          else
          {
            v39 = v39 - 2.0;
          }
        }
        else
        {
          v38 = v38 - 2.0;
          if ( v29 != 2 )
            goto LABEL_37;
LABEL_49:
          v22 = v38;
          v39 = flt_104D3C;
        }
        *(float *)(4 * v29 + v56) = *(float *)(4 * v29 + v56) + v39;
        v30 = v28 + 1;
        if ( v28 == 31 )
          break;
LABEL_14:
        if ( v30 <= 2 )
          v29 = v28;
        else
          v29 = v30;
        v28 = v30;
      }
      v54 += 1280;
    }
    while ( v54 != inited + 1280 * v57 );
  }
  v40 = flt_104D50;
  v41 = flt_104D54;
  v42 = (float)v57;
  v43 = (float *)a1;
  for ( j = 1; ; ++j )
  {
    v46 = sub_12D70C((float)(*(_DWORD *)(v43 + 0x80) / v42) / 12.0);
    v47 = &v61[j];
    *((_DWORD *)v43 + 32) = v46;
    if ( (unsigned int)(j - 1) > 1 )
      break;
    v48 = (float)(int)*(v47 - 1) * v40;
    *(_DWORD *)(v43 + 0x180) = (float)(*(float *)(a1 + 392) / v42) * v41;
    *v43 = v48;
LABEL_43:
    ++v43;
  }
  v45 = (float)(int)*(v47 - 1) * v40;
  *(_DWORD *)(v43 + 0x180) = (float)(*(_DWORD *)(v43 + 0x180) / v42) * v41;
  *v43 = v45;
  if ( j != 32 )
    goto LABEL_43;
  v49 = dword_104DDC;
  feature_guard_check(1, dword_104DD4);
  v50 = a1;
  do
  {
    v50 += 4;
    result = feature_guard_check(1, v49);
  }
  while ( v55 != v50 );
  return result;
}

