// v23 annotated: sub_12B3A4 @ 0x12b3a4
// Original: 12b3a4_sub_12B3A4.c
// Primary struct: vif_bssid_ref (cluster 2, 4 funcs)
// Fields: vif=0x0, bssid=0xe
//
// sub_12B3A4 @ 0x12b3a4, size 40 bytes
int __fastcall sub_12B3A4(char a1, int a2)
{
  _BYTE *v3; // r4

  v3 = (_BYTE *)sub_12C7EC(2052, a2, 2, 1);
  sub_12EB90(4, dword_12B3D0);
  *v3 = a1;
  return sub_12C84C(v3);
}

