// firmware_init_0478 @ 0x100478, size 240 bytes
// Doc: firmware_init_0478 [util]: Initialize firmware globals and link module table pointers
// firmware_init_0478 [util]: Initialize firmware globals and link module table pointers
void __noreturn firmware_init_0478()
{
  uint8_t *v0; // r4
  uint32_t *v1; // r5
  uint32_t *v2; // r3
  uint32_t *v3; // r0
  uint32_t *v4; // r2
  uint32_t *v5; // r3
  uint32_t *v6; // r1
  int v7; // r0
  uint32_t *v8; // r3
  uint8_t *v9; // r6
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int inited; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  uint32_t *v17; // r2
  int v18; // r1
  int v19; // r0
  int v20; // r0

  v0 = off_100568;
  v1 = off_100570;
  v2 = off_100574;
  v3 = off_100578;
  *(uint32_t *)off_10056C = off_100568;
  v4 = off_10057C;
  *v1 = v0 + 76;
  *v2 = v0 + 12;
  *v3 = v0 + 136;
  v5 = off_100580;
  v6 = off_100584;
  *v4 = v0 + 152;
  *v5 = v0 + 178;
  *v6 = v0 + 176;
  v7 = sub_1002A0();
  if ( *(uint8_t *)*v1 == 1 )
  {
    v8 = off_10058C;
    *((uint32_t *)off_100588 + 22) &= ~1u;
    v8[20] |= 1u;
    v8[20] &= ~2u;
  }
  v9 = off_100594;
  *((uint8_t *)off_100594 + 2) = (*(uint32_t *)off_100590 & 0xF) == 10;
  v10 = sub_1301B4(v7);
  v11 = log_hw_regs_init(v10);
  v12 = rf_cmd_send_n_36c(v11);
  inited = fw_init_seq_n_12(v12);
  if ( v0[363] )
  {
    v20 = sub_130714(inited);
    sub_1307D0(v20);
  }
  v14 = sub_12ECB0(dword_10059C, (unsigned __int8)v0[76], *(unsigned __int8 *)off_100598);
  v15 = sub_10FF58(v14);
  v16 = log_system_init(v15);
  if ( v9[2] )
  {
    sub_1143C4(v16);
    v17 = off_100590;
    v18 = dword_1005A4;
    *(uint32_t *)off_1005A0 &= ~8u;
    *v17 &= 0xFFFFFFF0;
    v19 = feature_guard_sdio(2, v18);
  }
  else
  {
    v19 = feature_guard_sdio(2, dword_1005AC);
  }
  if ( *(uint8_t *)*v1 == 3 )
    *(uint32_t *)off_1005A8 = 1;
  sub_116188(v19);
}

