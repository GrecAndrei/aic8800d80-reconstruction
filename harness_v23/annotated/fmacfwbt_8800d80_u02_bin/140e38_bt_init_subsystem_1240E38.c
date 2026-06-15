// v23 annotated: bt_init_subsystem_1240E38 @ 0x140e38
// Original: 140e38_bt_init_subsystem_1240E38.c
// Primary struct: <unclustered>
//
// bt_init_subsystem_1240E38 @ 0x140e38, size 36 bytes
// Doc: bt_init_subsystem_1240E38 [bt]: Init BT subsystem: load 0x198000, call 0x12cf5c with id 0xb, init 0x1960 region
// bt_init_subsystem_1240E38 [bt]: Init BT subsystem: load 0x198000, call 0x12cf5c with id 0xb, init 0x1960 region
int *bt_init_subsystem_1240E38()
{
  int *v0; // r4
  int *result; // r0

  v0 = (int *)dword_140E5C;
  rf_bus_mark_n_3b7(0xBu, 0);
  result = memset_thunk(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}

