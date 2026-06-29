// sub_10E560 @ 0x10e560, size 664 bytes
int sub_10E560()
{
  uint32_t *v0; // r1
  int v1; // r3
  int v2; // r2
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r5
  int v8; // r10
  int v9; // r8
  int v10; // r0
  uint64_t v11; // r0
  uint64_t v12; // r0
  int v13; // r0
  int v14; // r9
  int v15; // r4
  uint32_t *v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  int v21; // r3
  int v22; // r3
  int v23; // r11
  uint32_t *v24; // r6
  int v25; // r4
  int i; // r7
  int v27; // r2
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r0
  int v32; // r10
  int v33; // r5
  int v34; // r2
  uint32_t *v35; // r2
  uint64_t v36; // r0
  uint64_t v37; // r0
  uint64_t v38; // r0
  uint64_t v39; // r0
  int v40; // r0
  int result; // r0
  int v42; // [sp+0h] [bp-Ch]
  int v43; // [sp+4h] [bp-8h]

  v0 = off_10E814;
  v1 = dword_10E818;
  v2 = dword_10E81C;
  *((uint32_t *)off_10E810 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = sub_1429B4(v0[4]);
  v4 = sub_142AA8(v3, HIDWORD(v3), dword_10E7F8, dword_10E7FC);
  v5 = sub_142CFC(v4, HIDWORD(v4), dword_10E800, dword_10E804);
  v6 = sub_142738(v5, HIDWORD(v5), dword_10E7F8, dword_10E7FC);
  v7 = sub_142FDC(v6, HIDWORD(v6));
  v8 = sub_10ED6C(dword_10E820) & 0x1F;
  v9 = v7 - 840;
  sub_10DC24(dword_10E824, v7, v8);
  v10 = abs32(v7 - 840);
  if ( v10 <= 47 )
  {
    if ( (unsigned int)(v10 - 1) > 0x2E )
    {
      v9 = 0;
      goto LABEL_33;
    }
    if ( v9 <= 0 )
      v22 = 1;
    else
      v22 = -1;
    v42 = v22;
    v14 = 0;
  }
  else
  {
    v11 = sub_1429D4(v10);
    v12 = sub_142AA8(v11, HIDWORD(v11), dword_10E808, dword_10E80C);
    v13 = sub_142FDC(v12, HIDWORD(v12));
    v14 = v13;
    if ( v9 <= 0 )
    {
      if ( v7 == 840 )
        goto LABEL_33;
      v15 = v13 + v8;
    }
    else
    {
      v15 = v8 - v13;
    }
    if ( v15 > 31 )
    {
      v8 += 9;
      v9 = 9;
      goto LABEL_33;
    }
    if ( v15 <= 12 )
    {
      v8 -= 9;
      v9 = -9;
      goto LABEL_33;
    }
    sub_10ED7C(dword_10E820, v15, 31);
    v16 = off_10E814;
    *((uint32_t *)off_10E814 + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = sub_1429B4(v16[4]);
    v18 = sub_142AA8(v17, HIDWORD(v17), dword_10E7F8, dword_10E7FC);
    v19 = sub_142CFC(v18, HIDWORD(v18), dword_10E800, dword_10E804);
    v20 = sub_142738(v19, HIDWORD(v19), dword_10E7F8, dword_10E7FC);
    v7 = sub_142FDC(v20, HIDWORD(v20));
    sub_12EA88(dword_10E828, v14, v15);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v42 = v21;
  }
  v23 = dword_10E820;
  v24 = off_10E814;
  v43 = v8;
  v25 = v42 + v14 * v42 + v8;
  for ( i = v14 + 1; ; ++i )
  {
    v27 = v14;
    v9 = v25 - v43;
    v14 = i;
    if ( (unsigned int)(v25 - 13) > 0x12 )
    {
      v9 = v42 * v27;
      v8 = v43 + v42 * v27;
      goto LABEL_33;
    }
    sub_10ED7C(v23, v25, 31);
    v24[1] = 1;
    while ( v24[7] != 1 )
      ;
    v24[7] = 1;
    v28 = sub_1429B4(v24[4]);
    v29 = sub_142AA8(v28, HIDWORD(v28), dword_10E7F8, dword_10E7FC);
    v30 = sub_142CFC(v29, HIDWORD(v29), dword_10E800, dword_10E804);
    v31 = sub_142738(v30, HIDWORD(v30), dword_10E7F8, dword_10E7FC);
    v32 = sub_142FDC(v31, HIDWORD(v31));
    sub_12EA88(dword_10E82C, v9, v25);
    v33 = v7 - 840;
    v34 = v32 - 840;
    if ( v33 * (v32 - 840) <= 0 )
      break;
    v25 += v42;
    v7 = v32;
  }
  if ( v34 < 0 )
    v34 = 840 - v32;
  if ( v33 < 0 )
    v33 = -v33;
  if ( v34 > v33 )
  {
    v9 -= v42;
    v8 = v43 + v9;
  }
  else
  {
    v8 = v25;
  }
LABEL_33:
  sub_10DC24(dword_10E830, v9);
  sub_10ED7C(dword_10E820, v8, 31);
  v35 = off_10E814;
  *((uint32_t *)off_10E814 + 1) = 1;
  while ( v35[7] != 1 )
    ;
  v35[7] = 1;
  v36 = sub_1429B4(v35[4]);
  v37 = sub_142AA8(v36, HIDWORD(v36), dword_10E7F8, dword_10E7FC);
  v38 = sub_142CFC(v37, HIDWORD(v37), dword_10E800, dword_10E804);
  v39 = sub_142738(v38, HIDWORD(v38), dword_10E7F8, dword_10E7FC);
  v40 = sub_142FDC(v39, HIDWORD(v39));
  sub_10DC24(dword_10E834, v40);
  result = *((uint32_t *)off_10E838 + 94);
  if ( result != 0x80000000 )
    return sub_11130C();
  return result;
}

