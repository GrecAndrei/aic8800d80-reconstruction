// sub_1125F4 @ 0x1125f4, size 594 bytes
// Doc: rf_bus_mark_n_372 [rf]: Mark/latch RF bus transaction state
// rf_bus_mark_n_372 [rf]: Mark/latch RF bus transaction state
int sub_1125F4()
{
  uint32_t *v0; // r3
  int v1; // r2
  int v2; // r4
  uint64_t v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r8
  int v7; // r11
  uint32_t *v8; // r6
  int v9; // r5
  int v10; // r4
  int v11; // r9
  char *v12; // r3
  int v13; // r2
  int ( *v14)(int, int, BOOL); // r3
  uint32_t *v15; // r5
  int v16; // r6
  int v17; // r9
  int v18; // r7
  int i; // r4
  char *v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r3
  uint32_t *v25; // r3
  uint32_t **v26; // r4
  int *v27; // r0
  int v28; // r1
  uint32_t *v29; // r1
  int v30; // r4
  int ( *v31)(int, int, uint32_t); // r3
  BOOL v33; // [sp+4h] [bp-10h]
  int v34; // [sp+4h] [bp-10h]
  int v35; // [sp+8h] [bp-Ch]
  int v36; // [sp+8h] [bp-Ch]
  int v37; // [sp+Ch] [bp-8h]
  int v38; // [sp+Ch] [bp-8h]

  v0 = off_112848;
  v1 = *((uint32_t *)off_112848 + 5);
  *((uint32_t *)off_112848 + 5) = v1;
  v2 = v0[6] & v1;
  LODWORD(v3) = v2 << 19;
  if ( (v2 & 0x1000) != 0 )
  {
    LODWORD(v3) = sub_1122F0();
    v4 = v2 & 0x2000;
    if ( (v2 & 0x2000) == 0 )
      return v3;
    v7 = 0;
    v6 = 0;
    v5 = 0;
  }
  else
  {
    HIDWORD(v3) = v2 << 18;
    v4 = v2 & rf_bus_write2_n_4f3;
    v5 = v2 & 0x40000;
    v6 = v2 & 0x80000;
    v7 = v2 & 0x800;
    if ( (v2 & 0x2000) == 0 )
      goto rf_bus_reset_n334;
  }
  v24 = *((uint32_t *)off_112848 + 514);
  if ( (v24 & 6) != 0 && (v24 & 2) != 0 )
    *(uint32_t *)rf_cmd_send_n_bc = 1;
  v25 = off_112848;
  v26 = (uint32_t **)rf_cmd_send_n_b8;
  v27 = (int *)rf_cmd_send_n_b4;
  v28 = rf_cmd_send_n_b0;
  *((uint32_t *)off_112848 + 576) = rf_cmd_send_n_b0;
  v25[704] = v28;
  v29 = *v26;
  v30 = *v27;
  LODWORD(v3) = rf_cmd_send_n_ac;
  *v29 = rf_cmd_send_n_ac;
  v29[1] = v30;
  v25[709] = v29;
  v25[706] = v25[706];
  HIDWORD(v3) = v25[704] | 0x84000000;
  v25[704] = HIDWORD(v3);
rf_bus_reset_n334:
  if ( v5 )
  {
    v8 = off_112848;
    v9 = rf_cmd_send_n_cc;
    v10 = 0;
    v11 = *((uint32_t *)off_112848 + 518) & *((uint32_t *)off_112848 + 519);
    while ( 1 )
    {
      LODWORD(v3) = 1;
      if ( ((1 << v10) & v11) != 0 )
      {
        if ( !v10 )
        {
          HIDWORD(v3) = v8[578];
          v8[578] = HIDWORD(v3);
          v23 = v8[516] & HIDWORD(v3);
          if ( (v23 & 0x18) != 0 )
          {
            v8[516] &= ~0x10u;
            sub_111524(0, 0x200000, 0);
          }
          else if ( (v23 & 1) != 0 )
          {
            rf_level_apply_n_358(v3);
          }
          goto rf_cmd_send_n_272;
        }
        v12 = (char *)&v8[8 * v10 - 8];
        v13 = *((uint32_t *)v12 + 586);
        *((uint32_t *)v12 + 586) = v13;
        HIDWORD(v3) = v8[516] & v13;
        if ( (v3 & 0x900000000LL) != 0 )
        {
          if ( *(uint8_t *)(v9 - 5) )
          {
            v35 = *(uint32_t *)(v9 - 12);
            v37 = *(uint32_t *)(v9 - 16);
            v33 = (v13 & 1) == 0;
            if ( (v13 & 1) == 0 )
              sub_11164C((int *)1, (unsigned __int8)v10);
            LODWORD(v3) = sub_100200((int *)(v9 - 16), 0, 0x10u);
            v14 = *(int ( **)(int, int, BOOL))(rf_cmd_send_n_c8 + 4 * v10 + 52);
            if ( v14 )
              LODWORD(v3) = v14(v37, v35, v33);
          }
        }
        else
        {
          LODWORD(v3) = sub_10DA6C(dword_112858);
        }
      }
      if ( (unsigned __int8)v10 == 5 )
        break;
rf_cmd_send_n_272:
      ++v10;
      v9 += 16;
    }
  }
  if ( v6 )
  {
    v15 = off_112848;
    v16 = rf_cmd_send_n_c4;
    v17 = dword_112874;
    v18 = *((uint32_t *)off_112848 + 518) & *((uint32_t *)off_112848 + 519);
    for ( i = 0; ; ++i )
    {
      if ( ((0x10000 << i) & v18) != 0 )
      {
        if ( !i )
        {
          HIDWORD(v3) = v15[706];
          v15[706] = HIDWORD(v3);
          v22 = v15[517] & HIDWORD(v3);
          if ( (v22 & 0x10) != 0 )
          {
            v15[517] &= ~0x10u;
            LODWORD(v3) = rf_bus_write_1(0, 0x200000, 0);
          }
          else if ( (v22 & 0x29) != 0 )
          {
            LODWORD(v3) = 0;
            LODWORD(v3) = rf_level_apply_n_358(v3);
          }
          goto LABEL_19;
        }
        v20 = (char *)&v15[8 * i - 8];
        v21 = *((uint32_t *)v20 + 714);
        *((uint32_t *)v20 + 714) = v21;
        if ( (v15[517] & v21 & 1) != 0 )
        {
          if ( *(uint8_t *)(v16 - 8) )
          {
            v36 = **(unsigned __int16 **)(v17 + 4 * i);
            v34 = *(uint32_t *)(v16 - 12);
            v38 = *(uint32_t *)(v16 - 16);
            LODWORD(v3) = sub_100200((int *)(v16 - 16), 0, 0x10u);
            v31 = *(int ( **)(int, int, uint32_t))(4 * i + rf_cmd_send_n_c8 + 32);
            if ( v31 )
              LODWORD(v3) = v31(v38, v34 - v36, 0);
          }
        }
      }
      if ( (unsigned __int8)i == 5 )
        break;
LABEL_19:
      v16 += 16;
    }
  }
  if ( v7 )
  {
    LODWORD(v3) = rf_cmd_send_n_3ac(v3, SHIDWORD(v3));
    if ( v4 >= 0 )
      return v3;
  }
  else if ( v4 >= 0 )
  {
    return v3;
  }
  LODWORD(v3) = sub_1125B0(v3, SHIDWORD(v3));
  return v3;
}

