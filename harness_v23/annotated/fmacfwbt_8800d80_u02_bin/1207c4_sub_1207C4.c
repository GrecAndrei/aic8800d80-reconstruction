// v23 annotated: sub_1207C4 @ 0x1207c4
// Original: 1207c4_sub_1207C4.c
// Primary struct: <unclustered>
//
// sub_1207C4 @ 0x1207c4, size 26 bytes
int __fastcall sub_1207C4(int a1)
{
  _DWORD *v2; // r0

  v2 = (_DWORD *)rf_bus_setup_n3a8(143, 0, 255, 4);
  *v2 = a1;
  return sub_12CBB4(v2);
}

