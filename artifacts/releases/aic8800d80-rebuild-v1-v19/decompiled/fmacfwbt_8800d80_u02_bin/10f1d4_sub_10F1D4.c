// sub_10F1D4 @ 0x10f1d4, size 48 bytes
// Doc: sub_120F1D4 [util]: Initialize config struct fields and call sub
// sub_120F1D4 [util]: Initialize config struct fields and call sub
int sub_10F1D4()
{
  _BYTE *v0; // r4
  char *v1; // r0

  v0 = off_10F204;
  v1 = (char *)off_10F204 + 1624;
  *((_WORD *)off_10F204 + 810) = 80;
  v0[1622] = 81;
  bt_xtal_init_check(v1);
  *((_WORD *)v0 + 1216) = 39;
  v0[2434] = 40;
  return bt_xtal_init_check(v0 + 2436);
}

