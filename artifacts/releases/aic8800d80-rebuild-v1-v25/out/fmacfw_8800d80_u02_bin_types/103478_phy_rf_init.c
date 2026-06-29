// phy_rf_init @ 0x103478, size 1722 bytes
// Doc: phy_rf_init [rf]: Initialize PHY/RF subsystem hardware
// phy_rf_init [rf]: Initialize PHY/RF subsystem hardware
void __noreturn phy_rf_init()
{
  uint8_t *v0; // r4
  int *v1; // r2
  uint32_t *v2; // r0
  int v3; // r1
  uint32_t *v4; // r5
  uint8_t **v5; // r5
  uint32_t *v6; // r1
  int v7; // r6
  uint32_t *v8; // r0
  uint32_t *v9; // r8
  int v10; // r2
  uint32_t *v11; // r3
  uint32_t *v12; // r1
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int inited; // r0
  int v17; // r0
  uint32_t *v18; // r3
  uint32_t *v19; // r1
  int v20; // r0
  uint32_t *v21; // r4
  uint32_t *v22; // r5
  uint8_t *v23; // r6
  int v24; // r9
  int i; // r4
  int v26; // r0
  uint32_t *v27; // r4
  int v28; // r9
  int v29; // r10
  int k; // r5
  int v31; // r0
  int v32; // r5
  int v33; // r10
  int v34; // r0
  int v35; // r9
  unsigned uint64_t v36; // kr00_8
  bool v37; // zf
  unsigned __int8 v38; // r2
  int v39; // r3
  unsigned int v40; // r1
  int v41; // r2
  int v42; // r0
  int v43; // r3
  int *v44; // r4
  int j; // r4
  unsigned __int8 v46; // r2
  int *v47; // r2
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r6
  uint8_t *v52; // r6
  int v53; // r1
  int v54; // r2
  unsigned int v55; // r3
  int v56; // r0
  int v57; // r5
  uint8_t *v58; // r4
  uint32_t *v59; // r3
  uint32_t *v60; // r1
  uint8_t *v61; // r3
  char v62; // r1
  char v63; // r2
  uint32_t *v64; // r4
  int v65; // r10
  int v66; // r2
  int v67; // r11
  uint32_t *v68; // r6
  unsigned __int8 *v69; // r4
  char *v70; // r7
  int n; // r5
  int v72; // t1
  int v73; // r3
  int v74; // r1
  uint32_t *v75; // r5
  int v76; // r9
  int v77; // r2
  uint32_t *v78; // r7
  int v79; // r11
  char *v80; // r10
  int m; // r4
  int v82; // t1
  int v83; // r1
  int v84; // r1
  uint8_t *v85; // [sp+4h] [bp-30h]
  uint8_t v86[4]; // [sp+Ch] [bp-28h] BYREF
  uint32_t v87[3]; // [sp+10h] [bp-24h] BYREF
  unsigned __int8 v88[24]; // [sp+1Ch] [bp-18h] BYREF

  v0 = off_1035E0;
  *((uint32_t *)off_1035DC + 64) = 8;
  if ( !v0[2] )
    *((uint32_t *)off_1035E4 + 2) = *((uint32_t *)off_1035E4 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_1035E4;
  while ( (*((uint32_t *)off_1035E4 + 12) & 0x22) != 2 )
    ;
  v2 = off_1035E8;
  v3 = dword_1035EC;
  v4 = off_1035DC;
  *((uint32_t *)off_1035E4 + 2) = *((uint32_t *)off_1035E4 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (uint8_t **)off_1035F0;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  irq_mask_init();
  v6 = off_1035E4;
  v7 = dword_1035EC;
  v8 = off_1035DC;
  v9 = off_103600;
  *(uint32_t *)off_1035E4 = *(uint32_t *)off_1035E4 & 0x3EF | 0x10 | *(uint32_t *)off_1035E4 & dword_1035EC;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((unsigned __int8 *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v47 = (int *)off_103B38;
    v48 = v9[42] | 0x2000000;
    *(uint8_t *)off_103B34 = 1;
    *v47 = v48;
    v8[14] |= 0x10u;
  }
  else
  {
    *(uint32_t *)off_1035F4 = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(uint8_t **)off_1035F8 == 2 )
    {
      v59 = off_103B48;
      v60 = off_103B4C;
      *((uint32_t *)off_103B48 + 20) |= 0x40000u;
      v60[7] &= ~0x100u;
      v59[9] = v59[9] & 0xFFFFFF00 | 0x60;
      v59[9] = v59[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      v14 = irq23_enable_d628();
      v15 = hw_reg_set_40035000(v14);
      if ( !*(uint32_t *)off_1035FC )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_1035E4;
    **(uint8_t **)off_1035F8 = 2;
    v12 = off_1035DC;
    v13 = (unsigned __int8)v0[2];
    v11[20] |= 0x40000u;
    v12[7] &= ~0x100u;
    v11[9] = v11[9] & 0xFFFFFF00 | 0x60;
    v11[9] = v11[9] & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v18 = off_103914;
    v19 = off_103918;
    *((uint32_t *)off_103914 + 20) |= 0x40000u;
    v19[7] &= ~0x100u;
    v18[9] = v18[9] & 0xFFFFFF00 | 0x60;
    v18[9] = v18[9] & 0xFFFF00FF | 0xDF00;
  }
  v20 = sub_10D5D4();
  v15 = hw_reg_set_40035000(v20);
  if ( !*(uint32_t *)off_10391C )
  {
LABEL_17:
    v21 = off_103918;
    patch_check_1202f80();
    v21[4] |= 2u;
    sub_103258();
    if ( (*v21 & 0x2000000) != 0 )
    {
      v22 = off_103920;
      v23 = off_103924;
      v24 = 1;
      for ( i = 0; i != 3; ++i )
      {
        v26 = rf_fault_dump_n1d9(i, *v22 + 3 * i);
        if ( v26 != 546 )
        {
          v23[1] |= 1u;
          v24 = 0;
        }
      }
      if ( v24 )
      {
        for ( j = 0; j != 3; ++j )
        {
          v88[0] = 0;
          if ( sub_114A3C(j, v88) <= 1 )
          {
            v46 = v88[0];
            *(uint8_t *)(*v22 + j) = v88[0];
            *(uint8_t *)(*v22 + j + 3) = v46;
            *(uint8_t *)(*v22 + j + 6) = v46;
          }
        }
      }
      v27 = off_103928;
      v28 = dword_10397C;
      v29 = 1;
      for ( k = 0; k != 3; ++k )
      {
        v31 = sub_11499C(k, *v27 + 6 * k);
        if ( v31 != v28 )
        {
          v23[1] |= 1u;
          v29 = 0;
        }
      }
      if ( v29 )
      {
        v32 = 0;
        v33 = dword_103980;
        v88[0] = 0;
        v34 = 2;
        v35 = 4;
        do
        {
          v36 = (unsigned int)v33 * (unsigned uint64_t)(unsigned int)(2 * v32);
          v37 = v35 == HIDWORD(v36) >> 1;
          v35 = HIDWORD(v36) >> 1;
          if ( !v37 )
            v34 = patch_apply_n_428(HIDWORD(v36) >> 1, v88);
          if ( v34 <= 1 )
          {
            v38 = v88[0];
            *(uint8_t *)(*v27 + v32) = v88[0];
            v39 = *v27 + v32;
            *(uint8_t *)(v39 + 6) = v38;
            *(uint8_t *)(v39 + 12) = v38;
          }
          ++v32;
        }
        while ( v32 != 6 );
      }
      v40 = 31 - __clz(rf_fault_dump_n464());
      *v23 = v40;
    }
    else
    {
      memset(v87, 0, sizeof(v87));
      v51 = patch_apply_n_16c(v87);
      if ( v51 )
      {
        v52 = off_103B3C;
      }
      else
      {
        v75 = off_103B64;
        v76 = dword_103B68;
        sub_10DC24(dword_103B60, v49, v50);
        v78 = v87;
        do
        {
          sub_10DC24(dword_103B58, v51, v77);
          v79 = 3 * v51;
          v80 = (char *)v78;
          for ( m = 0; m != 3; ++m )
          {
            v82 = *v80++;
            *(uint8_t *)(*v75 + v79 + m) = v82;
            v83 = *(char *)(*v75 + v79 + m);
            sub_10DC24(v76, v83, v82);
          }
          ++v51;
          v78 = (uint32_t *)((char *)v78 + 3);
        }
        while ( v51 != 3 );
        v52 = off_103B3C;
        sub_10DC24(dword_103B5C, v84, v77);
        v52[1] |= 1u;
      }
      memset(v88, 0, 20);
      if ( !patch_apply_n_160(v88) )
      {
        v64 = off_103B50;
        v65 = dword_103B68;
        sub_10DC24(dword_103B54, v53, v54);
        v67 = 0;
        v85 = v52;
        v68 = v64;
        v69 = v88;
        do
        {
          sub_10DC24(dword_103B58, v67, v66);
          v70 = (char *)v69;
          for ( n = 0; n != 6; ++n )
          {
            v72 = *v70++;
            *(uint8_t *)(*v68 + n + 6 * v67) = v72;
            v73 = *v68 + n;
            sub_10DC24(v65, *(char *)(v73 + 6 * v67), v72);
          }
          ++v67;
          v69 += 6;
        }
        while ( v67 != 3 );
        v52 = v85;
        sub_10DC24(dword_103B5C, v74, v66);
        v85[1] |= 1u;
      }
      if ( sub_114D70(v86) )
      {
        v40 = -1;
        *v52 = -1;
      }
      else
      {
        v55 = v86[0];
        *v52 = v86[0];
        v40 = v55;
      }
    }
    v42 = sub_10DC24(dword_10392C, v40, v41);
    if ( *((uint8_t *)v9 + 372) )
    {
      if ( (*(uint32_t *)off_103918 & 0x2000000) != 0 )
      {
        if ( patch_apply_bit(v42) )
        {
          v56 = rf_fault_dump_n3c0();
          v57 = dword_103B40;
          v58 = off_103B44;
          *(uint8_t *)off_103B44 = *(uint8_t *)(dword_103B40 + v56);
          v58[1] = *(uint8_t *)(v57 + sub_114B1C());
          v58[2] = *(uint8_t *)(v57 + patch_apply_n_37c());
        }
      }
      else
      {
        *(uint32_t *)v88 = 0;
        if ( !patch_apply_n_154(v88) )
        {
          v61 = off_103B44;
          v62 = *(uint8_t *)(dword_103B40 + v88[1]);
          v63 = *(uint8_t *)(dword_103B40 + v88[2]);
          *(uint8_t *)off_103B44 = *(uint8_t *)(dword_103B40 + v88[0]);
          v61[1] = v62;
          v61[2] = v63;
        }
      }
    }
    v43 = dword_103934;
    v44 = (int *)off_103938;
    *(uint32_t *)off_103930 &= 0xFFFFFFC7;
    sub_102EB8(0, 0, 0x10u, v43);
    sub_102EB8(0, 16, 0x10u, dword_10393C);
    sub_102EB8(0, 32, 0x10u, v44[2]);
    sub_102EB8(0, 48, 0x10u, v44[1]);
    sub_102EB8(0, 64, 0x10u, *v44);
    sub_102EB8(1, 0, 0x10u, *(uint32_t *)off_103940);
    sub_102EB8(1, 16, 0x10u, *(uint32_t *)off_103944);
    mmio_regs_poll_1200ee8();
    sub_1032FC();
  }
LABEL_14:
  inited = rf_init_blocka(v15);
  v17 = rf_init_blockb_e560(inited);
  sub_10E2A0(v17);
  goto LABEL_17;
}

