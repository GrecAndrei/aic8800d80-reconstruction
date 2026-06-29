// fwstruct annotate: 11dc3c_sub_11DC3C.c
// sub_11DC3C @ 0x11dc3c, size 34 bytes
int sub_11DC3C()
{
  _BYTE *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = off_11DC60;
  init_global_table_121E430();
  v1 = bt_xtal_init_check(v0);
  v2 = sub_12F74C(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return bt_core_subsystems_init();
}

