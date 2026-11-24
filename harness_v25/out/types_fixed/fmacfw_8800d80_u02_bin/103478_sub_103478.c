// sub_103478 @ 0x103478, size 1722 bytes
void __fastcall sub_103478()
{
  _BYTE *v0; // r4
  int *v1; // r2
  _DWORD *v2; // r0
  int v3; // r1
  _DWORD *v4; // r5
  _BYTE **v5; // r5
  _DWORD *v6; // r1
  int v7; // r6
  _DWORD *v8; // r0
  _DWORD *v9; // r8
  int v10; // r2
  _DWORD *v11; // r3
  _DWORD *v12; // r1
  int v13; // r0
  _DWORD *v14; // r3
  _DWORD *v15; // r1
  _DWORD *v16; // r4
  _DWORD *v17; // r5
  char *v18; // r6
  int v19; // r9
  int i; // r4
  int v21; // r0
  _DWORD *v22; // r4
  int v23; // r9
  int v24; // r10
  int k; // r5
  int v26; // r0
  int v27; // r5
  int v28; // r10
  int v29; // r0
  int v30; // r9
  unsigned __int64 v31; // kr00_8
  bool v32; // zf
  unsigned __int8 v33; // r2
  int v34; // r3
  int v35; // r3
  int *v36; // r4
  _DWORD *v37; // r2
  int v38; // r0
  int v39; // r1
  int v40; // r3
  int v41; // r4
  int v42; // r1
  _WORD *v43; // r5
  int v44; // r1
  __int16 v45; // r2
  int v46; // r0
  int inited; // r0
  unsigned int *v48; // r2
  int v49; // r0
  int j; // r4
  unsigned __int8 v51; // r2
  int *v52; // r2
  int v53; // r3
  int v54; // r6
  int v55; // r0
  int v56; // r5
  _BYTE *v57; // r4
  _DWORD *v58; // r3
  _DWORD *v59; // r1
  _BYTE *v60; // r3
  char v61; // r1
  char v62; // r2
  _DWORD *v63; // r4
  int v64; // r10
  int v65; // r11
  _DWORD *v66; // r6
  unsigned __int8 *v67; // r4
  unsigned __int8 *v68; // r7
  int n; // r5
  char v70; // t1
  int v71; // r3
  _DWORD *v72; // r5
  int v73; // r9
  _DWORD *v74; // r7
  int v75; // r11
  char *v76; // r10
  int m; // r4
  char v78; // t1
  int v79; // r1
  char *v80; // [sp+4h] [bp-30h]
  _BYTE *(_DWORD *)(v81 + 0x10); // [sp+Ch] [bp-28h] BYREF
  _DWORD *(_DWORD *)(v82 + 0xc); // [sp+10h] [bp-24h] BYREF
  unsigned __int8 *(_DWORD *)(v83 + 0x60); // [sp+1Ch] [bp-18h] BYREF

  v0 = off_1035E0;
  *((_DWORD *)off_1035DC + 64) = 8;
  if ( !*(_DWORD *)(v0 + 0x8) )
    *((_DWORD *)off_1035E4 + 2) = *((_DWORD *)off_1035E4 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_1035E4;
  while ( (*((_DWORD *)off_1035E4 + 12) & 0x22) != 2 )
    ;
  v2 = off_1035E8;
  v3 = dword_1035EC;
  v4 = off_1035DC;
  *((_DWORD *)off_1035E4 + 2) = *((_DWORD *)off_1035E4 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  *(_DWORD *)(v1 + 0x54) = *(_DWORD *)(v1 + 0x54) & 0x37F | 0x80 | *(_DWORD *)(v1 + 0x54) & v3;
  *(_DWORD *)(v4 + 0x144) = 16;
  v5 = (_BYTE **)off_1035F0;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    *(_DWORD *)(v1 + 0x54) = v3 & *(_DWORD *)(v1 + 0x54) | *(_DWORD *)(v1 + 0x54) & 0x3F7 | 8;
  }
  irq_mask_init();
  v6 = off_1035E4;
  v7 = dword_1035EC;
  v8 = off_1035DC;
  v9 = off_103600;
  *(_DWORD *)off_1035E4 = *(_DWORD *)off_1035E4 & 0x3EF | 0x10 | *(_DWORD *)off_1035E4 & dword_1035EC;
  *(_DWORD *)(v6 + 0x54) = *(_DWORD *)(v6 + 0x54) & 0x3EF | 0x10 | *(_DWORD *)(v6 + 0x54) & v7;
  *(_DWORD *)(v8 + 0x58) &= 0xFFFFFFC1;
  v10 = *((unsigned __int8 *)v9 + 177);
  *(_DWORD *)(v8 + 0x58) |= 0x26u;
  if ( v10 && (*(_DWORD *)(v6 + 0x30) & 0x40) == 0 && (*(_DWORD *)(v6 + 0x30) & 4) != 0 )
  {
    v52 = (int *)off_103B38;
    v53 = *(_DWORD *)(v9 + 0xa8) | 0x2000000;
    *(_BYTE *)off_103B34 = 1;
    *v52 = v53;
    *(_DWORD *)(v8 + 0x38) |= 0x10u;
  }
  else
  {
    *(_DWORD *)off_1035F4 = *(_DWORD *)(v9 + 0xa8);
  }
  if ( *(_DWORD *)(v0 + 0x8) )
  {
    if ( **(_BYTE **)off_1035F8 == 2 )
    {
      v58 = off_103B48;
      v59 = off_103B4C;
      *((_DWORD *)off_103B48 + 20) |= 0x40000u;
      *(_DWORD *)(v59 + 0x1c) &= ~0x100u;
      *(_DWORD *)(v58 + 0x24) = *(_DWORD *)(v58 + 0x24) & 0xFFFFFF00 | 0x60;
      *(_DWORD *)(v58 + 0x24) = *(_DWORD *)(v58 + 0x24) & 0xFFFF00FF | 0xDF00;
LABEL_13:
      irq23_enable_d628();
      hw_reg_set_40035000();
      if ( !*(_DWORD *)off_1035FC )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_1035E4;
    **(_BYTE **)off_1035F8 = 2;
    v12 = off_1035DC;
    v13 = (unsigned __int8)*(_DWORD *)(v0 + 0x8);
    *(_DWORD *)(v11 + 0x50) |= 0x40000u;
    *(_DWORD *)(v12 + 0x1c) &= ~0x100u;
    *(_DWORD *)(v11 + 0x24) = *(_DWORD *)(v11 + 0x24) & 0xFFFFFF00 | 0x60;
    *(_DWORD *)(v11 + 0x24) = *(_DWORD *)(v11 + 0x24) & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v14 = off_103914;
    v15 = off_103918;
    *((_DWORD *)off_103914 + 20) |= 0x40000u;
    *(_DWORD *)(v15 + 0x1c) &= ~0x100u;
    *(_DWORD *)(v14 + 0x24) = *(_DWORD *)(v14 + 0x24) & 0xFFFFFF00 | 0x60;
    *(_DWORD *)(v14 + 0x24) = *(_DWORD *)(v14 + 0x24) & 0xFFFF00FF | 0xDF00;
  }
  sub_10D5D4();
  hw_reg_set_40035000();
  if ( *(_DWORD *)off_10391C )
  {
LABEL_14:
    rf_init_blocka();
    rf_init_blockb_e560();
    sub_10E2A0();
  }
LABEL_17:
  v16 = off_103918;
  patch_check_1202f80();
  *(_DWORD *)(v16 + 0x10) |= 2u;
  sub_103258();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = off_103920;
    v18 = (char *)off_103924;
    v19 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v21 = rf_fault_dump_n1d9(i, *v17 + 3 * i);
      if ( v21 != 546 )
      {
        *(_DWORD *)(v18 + 0x4) |= 1u;
        v19 = 0;
      }
    }
    if ( v19 )
    {
      for ( j = 0; j != 3; ++j )
      {
        *(_DWORD *)(v83 + 0x0) = 0;
        if ( sub_114A3C(j, v83) <= 1 )
        {
          v51 = *(_DWORD *)(v83 + 0x0);
          *(_BYTE *)(*v17 + j) = *(_DWORD *)(v83 + 0x0);
          *(_BYTE *)(*v17 + j + 3) = v51;
          *(_BYTE *)(*v17 + j + 6) = v51;
        }
      }
    }
    v22 = off_103928;
    v23 = dword_10397C;
    v24 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v26 = sub_11499C(k, *v22 + 6 * k);
      if ( v26 != v23 )
      {
        *(_DWORD *)(v18 + 0x4) |= 1u;
        v24 = 0;
      }
    }
    if ( v24 )
    {
      v27 = 0;
      v28 = dword_103980;
      *(_DWORD *)(v83 + 0x0) = 0;
      v29 = 2;
      v30 = 4;
      do
      {
        v31 = (unsigned int)v28 * (unsigned __int64)(unsigned int)(2 * v27);
        v32 = v30 == HIDWORD(v31) >> 1;
        v30 = HIDWORD(v31) >> 1;
        if ( !v32 )
          v29 = patch_apply_n_428(HIDWORD(v31) >> 1, v83);
        if ( v29 <= 1 )
        {
          v33 = *(_DWORD *)(v83 + 0x0);
          *(_BYTE *)(*v22 + v27) = *(_DWORD *)(v83 + 0x0);
          v34 = *v22 + v27;
          *(_BYTE *)(v34 + 6) = v33;
          *(_BYTE *)(v34 + 12) = v33;
        }
        ++v27;
      }
      while ( v27 != 6 );
    }
    *v18 = 31 - __clz(rf_fault_dump_n464());
  }
  else
  {
    memset(v82, 0, sizeof(v82));
    v54 = patch_apply_n_16c((int)v82);
    if ( v54 )
    {
      v18 = (char *)off_103B3C;
    }
    else
    {
      v72 = off_103B64;
      v73 = dword_103B68;
      sub_10DC24(dword_103B60);
      v74 = v82;
      do
      {
        sub_10DC24(dword_103B58, v54);
        v75 = 3 * v54;
        v76 = (char *)v74;
        for ( m = 0; m != 3; ++m )
        {
          v78 = *v76++;
          *(_BYTE *)(*v72 + v75 + m) = v78;
          v79 = *(char *)(*v72 + v75 + m);
          sub_10DC24(v73, v79);
        }
        ++v54;
        v74 = (_DWORD *)((char *)v74 + 3);
      }
      while ( v54 != 3 );
      v18 = (char *)off_103B3C;
      sub_10DC24(dword_103B5C);
      *(_DWORD *)(v18 + 0x4) |= 1u;
    }
    memset(v83, 0, 20);
    if ( !patch_apply_n_160((int)v83) )
    {
      v63 = off_103B50;
      v64 = dword_103B68;
      sub_10DC24(dword_103B54);
      v65 = 0;
      v80 = v18;
      v66 = v63;
      v67 = v83;
      do
      {
        sub_10DC24(dword_103B58, v65);
        v68 = v67;
        for ( n = 0; n != 6; ++n )
        {
          v70 = *v68++;
          *(_BYTE *)(*v66 + n + 6 * v65) = v70;
          v71 = *v66 + n;
          sub_10DC24(v64, *(char *)(v71 + 6 * v65));
        }
        ++v65;
        v67 += 6;
      }
      while ( v65 != 3 );
      v18 = v80;
      sub_10DC24(dword_103B5C);
      *(_DWORD *)(v80 + 0x4) |= 1u;
    }
    if ( sub_114D70((int)v81) )
      *v18 = -1;
    else
      *v18 = *(_DWORD *)(v81 + 0x0);
  }
  sub_10DC24(dword_10392C);
  if ( *((_BYTE *)v9 + 372) )
  {
    if ( (*(_DWORD *)off_103918 & 0x2000000) != 0 )
    {
      if ( patch_apply_bit() )
      {
        v55 = rf_fault_dump_n3c0();
        v56 = dword_103B40;
        v57 = off_103B44;
        *(_BYTE *)off_103B44 = *(_BYTE *)(dword_103B40 + v55);
        *(_DWORD *)(v57 + 0x4) = *(_BYTE *)(v56 + sub_114B1C());
        *(_DWORD *)(v57 + 0x8) = *(_BYTE *)(v56 + patch_apply_n_37c());
      }
    }
    else
    {
      *(_DWORD *)v83 = 0;
      if ( !patch_apply_n_154((int)v83) )
      {
        v60 = off_103B44;
        v61 = *(_BYTE *)(dword_103B40 + *(_DWORD *)(v83 + 0x4));
        v62 = *(_BYTE *)(dword_103B40 + *(_DWORD *)(v83 + 0x8));
        *(_BYTE *)off_103B44 = *(_BYTE *)(dword_103B40 + *(_DWORD *)(v83 + 0x0));
        *(_DWORD *)(v60 + 0x4) = v61;
        *(_DWORD *)(v60 + 0x8) = v62;
      }
    }
  }
  v35 = dword_103934;
  v36 = (int *)off_103938;
  *(_DWORD *)off_103930 &= 0xFFFFFFC7;
  sub_102EB8(0, 0, 0x10u, v35);
  sub_102EB8(0, 16, 0x10u, dword_10393C);
  sub_102EB8(0, 32, 0x10u, *(_DWORD *)(v36 + 0x8));
  sub_102EB8(0, 48, 0x10u, *(_DWORD *)(v36 + 0x4));
  sub_102EB8(0, 64, 0x10u, *v36);
  sub_102EB8(1, 0, 0x10u, *(_DWORD *)off_103940);
  sub_102EB8(1, 16, 0x10u, *(_DWORD *)off_103944);
  mmio_regs_poll_1200ee8();
  sub_1032FC();
  message_dispatch_n244(0);
  sub_1032FC();
  if ( (*(_DWORD *)(v9 + 0x188) & 4) != 0 )
  {
    v37 = off_103948;
    v38 = dword_10394C;
    v39 = dword_103950;
    *((_DWORD *)off_103948 + 13) = dword_10394C;
    *(_DWORD *)(v37 + 0x38) = v39;
    --v38;
    v39 -= 10;
    *(_DWORD *)(v37 + 0x1b4) = v38;
    *(_DWORD *)(v37 + 0x1b8) = v39;
    v38 += 2;
    v39 -= 8;
    v40 = dword_103954;
    *(_DWORD *)(v37 + 0x330) = v38;
    *(_DWORD *)(v37 + 0x334) = v39;
    v38 += 33;
    v39 += 41;
    v41 = dword_103958;
    *(_DWORD *)(v37 + 0x338) = v38;
    *(_DWORD *)(v37 + 0x3c) = v39;
    v38 -= 7;
    *(_DWORD *)(v37 + 0x1bc) = v39;
    *(_DWORD *)(v37 + 0x33c) = v39;
    *(_DWORD *)(v37 + 0x4bc) = v39;
    *(_DWORD *)(v37 + 0x63c) = v39;
    *(_DWORD *)(v37 + 0x7bc) = v39;
    v39 -= 16;
    *(_DWORD *)(v37 + 0x4b8) = v39;
    *(_DWORD *)(v37 + 0x638) = v39;
    *(_DWORD *)(v37 + 0x7b8) = v39;
    *(_DWORD *)(v37 + 0x4b0) = v41;
    *(_DWORD *)(v37 + 0x630) = v41;
    *(_DWORD *)(v37 + 0x7b0) = v41;
    *(_DWORD *)(v37 + 0x4b4) = v38;
    *(_DWORD *)(v37 + 0x634) = v38;
    *(_DWORD *)(v37 + 0x7b4) = v38;
    v42 = v40 + 7584;
    do
    {
      *(_DWORD *)(v40 + 1272) |= 0x8000u;
      v40 += 1264;
    }
    while ( v40 != v42 );
  }
  v43 = off_103960;
  *(_DWORD *)off_10395C |= 0x8000000u;
  v44 = sub_130374();
  v45 = ((int)(((unsigned __int64)(dword_103964 * (__int64)(4 * (v44 - 35))) >> 32) + 4 * (v44 - 35)) >> 2)
      - ((__int16)((unsigned int)(v44 - 35) >> 14) >> 15)
      + 120;
  v46 = dword_103968;
  *(_WORD *)off_103984 = v45;
  *v43 = v45;
  msg_parse(v46, v44);
  inited = mmio_init_peripherals((unsigned int *)v83);
  sub_10DC24(dword_10396C, inited, *(_DWORD *)v83);
  if ( (*(_DWORD *)(v18 + 0x4) & 1) != 0 && *v18 < 0 )
  {
    v48 = (unsigned int *)off_103974;
    *(_DWORD *)off_103970 = *(_DWORD *)off_103970 & 0xFFFFFF87 | 0x40;
    *v48 = *v48 & 0xFFF87FFF | 0x40000;
  }
  v49 = sub_10EC44();
  sub_10DC24(dword_103978, v49);
}
