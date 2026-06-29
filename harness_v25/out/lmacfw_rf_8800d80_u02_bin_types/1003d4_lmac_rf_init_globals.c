// lmac_rf_init_globals @ 0x1003d4, size 190 bytes
// Doc: lmac_rf_init_globals [util]: Initializes lmac RF global pointer table at boot
// lmac_rf_init_globals [util]: Initializes lmac RF global pointer table at boot
void __noreturn lmac_rf_init_globals()
{
  uint8_t *v0; // r4
  uint32_t *v1; // r2
  uint32_t *v2; // r5
  uint32_t *v3; // r1
  uint32_t *v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r6
  int inited; // r0
  uint32_t *v8; // r3
  int v9; // r0
  int v10; // r0
  uint16_t *v11; // r2
  unsigned __int8 *v12; // r6
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0

  v0 = off_100498;
  v1 = off_10049C;
  v2 = off_1004A0;
  *(uint32_t *)off_100494 = off_100498;
  *v1 = v0 + 12;
  v3 = off_1004A4;
  v4 = off_1004A8;
  v5 = off_1004AC;
  v6 = off_1004B0;
  *v2 = v0 + 76;
  *v3 = v0 + 136;
  *v4 = v0 + 152;
  *v6 = v0 + 178;
  *v5 = v0 + 176;
  inited = rf_init_setup_n_2a0();
  if ( *(uint8_t *)*v2 == 1 )
  {
    v8 = off_1004B8;
    *((uint32_t *)off_1004B4 + 22) &= ~1u;
    v8[20] |= 1u;
    v8[20] &= ~2u;
  }
  v9 = sub_123068(inited);
  v10 = sub_10F4B8(v9);
  rf_init_submodule_dispatch(v10);
  v11 = (uint16_t *)*v6;
  v12 = (unsigned __int8 *)off_1004BC;
  v13 = dword_1004C0;
  *v11 |= 0x2000u;
  v14 = msg_parse(v13, *v12);
  v15 = rf_init_calibration_n174(v14);
  if ( v0[363] )
  {
    v19 = rf_level_apply_n274(v15);
    sub_127108(v19);
  }
  v16 = msg_parse(dword_1004C4, (unsigned __int8)v0[76]);
  v17 = sub_10FFF0(v16);
  v18 = log_system_init_f6a4(v17);
  if ( *(uint8_t *)*v2 == 3 )
    *(uint32_t *)off_1004C8 = 1;
  sub_115018(v18);
}

