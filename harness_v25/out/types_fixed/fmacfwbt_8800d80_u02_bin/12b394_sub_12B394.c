// sub_12B394 @ 0x12b394, size 40 bytes
int sub_12B394()
{
  int result; // r0
  _DWORD *v1; // r3

  memset_thunk((int *)dword_12B3BC, 0, 0xCu);
  result = rf_bus_mark_n_3b7(2);
  v1 = off_12B3C0;
  *(_DWORD *)off_12B3C0 = dword_12B3C4;
  *(_DWORD *)(v1 + 0x8) = v1 + 5;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  return result;
}

