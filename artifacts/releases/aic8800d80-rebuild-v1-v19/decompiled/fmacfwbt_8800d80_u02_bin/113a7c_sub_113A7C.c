// sub_113A7C @ 0x113a7c, size 28 bytes
int __fastcall sub_113A7C(int a1)
{
  _BYTE *v1; // r2
  char v2; // r3

  sub_113918(a1);
  v1 = off_113AA0;
  v2 = *((_BYTE *)off_113A98 + 352);
  *(_BYTE *)off_113A9C = *((_BYTE *)off_113A98 + 326);
  *v1 = v2;
  return 1;
}

