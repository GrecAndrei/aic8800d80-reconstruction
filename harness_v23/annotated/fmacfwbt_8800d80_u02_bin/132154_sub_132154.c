// v23 annotated: sub_132154 @ 0x132154
// Original: 132154_sub_132154.c
// Primary struct: <unclustered>
//
// sub_132154 @ 0x132154, size 328 bytes
int __fastcall sub_132154(int a1, int a2, __int16 a3, __int16 a4)
{
  _BYTE *v4; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  _DWORD *v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  __int16 v18; // r1
  int v19; // r2
  char v20; // r2
  _DWORD *v22; // r6
  int v23; // r1
  int v24; // r2
  int v25; // r3
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r1
  _BYTE *v33; // r0
  int v34; // r0
  int v35; // r3
  unsigned int v36; // r2
  bool v37; // cc
  int v38; // r3

  v4 = off_13229C;
  *((_BYTE *)off_13229C + 374) = 0;
  if ( *(_BYTE *)(a2 + 103) )
  {
    v4[374] = 1;
    v8 = *(_DWORD *)(a2 + 4);
    v9 = *(_DWORD *)(a2 + 8);
    v10 = *(_DWORD *)(a2 + 12);
    *((_DWORD *)v4 + 3) = *(_DWORD *)a2;
    *((_DWORD *)v4 + 4) = v8;
    *((_DWORD *)v4 + 5) = v9;
    *((_DWORD *)v4 + 6) = v10;
    v11 = *(_DWORD *)(a2 + 20);
    v12 = *(_DWORD *)(a2 + 24);
    v13 = *(_DWORD *)(a2 + 28);
    *((_DWORD *)v4 + 7) = *(_DWORD *)(a2 + 16);
    *((_DWORD *)v4 + 8) = v11;
    *((_DWORD *)v4 + 9) = v12;
    *((_DWORD *)v4 + 10) = v13;
  }
  if ( *(_BYTE *)(a2 + 104) )
  {
    v14 = (_DWORD *)dword_1322A0;
    v4[374] |= 2u;
    v15 = *(_DWORD *)(a2 + 36);
    v16 = *(_DWORD *)(a2 + 40);
    *v14 = *(_DWORD *)(a2 + 32);
    v14[1] = v15;
    v14[2] = v16;
  }
  if ( sub_1151C0() )
  {
    *(_BYTE *)(a2 + 105) = 0;
    *(_BYTE *)(a2 + 106) = 0;
  }
  else
  {
    if ( *(_BYTE *)(a2 + 105) )
    {
      v22 = (_DWORD *)dword_1322A4;
      v4[374] |= 4u;
      v23 = *(_DWORD *)(a2 + 48);
      v24 = *(_DWORD *)(a2 + 52);
      v25 = *(_DWORD *)(a2 + 56);
      *v22 = *(_DWORD *)(a2 + 44);
      v22[1] = v23;
      v22[2] = v24;
      v22[3] = v25;
      v22 += 4;
      v26 = *(_DWORD *)(a2 + 64);
      v27 = *(_DWORD *)(a2 + 68);
      v28 = *(_DWORD *)(a2 + 72);
      *v22 = *(_DWORD *)(a2 + 60);
      v22[1] = v26;
      v22[2] = v27;
      v22[3] = v28;
      v22 += 4;
      v29 = *(_DWORD *)(a2 + 80);
      v30 = *(_DWORD *)(a2 + 84);
      v31 = *(_DWORD *)(a2 + 88);
      *v22 = *(_DWORD *)(a2 + 76);
      v22[1] = v29;
      v22[2] = v30;
      v22[3] = v31;
      v22 += 4;
      v32 = *(_DWORD *)(a2 + 96);
      *v22 = *(_DWORD *)(a2 + 92);
      v22[1] = v32;
    }
    if ( *(_BYTE *)(a2 + 106) )
      v4[374] |= 8u;
  }
  v4[373] = *(_BYTE *)(a2 + 102);
  message_dispatch_n84(5121, a4, a3);
  if ( (v4[374] & 1) != 0 )
  {
    v34 = chip_rev_get();
    v35 = (unsigned __int8)v4[374] << 29;
    v4[372] = (v34 + 1) >> 1;
    if ( v35 < 0 )
    {
      v36 = (unsigned __int8)v4[373];
      v37 = v36 > 2;
      if ( v36 > 2 )
        v36 = (unsigned __int8)v4[73];
      v38 = (unsigned __int8)v4[68] >> 2;
      if ( v37 )
        v38 &= v36 >> 6;
      v4[116] = v38 & 1;
    }
  }
  else
  {
    v4[372] = 0;
  }
  v17 = *(unsigned __int8 *)(a2 + 107);
  v18 = *(_WORD *)(a2 + 100);
  v4[375] = v17;
  v19 = *(unsigned __int8 *)(a2 + 109);
  *((_WORD *)v4 + 22) = v18;
  if ( v19 )
    v20 = 2;
  else
    v20 = 1;
  v4[376] = v20;
  if ( v17 )
  {
    *((_WORD *)v4 + 4) = 255;
    v33 = (_BYTE *)rf_bus_setup_n3a8(49, 0, 5, 1u);
    *v33 = v4[376];
    sub_12CBB4((int)v33);
    rf_bus_mark_n_3b7(5u, 1);
  }
  return 0;
}

