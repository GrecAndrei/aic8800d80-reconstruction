// v23 annotated: bt_init_entry @ 0x114914
// Original: 114914_bt_init_entry.c
// Primary struct: <unclustered>
//
// bt_init_entry @ 0x114914, size 36 bytes
// Doc: bt_init_entry [bt]: Initializes BT subsystem entry with defaults
// bt_init_entry [bt]: Initializes BT subsystem entry with defaults
int bt_init_entry()
{
  int v0; // r1
  int v1; // r2

  sub_114C98(0, 0, dword_114938, dword_11493C, 1);
  bt_data_init_n0c8();
  return sub_12ECB0(dword_114940, v0, v1);
}

