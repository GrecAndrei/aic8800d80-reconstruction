// v23 annotated: sub_11CD0C @ 0x11cd0c
// Original: 11cd0c_sub_11CD0C.c
// Primary struct: <unclustered>
//
// sub_11CD0C @ 0x11cd0c, size 40 bytes
// Doc: sub_121CD0C [util]: Init function calling helper with arg 0x804
// sub_121CD0C [util]: Init function calling helper with arg 0x804
int __fastcall sub_11CD0C(char a1, int a2)
{
  _BYTE *v3; // r4
  int v4; // r3

  v3 = (_BYTE *)rf_setup_dispatch(2052, a2, 2, 1);
  sub_11F74C(4, dword_11CD38, dword_11CD34, v4);
  *v3 = a1;
  return sub_11DE50(v3);
}

