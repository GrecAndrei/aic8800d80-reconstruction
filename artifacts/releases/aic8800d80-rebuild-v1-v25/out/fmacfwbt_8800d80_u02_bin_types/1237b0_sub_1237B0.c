// sub_1237B0 @ 0x1237b0, size 80 bytes
int  sub_1237B0(int a1, unsigned __int8 *a2)
{
  uint8_t *v3; // r0
  uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (uint8_t *)rf_bus_setup_n3a8(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(uint8_t *)(dword_123800 + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    sub_12A74C();
LABEL_5:
    sub_12CBB4(v4);
    return 0;
  }
  rf_table_lookup_n788();
  sub_12CBB4(v4);
  return 0;
}

