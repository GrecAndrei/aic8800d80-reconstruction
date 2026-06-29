// sub_134DEC @ 0x134dec, size 428 bytes
uint32_t *sub_134DEC()
{
  int v0; // r10
  int v1; // r5
  uint8_t *v2; // r9
  int v3; // r7
  int v4; // r4
  int v5; // r6
  int v6; // r11
  uint8_t *v7; // r8
  int v8; // r0
  void *v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r6
  int v14; // r6
  int v15; // r7
  int *v16; // r10
  int v17; // r0
  int v18; // t1
  int v19; // r0
  int *v21; // r6
  int v22; // [sp+0h] [bp-Ch]

  v0 = dword_134FA4;
  v1 = *((uint32_t *)off_134F98 + 4);
  v22 = *(unsigned __int8 *)(v1 + 61);
  v2 = (uint8_t *)rf_bus_setup_n3a8(5145, 5, 6, 2u);
  v3 = rf_bus_setup_n3a8(24, 0, 6, 8u);
  v4 = 1320 * v22;
  v5 = rf_bus_setup_n3a8(22, 0, 6, 8u);
  v6 = rf_bus_setup_n3a8(20, 0, 6, 4u);
  v7 = (uint8_t *)rf_bus_setup_n3a8(5143, 5, 6, 2u);
  sub_134608();
  *v2 = 1;
  v2[1] = *(uint8_t *)(v1 + 61);
  list_push_tail((int)off_134F98 + 24, (uint32_t *)v2 - 3);
  v8 = *(uint32_t *)(v0 + 1320 * v22 + 368);
  *(uint16_t *)(v3 + 4) = *(uint16_t *)(v0 + 1320 * v22 + 372);
  v9 = off_134F98;
  *(uint32_t *)v3 = v8;
  *(uint8_t *)(v3 + 6) = *(uint8_t *)(v1 + 61);
  list_push_tail((int)v9 + 24, (uint32_t *)(v3 - 12));
  *(uint8_t *)(v5 + 5) = *(uint8_t *)(v0 + 1320 * v22 + 412);
  v10 = sub_1329B0((unsigned __int8 *)(1320 * v22 + 424 + v0), 1);
  v11 = *(unsigned __int8 *)(v5 + 5);
  *(uint32_t *)v5 = v10;
  *(uint8_t *)(v5 + 4) = *(uint8_t *)(v1 + 61);
  if ( !v11 )
  {
    if ( (v10 & 1) != 0 )
    {
      *((uint32_t *)off_134F9C + 5) = 1024;
    }
    else if ( (v10 & 0x10) != 0 )
    {
      *((uint32_t *)off_134F9C + 5) = 4;
    }
  }
  list_push_tail(dword_134FA0, (uint32_t *)(v5 - 12));
  v12 = dword_134FA0;
  v13 = v0 + 1320 * v22;
  *(uint16_t *)v6 = *(uint16_t *)(v13 + 422);
  *(uint8_t *)(v6 + 2) = *(uint8_t *)(v1 + 61);
  list_push_tail(v12, (uint32_t *)(v6 - 12));
  if ( (*(uint32_t *)(v13 + 472) & 8) != 0 )
  {
    v21 = (int *)rf_bus_setup_n3a8(113, 0, 6, 4u);
    *v21 = sub_132AA0(v0 + v4 + 248);
    list_push_tail(dword_134FA0, v21 - 3);
  }
  v14 = 0;
  v15 = dword_134FA0;
  v16 = (int *)(v0 + v4 + 440);
  do
  {
    v17 = rf_bus_setup_n3a8(26, 0, 6, 8u);
    v18 = *v16++;
    *(uint32_t *)v17 = v18;
    *(uint8_t *)(v17 + 5) = v14;
    *(uint8_t *)(v17 + 6) = *(uint8_t *)(v1 + 61);
    *(uint8_t *)(v17 + 4) = 0;
    ++v14;
    list_push_tail(v15, (uint32_t *)(v17 - 12));
  }
  while ( v14 != 4 );
  *v7 = 1;
  v19 = dword_134FA0;
  v7[1] = *(uint8_t *)(v1 + 61);
  list_push_tail(v19, (uint32_t *)v7 - 3);
  sub_1349D8();
  return rf_bus_mark_n_3b7(6u, 4);
}

