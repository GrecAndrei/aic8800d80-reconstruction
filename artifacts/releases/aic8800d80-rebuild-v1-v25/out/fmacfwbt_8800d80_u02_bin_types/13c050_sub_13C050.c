// sub_13C050 @ 0x13c050, size 222 bytes
int  sub_13C050(int a1, int a2, __int16 a3)
{
  int v6; // r0
  char v7; // r11
  uint32_t *v8; // r8
  int v9; // r4
  __int16 v10; // r6
  char v11; // r0
  __int16 v12; // r12
  int v13; // r2
  bool v14; // zf
  __int16 v15; // r0
  int v16; // r7
  int v17; // r2
  unsigned __int16 v18; // r6

  v6 = sub_13C014();
  v7 = v6;
  if ( (unsigned __int8)v6 == 33 )
    return 3;
  v8 = off_13C13C;
  v9 = dword_13C130 + 32 * (unsigned __int8)v6;
  v10 = v6;
  *(uint8_t *)(v9 + 22) = a2;
  *(uint8_t *)(v9 + 16) = a1;
  v11 = sub_143A18(v6);
  v13 = dword_13C134;
  *(uint8_t *)(v9 + 23) = v11;
  v14 = (*(uint32_t *)(v13 + 696 * a1 + 4) & 0x20) == 0;
  v15 = *(uint16_t *)(*(uint32_t *)off_13C138 + 2);
  *(uint8_t *)(v9 + 18) = 1;
  *(uint8_t *)(v9 + 17) = 1;
  *(uint32_t *)(v9 + 4) = 0;
  v16 = v13 + 696 * a1 + 12 * a2;
  if ( !v14 )
    v12 = 256;
  v17 = v8[4];
  if ( v14 )
    v12 = 64;
  *(uint16_t *)(v9 + 20) = v12;
  *(uint16_t *)(v9 + 14) = v15;
  *(uint32_t *)(v9 + 8) = v17;
  *(uint16_t *)(v9 + 12) = a3;
  *(uint8_t *)(v16 + 453) = v7;
  rf_bus_write_n_25c(a1, v9, 2, 0, 0, 39, 0);
  v18 = (v10 << 8) | 8;
  rf_bus_write_n_25c(a1, v9, 0, 0, 0, 0, 0);
  *(uint32_t *)(v16 + 444) = v8[4];
  rf_level_apply_80c(0x2000, v18, 0x7D000u);
  rf_bus_mark_n_3b7(v18, 2);
  return 0;
}

