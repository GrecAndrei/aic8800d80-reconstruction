// sub_13876C @ 0x13876c, size 316 bytes
// Doc: sub_123876C [bt]: Bluetooth firmware handler, checks flag and processes state
// sub_123876C [bt]: Bluetooth firmware handler, checks flag and processes state
uint32_t *sub_13876C()
{
  uint32_t *v0; // r6
  uint16_t *v1; // r4
  uint32_t *v2; // r5
  int v3; // r6
  char *v4; // r3
  char *v5; // r0
  uint32_t *v6; // r3
  uint8_t *v7; // r1
  BOOL v8; // r2
  BOOL v9; // r0
  int *v10; // r2
  uint16_t *v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  int v15; // r1
  uint32_t *v16; // r2
  int v17; // r3
  int v18; // r2

  if ( *(uint8_t *)off_1388A8 )
    rf_power_set(0xC2u);
  if ( **(uint8_t **)off_1388AC == 1 )
    *(uint32_t *)off_1388B0 &= ~0x200000u;
  v0 = off_1388B4;
  v1 = off_1388B8;
  v2 = off_1388BC;
  if ( (*(uint32_t *)off_1388B4 & 4) != 0 )
  {
    v15 = *(unsigned __int16 *)(*(uint32_t *)off_1388E0 + 54);
    v16 = off_1388E8;
    v17 = dword_1388E4 + 1320 * *(unsigned __int8 *)(*(uint32_t *)off_1388B8 + 366);
    *((uint8_t *)off_1388BC + 29) = 3;
    v18 = v16[4];
    v2[5] = v17;
    timestamp_update_4f60((int)(v2 + 3), v15 + v18);
    *((uint8_t *)v2 + 28) = 1;
    *v0 &= ~4u;
  }
  v3 = *((unsigned __int8 *)v1 + 3850);
  if ( !*((uint8_t *)v1 + 3850) )
  {
    v4 = (char *)off_1388B8;
    v5 = (char *)off_1388B8 + 3840;
    do
    {
      v4[8] = v3;
      v4[64] = 0x80;
      v4 += 60;
    }
    while ( v5 != v4 );
    v6 = off_1388C0;
    v1[2] = v3;
    v6[1] = v3;
  }
  v7 = *(uint8_t **)v1;
  if ( *(uint8_t *)(*(uint32_t *)v1 + 368) == 1 && v7[252] == 7 )
  {
    v9 = sub_1437AC(v7 + 253, dword_1388DC, 7) == 0;
    v7 = *(uint8_t **)v1;
    v3 = *((unsigned __int8 *)v1 + 3850);
    v8 = v9;
  }
  else
  {
    v8 = 0;
    LOBYTE(v9) = 0;
  }
  *((uint8_t *)v1 + 3898) = v9;
  feature_guard_sdio(8, dword_1388C8, dword_1388C4, (unsigned __int8)v7[366], v3, v8, (unsigned __int8)v7[367]);
  v10 = (int *)off_1388D0;
  v11 = off_1388D4;
  *(uint32_t *)off_1388CC |= 4u;
  *v11 = *v10;
  *v10 = (HIWORD(*v10) << 16) | 0x5DC;
  v2[1] |= 0x20u;
  rf_bus_mark_n_3b7(4u, 1);
  v12 = *(uint32_t *)(*(uint32_t *)v1 + 360);
  if ( v12 )
  {
    v13 = *(unsigned __int16 *)(*(uint32_t *)v1 + 364);
    if ( v13 <= 0xC8 )
      sub_14380C(dword_1388D8, v12, v13);
  }
  return sub_1383E0();
}

