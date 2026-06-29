// sub_1369C0 @ 0x1369c0, size 280 bytes
uint32_t *sub_1369C0()
{
  int v0; // r11
  int v1; // r4
  int v2; // r9
  int v3; // r6
  int v4; // r5
  int v5; // r8
  int v6; // r10
  uint8_t *v7; // r7
  int v8; // r9
  int v9; // r0
  int v10; // r0
  uint8_t *v12; // r0

  v0 = dword_136AE4;
  v1 = *(uint32_t *)off_136AD8;
  v2 = *(unsigned __int8 *)(*(uint32_t *)off_136AD8 + 51);
  v3 = rf_bus_setup_n3a8(24, 0, 7, 8u);
  v4 = rf_bus_setup_n3a8(22, 0, 7, 8u);
  v5 = rf_bus_setup_n3a8(20, 0, 7, 4u);
  v6 = v0 + 1320 * v2;
  v7 = (uint8_t *)rf_bus_setup_n3a8(5143, 5, 7, 2u);
  sub_136828();
  if ( *(uint8_t *)(v6 + 1224) )
  {
    *(uint32_t *)off_136ADC &= ~4u;
    *(uint32_t *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v12 = (uint8_t *)rf_bus_setup_n3a8(5145, 5, 7, 2u);
    *v12 = 1;
    v12[1] = *(uint8_t *)(v6 + 107);
    list_push_tail((int)off_136AD8 + 4, (uint32_t *)v12 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(uint32_t *)(v8 + 100);
  *(uint16_t *)(v3 + 4) = *(uint16_t *)(v8 + 104);
  *(uint32_t *)v3 = v9;
  *(uint8_t *)(v3 + 6) = *(uint8_t *)(v1 + 51);
  list_push_tail(dword_136AE0, (uint32_t *)(v3 - 12));
  *(uint8_t *)(v4 + 5) = *(uint8_t *)(v1 + 16);
  *(uint32_t *)v4 = sub_1329B0((unsigned __int8 *)v1, 1);
  *(uint8_t *)(v4 + 4) = *(uint8_t *)(v1 + 51);
  list_push_tail(dword_136AE0, (uint32_t *)(v4 - 12));
  *(uint16_t *)v5 = *(uint16_t *)(v1 + 40);
  *(uint8_t *)(v5 + 2) = *(uint8_t *)(v1 + 51);
  list_push_tail(dword_136AE0, (uint32_t *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136AE0;
  v7[1] = *(uint8_t *)(v1 + 51);
  list_push_tail(v10, (uint32_t *)v7 - 3);
  sub_13697C();
  return rf_bus_mark_n_3b7(7u, 1);
}

