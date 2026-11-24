// sub_11F7C0 @ 0x11f7c0, size 1000 bytes
int __fastcall sub_11F7C0(int *a1, int a2, int a3, _BYTE *a4)
{
  _BYTE *v4; // r9
  int **v5; // r4
  int result; // r0
  int v7; // r0
  int v8; // r6
  int v9; // r7
  int v10; // r8
  int v11; // r11
  int v12; // r5
  int v13; // r10
  int *v14; // r3
  int *v15; // r1
  int *v16; // r2
  _DWORD *v17; // r0
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
  _DWORD *v29; // r5
  _DWORD *v30; // r0
  int v31; // r2
  int v32; // r3
  _DWORD *v33; // r3
  bool v34; // zf
  int v35; // r0
  int v36; // r1
  int v37; // r0
  __int16 **v38; // r3
  char v39; // r2
  int v40; // r5
  int v41; // r3
  int v42; // r6
  int *v43; // r5
  int v44; // r3
  int v45; // r2
  int v46; // r2
  int v47; // r2
  int v48; // r0
  int v53; // [sp+20h] [bp-1Ch]
  int v54; // [sp+24h] [bp-18h]
  unsigned __int8 v55; // [sp+2Bh] [bp-11h] BYREF
  _DWORD *(_DWORD *)(v56 + 0x10); // [sp+2Ch] [bp-10h] BYREF

  v4 = off_11FAFC;
  if ( !*(_DWORD *)off_11FAFC )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(_BYTE *)off_11FB58 )
      return 1;
    v5 = *((int ***)off_11FAFC + 2);
    if ( v5 )
    {
      if ( *((_BYTE *)off_11FAFC + 19) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    mmio_init_regs_1221788(a1);
    goto LABEL_11;
  }
  v5 = *((int ***)off_11FAFC + 2);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = dword_11FAE4;
  v8 = *a1;
  v53 = *a1;
  v9 = 0;
  v54 = *((unsigned __int16 *)a1 + 2);
  v10 = 0;
  v11 = v54;
  do
  {
    v12 = (int)*(_DWORD *)(v5 + 0x64);
    v13 = *((unsigned __int16 *)v5 + 52);
    msg_parse(v7, v12, v13, *((unsigned __int8 *)v5 + 1224));
    v5 = (int **)*v5;
    v7 = dword_11FAE4;
    v10 |= v12 ^ v8;
    v8 &= v12;
    v9 |= v13 ^ v11;
    v11 &= v13;
  }
  while ( v5 );
  v14 = (int *)off_11FAEC;
  v15 = (int *)off_11FAF0;
  v16 = (int *)off_11FAF4;
  *(_DWORD *)off_11FAE8 = v9 | 0x300;
  *v14 = v10;
  *v15 = v53;
  *v16 = v54;
  msg_parse(dword_11FAF8, v53, v54, v10, v9, a3);
LABEL_11:
  v17 = rf_bus_mark_n100_d2d0((int)off_11FAFC);
  v18 = dword_11FB00;
  *((_BYTE *)v17 + 106) = a2;
  v19 = (int)v17;
  v20 = dword_11FB04;
  *(_DWORD *)(v17 + 0x64) = *a1;
  *((_WORD *)v17 + 52) = *((_WORD *)a1 + 2);
  v21 = (unsigned __int8)(v20 * (((int)v17 - v18) >> 3));
  *((_BYTE *)v17 + 1224) = a3;
  v22 = dword_11FB08;
  *(_DWORD *)(v17 + 0xc) = 2627;
  *(_DWORD *)(v17 + 0x10) = v22;
  *(_DWORD *)(v17 + 0x14) = dword_11FB0C;
  *((_WORD *)v17 + 611) = 1023;
  *(_DWORD *)(v17 + 0x8) = 2631;
  *((_BYTE *)v17 + 107) = v21;
  *((_BYTE *)v17 + 84) = v21;
  *((_BYTE *)v17 + 109) = 127;
  *((_BYTE *)v17 + 110) = 127;
  *(_DWORD *)(v17 + 0x48) = 0;
  *((_BYTE *)v17 + 140) = 0;
  if ( a2 == 2 )
  {
    v39 = *(_DWORD *)(v4 + 0x48);
    if ( v39 )
    {
      v40 = a3;
    }
    else
    {
      sub_121834();
      v39 = *(_DWORD *)(v4 + 0x48);
      v21 = *(unsigned __int8 *)(v19 + 107);
      v40 = *(unsigned __int8 *)(v19 + 1224);
    }
    v41 = dword_11FB44 + 696 * (v21 + 32);
    *(_DWORD *)(v4 + 0x48) = v39 + 1;
    *(_BYTE *)(v41 + 37) = 1;
    if ( v40 )
    {
      *(_DWORD *)(v19 + 28) = dword_11FB48;
      *(_DWORD *)(v19 + 32) = v19;
    }
    sub_125778(v19);
    v23 = (unsigned __int8)*(_DWORD *)(v4 + 0x44);
  }
  else if ( a2 == 4 )
  {
    if ( (unsigned __int8)*(_DWORD *)(v4 + 0x40) != 255 )
      return 1;
    v42 = *((_DWORD *)v4 + 2);
    *(_DWORD *)(v4 + 0x40) = v21;
    if ( v42 )
    {
      v43 = (int *)off_11FB14;
      v44 = dword_11FB4C;
      v45 = **(__int16 **)off_11FB10;
      *(_DWORD *)off_11FB14 = dword_11FB4C;
      if ( v45 < 0 && *(_DWORD *)off_11FBA8 << 28 )
      {
        sub_12F49C(dword_11FBB0, dword_11FBAC, 472);
        v44 = *v43;
      }
      v46 = *(_DWORD *)(v42 + 72);
      *(_DWORD *)off_11FB18 = v44 | *(_DWORD *)(v43 + 0x4);
      if ( v46 )
        sub_128AD4(*(unsigned __int8 *)(v46 + 24));
      v23 = (unsigned __int8)*(_DWORD *)(v4 + 0x44);
    }
    else
    {
      *(_DWORD *)(v56 + 0x0) = dword_11FBB4;
      *(_DWORD *)(v56 + 0x4) = 2437;
      sub_12BC2C();
      if ( sub_127D34((unsigned __int8 *)v56, &v55) )
        return 1;
      v48 = v55;
      *(_DWORD *)(v19 + 4) |= 0x80u;
      sub_128AD4(v48);
      v23 = (unsigned __int8)*(_DWORD *)(v4 + 0x44);
    }
  }
  else
  {
    v23 = (unsigned __int8)*(_DWORD *)(v4 + 0x44);
    if ( !a2 )
    {
      *(_DWORD *)(v17 + 0x1c) = dword_11FB50;
      v47 = dword_11FB54;
      *(_DWORD *)(v17 + 0x20) = v17;
      v23 = (unsigned __int8)(v23 + 1);
      *((_WORD *)v17 + 73) = 0;
      *(_DWORD *)(v17 + 0xa0) = v17;
      *(_DWORD *)(v4 + 0x44) = v23;
      *((_BYTE *)v17 + 116) = -1;
      *(_DWORD *)(v17 + 0x9c) = v47;
    }
  }
  v24 = v23 + (unsigned __int8)*(_DWORD *)(v4 + 0x48);
  if ( v24 > 1 || *(_DWORD *)(v4 + 0x48) )
  {
    v25 = off_11FB14;
    v26 = **(__int16 **)off_11FB10;
    v27 = *((_DWORD *)off_11FB14 + 1) | 0x100;
    *((_DWORD *)off_11FB14 + 1) = v27;
    if ( v26 < 0 && *(_DWORD *)off_11FB38 << 28 )
    {
      sub_12F49C(dword_11FB40, dword_11FB3C, 472);
      v27 = *(_DWORD *)(v25 + 0x4);
      v24 = (unsigned __int8)*(_DWORD *)(v4 + 0x44) + (unsigned __int8)*(_DWORD *)(v4 + 0x48);
    }
    *(_DWORD *)off_11FB18 = v27 | *v25;
  }
  if ( v24 == 1 )
    *(_DWORD *)off_11FB1C |= 1u;
  if ( a3 )
  {
    v35 = *(unsigned __int8 *)(v19 + 107);
    v36 = a2;
    if ( a2 )
      v36 = 1;
    ++*(_DWORD *)(v4 + 0x4c);
    v37 = sub_129F68(v35, v36);
    v38 = (__int16 **)off_11FB10;
    *(_BYTE *)(v19 + 1225) = v37;
    if ( **v38 < 0 && v37 == 255 )
      sub_12F46C(dword_11FB34, dword_11FB30, 498);
  }
  v28 = dword_11FB20;
  *a4 = *(_BYTE *)(v19 + 107);
  list_push_tail(v28, (_DWORD *)v19);
  v29 = (_DWORD *)(v19 + 1232);
  do
  {
    sub_12D240(v29);
    v30 = v29 + 10;
    v29 += 2;
    sub_12D240(v30);
  }
  while ( v29 != (_DWORD *)(v19 + 1272) );
  sub_12D240((_DWORD *)(v19 + 1312));
  v31 = (unsigned __int8)*(_DWORD *)(v4 + 0x48);
  v32 = (unsigned __int8)*(_DWORD *)(v4 + 0x44) + v31;
  *(_DWORD *)off_11FB24 = 0;
  if ( v32 <= 1 )
  {
    sub_11F6F0();
    v31 = (unsigned __int8)*(_DWORD *)(v4 + 0x48);
    v32 = (unsigned __int8)*(_DWORD *)(v4 + 0x44) + v31;
  }
  feature_guard_check(256, dword_11FB2C, dword_11FB28, v32, v31, a2, a3, (unsigned __int8)*a4);
  v33 = (_DWORD *)((unsigned __int8)*(_DWORD *)(v4 + 0x48) + (unsigned __int8)*(_DWORD *)(v4 + 0x44));
  v34 = v33 == (_DWORD *)1;
  if ( v33 == (_DWORD *)1 )
    v33 = off_11FAE8;
  result = 0;
  if ( v34 )
    *v33 = 0;
  return result;
}
