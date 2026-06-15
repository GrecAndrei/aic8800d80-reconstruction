// sub_11F680 @ 0x11f680, size 1000 bytes
int __fastcall sub_11F680(int *a1, int a2, int a3, _BYTE *a4)
{
  _BYTE *v4; // r9
  int **v5; // r4
  int result; // r0
  int v7; // r0
  int v8; // r6
  int v9; // r7
  int v10; // r8
  int v11; // r11
  int *v12; // r5
  int v13; // r10
  _DWORD *v14; // r3
  _DWORD *v15; // r1
  _DWORD *v16; // r2
  int v17; // r0
  int v18; // r2
  int v19; // r4
  char v20; // r3
  int v21; // r3
  int v22; // r2
  int v23; // r3
  int v24; // r3
  _DWORD *v25; // r5
  int v26; // r1
  int v27; // r2
  int v28; // r0
  int v29; // r5
  int v30; // r0
  int v31; // r3
  _DWORD *v32; // r3
  bool v33; // zf
  int v34; // r0
  int v35; // r1
  int v36; // r0
  __int16 **v37; // r3
  char v38; // r2
  int v39; // r5
  int v40; // r3
  int v41; // r6
  int *v42; // r5
  int v43; // r3
  int v44; // r2
  int v45; // r2
  int v46; // r2
  int v47; // r0
  int v52; // [sp+20h] [bp-1Ch]
  int v53; // [sp+24h] [bp-18h]
  unsigned __int8 v54; // [sp+2Bh] [bp-11h] BYREF
  _DWORD v55[4]; // [sp+2Ch] [bp-10h] BYREF

  v4 = off_11F9BC;
  if ( !*(_DWORD *)off_11F9BC )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(_BYTE *)off_11FA18 )
      return 1;
    v5 = *((int ***)off_11F9BC + 2);
    if ( v5 )
    {
      if ( *((_BYTE *)off_11F9BC + 19) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    sub_121648(a1);
    goto LABEL_11;
  }
  v5 = *((int ***)off_11F9BC + 2);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = dword_11F9A4;
  v8 = *a1;
  v52 = *a1;
  v9 = 0;
  v53 = *((unsigned __int16 *)a1 + 2);
  v10 = 0;
  v11 = v53;
  do
  {
    v12 = v5[25];
    v13 = *((unsigned __int16 *)v5 + 52);
    sub_12E948(v7, v12, v13);
    v5 = (int **)*v5;
    v7 = dword_11F9A4;
    v10 |= (unsigned int)v12 ^ v8;
    v8 &= (unsigned int)v12;
    v9 |= v13 ^ v11;
    v11 &= v13;
  }
  while ( v5 );
  v14 = off_11F9AC;
  v15 = off_11F9B0;
  v16 = off_11F9B4;
  *(_DWORD *)off_11F9A8 = v9 | 0x300;
  *v14 = v10;
  *v15 = v52;
  *v16 = v53;
  sub_12E948(dword_11F9B8, v52, v53);
LABEL_11:
  v17 = sub_12D190(off_11F9BC);
  v18 = dword_11F9C0;
  *(_BYTE *)(v17 + 106) = a2;
  v19 = v17;
  v20 = dword_11F9C4;
  *(_DWORD *)(v17 + 100) = *a1;
  *(_WORD *)(v17 + 104) = *((_WORD *)a1 + 2);
  v21 = (unsigned __int8)(v20 * ((v17 - v18) >> 3));
  *(_BYTE *)(v17 + 1224) = a3;
  v22 = dword_11F9C8;
  *(_DWORD *)(v17 + 12) = 2627;
  *(_DWORD *)(v17 + 16) = v22;
  *(_DWORD *)(v17 + 20) = dword_11F9CC;
  *(_WORD *)(v17 + 1222) = 1023;
  *(_DWORD *)(v17 + 8) = 2631;
  *(_BYTE *)(v17 + 107) = v21;
  *(_BYTE *)(v17 + 84) = v21;
  *(_BYTE *)(v17 + 109) = 127;
  *(_BYTE *)(v17 + 110) = 127;
  *(_DWORD *)(v17 + 72) = 0;
  *(_BYTE *)(v17 + 140) = 0;
  if ( a2 == 2 )
  {
    v38 = v4[18];
    if ( v38 )
    {
      v39 = a3;
    }
    else
    {
      sub_1216F4(2631, 127);
      v38 = v4[18];
      v21 = *(unsigned __int8 *)(v19 + 107);
      v39 = *(unsigned __int8 *)(v19 + 1224);
    }
    v40 = dword_11FA04 + 696 * (v21 + 32);
    v4[18] = v38 + 1;
    *(_BYTE *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(_DWORD *)(v19 + 28) = dword_11FA08;
      *(_DWORD *)(v19 + 32) = v19;
    }
    sub_125638(v19);
    v23 = (unsigned __int8)v4[17];
  }
  else if ( a2 == 4 )
  {
    if ( (unsigned __int8)v4[16] != 255 )
      return 1;
    v41 = *((_DWORD *)v4 + 2);
    v4[16] = v21;
    if ( v41 )
    {
      v42 = (int *)off_11F9D4;
      v43 = dword_11FA0C;
      v44 = **(__int16 **)off_11F9D0;
      *(_DWORD *)off_11F9D4 = dword_11FA0C;
      if ( v44 < 0 && *(_DWORD *)off_11FA68 << 28 )
      {
        sub_12F35C(dword_11FA70, dword_11FA6C, 472);
        v43 = *v42;
      }
      v45 = *(_DWORD *)(v41 + 72);
      *(_DWORD *)off_11F9D8 = v43 | v42[1];
      if ( v45 )
        sub_128994(*(unsigned __int8 *)(v45 + 24));
      v23 = (unsigned __int8)v4[17];
    }
    else
    {
      v55[0] = dword_11FA74;
      v55[1] = 2437;
      sub_12BAEC(2631, 127);
      if ( sub_127BF4(v55, &v54) )
        return 1;
      v47 = v54;
      *(_DWORD *)(v19 + 4) |= 0x80u;
      sub_128994(v47);
      v23 = (unsigned __int8)v4[17];
    }
  }
  else
  {
    v23 = (unsigned __int8)v4[17];
    if ( !a2 )
    {
      *(_DWORD *)(v17 + 28) = dword_11FA10;
      v46 = dword_11FA14;
      *(_DWORD *)(v17 + 32) = v17;
      v23 = (unsigned __int8)(v23 + 1);
      *(_WORD *)(v17 + 146) = 0;
      *(_DWORD *)(v17 + 160) = v17;
      v4[17] = v23;
      *(_BYTE *)(v17 + 116) = -1;
      *(_DWORD *)(v17 + 156) = v46;
    }
  }
  v24 = v23 + (unsigned __int8)v4[18];
  if ( v24 > 1 || v4[18] )
  {
    v25 = off_11F9D4;
    v26 = **(__int16 **)off_11F9D0;
    v27 = *((_DWORD *)off_11F9D4 + 1) | 0x100;
    *((_DWORD *)off_11F9D4 + 1) = v27;
    if ( v26 < 0 && *(_DWORD *)off_11F9F8 << 28 )
    {
      sub_12F35C(dword_11FA00, dword_11F9FC, 472);
      v27 = v25[1];
      v24 = (unsigned __int8)v4[17] + (unsigned __int8)v4[18];
    }
    *(_DWORD *)off_11F9D8 = v27 | *v25;
  }
  if ( v24 == 1 )
    *(_DWORD *)off_11F9DC |= 1u;
  if ( a3 )
  {
    v34 = *(unsigned __int8 *)(v19 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++v4[19];
    v36 = sub_129E28(v34, v35);
    v37 = (__int16 **)off_11F9D0;
    *(_BYTE *)(v19 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      sub_12F32C(dword_11F9F4, dword_11F9F0, 498);
  }
  v28 = dword_11F9E0;
  *a4 = *(_BYTE *)(v19 + 107);
  sub_12D108(v28);
  v29 = v19 + 1232;
  do
  {
    sub_12D100(v29);
    v30 = v29 + 40;
    v29 += 8;
    sub_12D100(v30);
  }
  while ( v29 != v19 + 1272 );
  sub_12D100(v19 + 1312);
  v31 = (unsigned __int8)v4[17] + (unsigned __int8)v4[18];
  *(_DWORD *)off_11F9E4 = 0;
  if ( v31 <= 1 )
    sub_11F5B0();
  sub_12EB90(256, dword_11F9EC);
  v32 = (_DWORD *)((unsigned __int8)v4[18] + (unsigned __int8)v4[17]);
  v33 = v32 == (_DWORD *)1;
  if ( v32 == (_DWORD *)1 )
    v32 = off_11F9A8;
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}

