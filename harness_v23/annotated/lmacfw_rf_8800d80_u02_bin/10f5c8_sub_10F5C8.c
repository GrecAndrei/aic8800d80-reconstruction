// v23 annotated: sub_10F5C8 @ 0x10f5c8
// Original: 10f5c8_sub_10F5C8.c
// Primary struct: <unclustered>
//
// sub_10F5C8 @ 0x10f5c8, size 48 bytes
// Doc: sub_120F5C8 [rf]: lmacfw RF initialization subroutine, stores bytes and calls helper
// sub_120F5C8 [rf]: lmacfw RF initialization subroutine, stores bytes and calls helper
int sub_10F5C8()
{
  _BYTE *v0; // r4
  char *v1; // r0

  v0 = off_10F5F8;
  v1 = (char *)off_10F5F8 + 1624;
  *((_WORD *)off_10F5F8 + 810) = 80;
  v0[1622] = 81;
  sub_11E71C(v1);
  *((_WORD *)v0 + 1216) = 39;
  v0[2434] = 40;
  return sub_11E71C(v0 + 2436);
}

