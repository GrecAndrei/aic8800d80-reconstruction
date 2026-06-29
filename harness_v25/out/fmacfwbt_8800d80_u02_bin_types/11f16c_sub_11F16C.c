// sub_11F16C @ 0x11f16c, size 248 bytes
// Doc: sub_121F16C [rf]: Initialize RF subsystem state with global pointers
// sub_121F16C [rf]: Initialize RF subsystem state with global pointers
int *sub_11F16C()
{
  int v0; // r5
  int v1; // r7
  int v2; // r6
  int v3; // r4
  int v4; // r0
  int i; // r5
  int v6; // r4
  int v7; // r0
  uint32_t *v8; // r4
  int v9; // r6
  int v10; // r5
  int v11; // r3
  int *result; // r0
  int v13; // r3

  v0 = dword_11F268;
  v1 = dword_11F264;
  bt_xtal_init_check(dword_11F264);
  v2 = v0 + 22272;
  do
  {
    rf_phy_field_clear_n_23c(v0 - 624);
    list_push_tail(v1);
    v3 = v0 - 40;
    do
    {
      bt_xtal_init_check(v3);
      v4 = v3 + 40;
      v3 += 8;
      bt_xtal_init_check(v4);
    }
    while ( v3 != v0 );
    v0 = v3 + 696;
  }
  while ( v3 + 696 != v2 );
  for ( i = 2784; i != 3132; i += 87 )
  {
    v6 = v2 - 40;
    do
    {
      bt_xtal_init_check(v6);
      v7 = v6 + 40;
      v6 += 8;
      bt_xtal_init_check(v7);
    }
    while ( v6 != v2 );
    v2 = v6 + 696;
  }
  v8 = off_11F26C;
  v9 = dword_11F270;
  v10 = dword_11F274;
  rf_phy_field_clear_n_23c((int)off_11F26C);
  v8[8] = 0x20000000;
  v8[84] = v9;
  v8[47] = v10;
  *((uint8_t *)v8 + 52) = 0;
  rf_phy_field_clear_n_23c((int)(v8 + 174));
  v8[258] = v9 + 64;
  v11 = dword_11F278;
  v8[221] = v10 + 1320;
  v8[182] = v11;
  *((uint8_t *)v8 + 748) = 0;
  rf_phy_field_clear_n_23c((int)(v8 + 348));
  v8[432] = v9 + 128;
  v8[356] = dword_11F27C;
  *((uint8_t *)v8 + 1444) = 0;
  v8[395] = v10 + 2640;
  result = rf_phy_field_clear_n_23c((int)(v8 + 522));
  v13 = dword_11F280;
  *((uint8_t *)v8 + 2140) = 0;
  v8[606] = v9 + 192;
  v8[569] = v10 + 3960;
  v8[530] = v13;
  return result;
}

