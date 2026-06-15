// v23 annotated: bt_data_init_n0c8 @ 0x114754
// Original: 114754_bt_data_init_n0c8.c
// Primary struct: <unclustered>
//
// bt_data_init_n0c8 @ 0x114754, size 52 bytes
// Doc: bt_data_init_n0c8 [bt]: initialize BT data structures at 0x18254c/0x187ffc
// bt_data_init_n0c8 [bt]: initialize BT data structures at 0x18254c/0x187ffc
int bt_data_init_n0c8()
{
  int v0; // r4
  int v1; // r5

  v0 = dword_114788;
  v1 = dword_114788 + 8;
  bt_xtal_init_check(dword_114788);
  bt_xtal_init_check(v1);
  list_push_tail(v1);
  list_push_tail(v1);
  return bt_xtal_init_check(v0 + 16);
}

