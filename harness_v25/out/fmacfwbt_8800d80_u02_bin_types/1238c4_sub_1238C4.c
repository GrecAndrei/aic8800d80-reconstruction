// sub_1238C4 @ 0x1238c4, size 54 bytes
// Doc: sub_12238C4 [unknown]: Bridge helper forwarding args to 0x127d80
// sub_12238C4 [unknown]: Bridge helper forwarding args to 0x127d80
int  sub_1238C4(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = sub_127D80(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)rf_bus_setup_n3a8(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_12CBB4(v10);
  }
  return 0;
}

