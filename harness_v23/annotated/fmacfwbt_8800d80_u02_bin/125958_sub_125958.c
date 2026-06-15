// v23 annotated: sub_125958 @ 0x125958
// Original: 125958_sub_125958.c
// Primary struct: <unclustered>
//
// sub_125958 @ 0x125958, size 58 bytes
// Doc: sub_1225958 [util]: Initialize control structure via memset then call sub-init helper
// sub_1225958 [util]: Initialize control structure via memset then call sub-init helper
int sub_125958()
{
  int v0; // r5
  int v1; // r4

  v0 = dword_125994;
  v1 = dword_125998;
  memset_thunk((int *)dword_125994, 0, 0x18u);
  bt_xtal_init_check(v0 + 12);
  sub_12ADD4(v1);
  sub_12ADD4(v1 + 38);
  sub_12ADD4(v1 + 76);
  return sub_12ADD4(v1 + 114);
}

