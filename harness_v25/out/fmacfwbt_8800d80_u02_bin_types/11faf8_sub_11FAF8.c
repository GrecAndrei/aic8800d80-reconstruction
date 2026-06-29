// sub_11FAF8 @ 0x11faf8, size 1000 bytes
int  sub_11FAF8(int *a1, int a2, int a3, uint8_t *a4)
{
  uint8_t *v4; // r9
  int **v5; // r4
  int result; // r0
  int v7; // r0
  int v8; // r6
  int v9; // r7
  int v10; // r8
  int v11; // r11
  int *v12; // r5
  int v13; // r10
  uint32_t *v14; // r3
  uint32_t *v15; // r1
  uint32_t *v16; // r2
  int v17; // r0
  int v18; // r2
  int v19; // r4
  char v20; // r3
  int v21; // r3
  int v22; // r2
  int v23; // r3
  int v24; // r3
  uint32_t *v25; // r5
  int v26; // r1
  int v27; // r2
  int v28; // r0
  int v29; // r5
  int v30; // r0
  int v31; // r3
  uint32_t *v32; // r3
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
  uint32_t v55[4]; // [sp+2Ch] [bp-10h] BYREF

  v4 = off_11FE34;
  if ( !*(uint32_t *)off_11FE34 )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(uint8_t *)off_11FE90 )
      return 1;
    v5 = *((int ***)off_11FE34 + 2);
    if ( v5 )
    {
      if ( *((uint8_t *)off_11FE34 + 19) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    rf_reg_init_load(a1);
    goto LABEL_11;
  }
  v5 = *((int ***)off_11FE34 + 2);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = dword_11FE1C;
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
    sub_12ECB0(v7, v12, v13);
    v5 = (int **)*v5;
    v7 = dword_11FE1C;
    v10 |= (unsigned int)v12 ^ v8;
    v8 &= (unsigned int)v12;
    v9 |= v13 ^ v11;
    v11 &= v13;
  }
  while ( v5 );
  v14 = off_11FE24;
  v15 = off_11FE28;
  v16 = off_11FE2C;
  *(uint32_t *)off_11FE20 = v9 | 0x300;
  *v14 = v10;
  *v15 = v52;
  *v16 = v53;
  sub_12ECB0(dword_11FE30, v52, v53);
