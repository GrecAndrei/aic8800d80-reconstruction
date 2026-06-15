// v23 annotated: sub_136870 @ 0x136870
// Original: 136870_sub_136870.c
// Primary struct: <unclustered>
//
// sub_136870 @ 0x136870, size 28 bytes
// Doc: sub_1236870 [util]: Initialize/zero a 16-byte control structure via memset
// sub_1236870 [util]: Initialize/zero a 16-byte control structure via memset
_DWORD *sub_136870()
{
  _BYTE *v0; // r4

  v0 = off_13688C;
  memset_thunk((int *)off_13688C, 0, 0x10u);
  v0[12] = 0;
  return rf_bus_mark_n_3b7(7u, 0);
}

