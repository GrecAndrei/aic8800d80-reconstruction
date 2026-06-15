// v23 annotated: sub_10E2A0 @ 0x10e2a0
// Original: 10e2a0_sub_10E2A0.c
// Primary struct: <unclustered>
//
// sub_10E2A0 @ 0x10e2a0, size 628 bytes
int sub_10E2A0()
{
  int v0; // r3
  int v1; // r0
  _DWORD *v2; // r4
  __int64 v3; // r0
  __int64 v4; // r0
  __int64 v5; // r0
  int v6; // r5
  int v7; // r2
  char cb; // r0
  int v9; // r2
  int v10; // r4
  int v11; // r3
  int v12; // r6
  __int64 v13; // r0
  __int64 v14; // r0
  int v15; // r0
  int v16; // r8
  int v17; // r4
  _DWORD *v18; // r2
  __int64 v19; // r0
  __int64 v20; // r0
  __int64 v21; // r0
  int v22; // r3
  int v23; // r3
  int v24; // r11
  _DWORD *v25; // r6
  int v26; // r10
  int v27; // r7
  int v28; // r4
  int v29; // r9
  __int64 v30; // r0
  __int64 v31; // r0
  __int64 v32; // r0
  int v33; // r5
  int v34; // r3
  _DWORD *v35; // r2
  __int64 v36; // r0
  __int64 v37; // r0
  __int64 v38; // r0
  int v39; // r0
  int v40; // r2
  int v42; // [sp+4h] [bp-10h]
  int v43; // [sp+8h] [bp-Ch]
  int v44; // [sp+Ch] [bp-8h]

  v0 = dword_10E534;
  v1 = dword_10E538;
  v2 = off_10E53C;
  *((_DWORD *)off_10E530 + 14) = 296;
  v2[3] = v0 | v2[3] & 0xE0000000;
  sub_10ED7C(v1, 1024, 15360);
  v2[2] = dword_10E540 & v2[2] | 0x1200000F;
  v2[1] = 1;
  while ( v2[7] != 1 )
    ;
  v2[7] = 1;
  v3 = sub_1429B4(v2[4]);
  v4 = sub_142AA8(v3, HIDWORD(v3), dword_10E518, dword_10E51C);
  v5 = sub_142738(v4, HIDWORD(v4), dword_10E520, dword_10E524);
  v6 = sub_142FDC(v5, HIDWORD(v5));
  msg_parse(dword_10E544, v6, v7);
  cb = rf_reg_read_cb(dword_10E548);
  v10 = v6 - 1400;
  v11 = abs32(v6 - 1400);
  v12 = cb & 0x3F;
  v43 = v12;
  if ( v11 > 49 )
  {
    v13 = sub_1429D4(v11);
    v14 = sub_142AA8(v13, HIDWORD(v13), dword_10E528, dword_10E52C);
    v15 = sub_142FDC(v14, HIDWORD(v14));
    v16 = v15;
    if ( v10 <= 0 )
    {
      v34 = v12;
      if ( v6 == 1400 )
        goto LABEL_39;
      v17 = v15 + v12;
    }
    else
    {
      v17 = v12 - v15;
    }
    if ( v17 > 32 )
    {
      v29 = 7;
      v28 = v12 + 7;
      goto LABEL_28;
    }
    if ( v17 > 11 )
    {
      sub_10ED7C(dword_10E548, v17, 63);
      v18 = off_10E53C;
      *((_DWORD *)off_10E53C + 1) = 1;
      while ( v18[7] != 1 )
        ;
      v18[7] = 1;
      v19 = sub_1429B4(v18[4]);
      v20 = sub_142AA8(v19, HIDWORD(v19), dword_10E518, dword_10E51C);
      v21 = sub_142738(v20, HIDWORD(v20), dword_10E520, dword_10E524);
      v6 = sub_142FDC(v21, HIDWORD(v21));
      msg_parse(dword_10E54C, v16, v17);
      if ( v6 <= 1400 )
        v22 = 1;
      else
        v22 = -1;
      v44 = v22;
      goto LABEL_19;
    }
    v34 = v12;
LABEL_39:
    v28 = v34 - 13;
    v29 = -13;
    goto LABEL_28;
  }
  if ( (unsigned int)(v11 - 1) > 0x30 )
  {
    v28 = cb & 0x3F;
    v29 = 0;
    goto LABEL_28;
  }
  if ( v10 <= 0 )
    v23 = 1;
  else
    v23 = -1;
  v44 = v23;
  v16 = 0;
LABEL_19:
  v24 = dword_10E548;
  v25 = off_10E53C;
  v26 = dword_10E558;
  v27 = v16 + 1;
  v28 = v44 + v16 * v44 + v43;
  while ( 1 )
  {
    v9 = v16;
    v29 = v28 - v43;
    v16 = v27;
    if ( (unsigned int)(v28 - 12) > 0x14 )
    {
      v29 = v44 * v9;
      v28 = v43 + v44 * v9;
      goto LABEL_28;
    }
    sub_10ED7C(v24, v28, 63);
    v25[1] = 1;
    while ( v25[7] != 1 )
      ;
    v25[7] = 1;
    v30 = sub_1429B4(v25[4]);
    v31 = sub_142AA8(v30, HIDWORD(v30), dword_10E518, dword_10E51C);
    v32 = sub_142738(v31, HIDWORD(v31), dword_10E520, dword_10E524);
    v42 = sub_142FDC(v32, HIDWORD(v32));
    msg_parse(v26, v29, v28);
    v33 = v6 - 1400;
    v9 = v42 - 1400;
    if ( v33 * (v42 - 1400) <= 0 )
      break;
    v28 += v44;
    v6 = v42;
    ++v27;
  }
  if ( v9 < 0 )
    v9 = 1400 - v42;
  if ( v33 < 0 )
    v33 = -v33;
  if ( v9 > v33 )
  {
    v29 -= v44;
    v28 = v43 + v29;
  }
LABEL_28:
  msg_parse(dword_10E550, v29, v9);
  sub_10ED7C(dword_10E548, v28, 63);
  v35 = off_10E53C;
  *((_DWORD *)off_10E53C + 1) = 1;
  while ( v35[7] != 1 )
    ;
  v35[7] = 1;
  v36 = sub_1429B4(v35[4]);
  v37 = sub_142AA8(v36, HIDWORD(v36), dword_10E518, dword_10E51C);
  v38 = sub_142738(v37, HIDWORD(v37), dword_10E520, dword_10E524);
  v39 = sub_142FDC(v38, HIDWORD(v38));
  msg_parse(dword_10E554, v39, v40);
  return sub_10ED7C(dword_10E538, 0, 15360);
}

