// v23 annotated: sub_122810 @ 0x122810
// Original: 122810_sub_122810.c
// Primary struct: <unclustered>
//
// sub_122810 @ 0x122810, size 30 bytes
int __fastcall sub_122810(char a1, char a2)
{
  _BYTE *v4; // r0

  v4 = (_BYTE *)rf_bus_setup_n3a8(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return sub_12CBB4(v4);
}

