// fwstruct annotate: 10f37c_sub_10F37C.c
// sub_10F37C @ 0x10f37c, size 48 bytes
int sub_10F37C()
{
  _BYTE *v0; // r4
  char *v1; // r0

  v0 = off_10F3AC;
  v1 = (char *)off_10F3AC + 1624;
  *((_WORD *)off_10F3AC + 810) = 80;
  v0[1622] = 81;
  sub_12D240(v1);
  *((_WORD *)v0 + 1216) = 39;
  v0[2434] = 40;
  return sub_12D240(v0 + 2436);
}