LABEL_11:
  v17 = sub_12D4F8(off_11FE34);
  v18 = dword_11FE38;
  *(uint8_t *)(v17 + 106) = a2;
  v19 = v17;
  v20 = dword_11FE3C;
  *(uint32_t *)(v17 + 100) = *a1;
  *(uint16_t *)(v17 + 104) = *((uint16_t *)a1 + 2);
  v21 = (unsigned __int8)(v20 * ((v17 - v18) >> 3));
  *(uint8_t *)(v17 + 1224) = a3;
  v22 = dword_11FE40;
  *(uint32_t *)(v17 + 12) = 2627;
  *(uint32_t *)(v17 + 16) = v22;
  *(uint32_t *)(v17 + 20) = dword_11FE44;
  *(uint16_t *)(v17 + 1222) = 1023;
  *(uint32_t *)(v17 + 8) = 2631;
  *(uint8_t *)(v17 + 107) = v21;
  *(uint8_t *)(v17 + 84) = v21;
  *(uint8_t *)(v17 + 109) = 127;
  *(uint8_t *)(v17 + 110) = 127;
  *(uint32_t *)(v17 + 72) = 0;
  *(uint8_t *)(v17 + 140) = 0;
  if ( a2 == 2 )
  {
    v38 = v4[18];
    if ( v38 )
    {
      v39 = a3;
    }
    else
    {
      sub_121A94(2631, 127);
      v38 = v4[18];
      v21 = *(unsigned __int8 *)(v19 + 107);
      v39 = *(unsigned __int8 *)(v19 + 1224);
    }
    v40 = dword_11FE7C + 696 * (v21 + 32);
    v4[18] = v38 + 1;
    *(uint8_t *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(uint32_t *)(v19 + 28) = dword_11FE80;
      *(uint32_t *)(v19 + 32) = v19;
    }
    sub_12599C(v19);
    v23 = (unsigned __int8)v4[17];
  }
  else if ( a2 == 4 )
  {
    if ( (unsigned __int8)v4[16] != 255 )
      return 1;
    v41 = *((uint32_t *)v4 + 2);
    v4[16] = v21;
    if ( v41 )
    {
      v42 = (int *)off_11FE4C;
      v43 = dword_11FE84;
      v44 = **(__int16 **)off_11FE48;
      *(uint32_t *)off_11FE4C = dword_11FE84;
      if ( v44 < 0 && *(uint32_t *)off_11FEE0 << 28 )
      {
        sub_12F6C4(dword_11FEE8, dword_11FEE4, 472);
        v43 = *v42;
      }
      v45 = *(uint32_t *)(v41 + 72);
      *(uint32_t *)off_11FE50 = v43 | v42[1];
      if ( v45 )
        fw_state_lookup_n_528(*(unsigned __int8 *)(v45 + 24));
      v23 = (unsigned __int8)v4[17];
    }
    else
    {
      v55[0] = dword_11FEEC;
      v55[1] = 2437;
      sub_12BE54(2631, 127);
      if ( sub_127F58(v55, &v54) )
        return 1;
      v47 = v54;
      *(uint32_t *)(v19 + 4) |= 0x80u;
      fw_state_lookup_n_528(v47);
      v23 = (unsigned __int8)v4[17];
    }
  }
  else
  {
    v23 = (unsigned __int8)v4[17];
    if ( !a2 )
    {
      *(uint32_t *)(v17 + 28) = dword_11FE88;
      v46 = dword_11FE8C;
      *(uint32_t *)(v17 + 32) = v17;
      v23 = (unsigned __int8)(v23 + 1);
      *(uint16_t *)(v17 + 146) = 0;
      *(uint32_t *)(v17 + 160) = v17;
      v4[17] = v23;
      *(uint8_t *)(v17 + 116) = -1;
      *(uint32_t *)(v17 + 156) = v46;
    }
  }
  v24 = v23 + (unsigned __int8)v4[18];
  if ( v24 > 1 || v4[18] )
  {
    v25 = off_11FE4C;
    v26 = **(__int16 **)off_11FE48;
    v27 = *((uint32_t *)off_11FE4C + 1) | 0x100;
    *((uint32_t *)off_11FE4C + 1) = v27;
    if ( v26 < 0 && *(uint32_t *)off_11FE70 << 28 )
    {
      sub_12F6C4(dword_11FE78, dword_11FE74, 472);
      v27 = v25[1];
      v24 = (unsigned __int8)v4[17] + (unsigned __int8)v4[18];
    }
    *(uint32_t *)off_11FE50 = v27 | *v25;
  }
  if ( v24 == 1 )
    *(uint32_t *)off_11FE54 |= 1u;
  if ( a3 )
  {
    v34 = *(unsigned __int8 *)(v19 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++v4[19];
    v36 = sub_12A18C(v34, v35);
    v37 = (__int16 **)off_11FE48;
    *(uint8_t *)(v19 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      sub_12F694(dword_11FE6C, dword_11FE68, 498);
  }
  v28 = dword_11FE58;
  *a4 = *(uint8_t *)(v19 + 107);
  list_push_tail(v28);
  v29 = v19 + 1232;
  do
  {
    bt_xtal_init_check(v29);
    v30 = v29 + 40;
    v29 += 8;
    bt_xtal_init_check(v30);
  }
  while ( v29 != v19 + 1272 );
  bt_xtal_init_check(v19 + 1312);
  v31 = (unsigned __int8)v4[17] + (unsigned __int8)v4[18];
  *(uint32_t *)off_11FE5C = 0;
  if ( v31 <= 1 )
    sub_11FA28();
  feature_guard_sdio(256, dword_11FE64);
  v32 = (uint32_t *)((unsigned __int8)v4[18] + (unsigned __int8)v4[17]);
  v33 = v32 == (uint32_t *)1;
  if ( v32 == (uint32_t *)1 )
    v32 = off_11FE20;
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}

