// v23 annotated: sub_12B394 @ 0x12b394
// Original: 12b394_sub_12B394.c
// Primary struct: <unclustered>
//
// sub_12B394 @ 0x12b394, size 40 bytes
int sub_12B394()
{
  int result; // r0
  _DWORD *v1; // r3

  memset_thunk((int *)dword_12B3BC, 0, 0xCu);
  result = rf_bus_mark_n_3b7(2);
  v1 = off_12B3C0;
  *(_DWORD *)off_12B3C0 = dword_12B3C4;
  v1[2] = v1 + 5;
  v1[4] = 0;
  v1[1] = 0;
  return result;
}

