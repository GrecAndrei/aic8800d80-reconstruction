// fwstruct annotate: 113ae0_sub_113AE0.c
// sub_113AE0 @ 0x113ae0, size 28 bytes
int __fastcall sub_113AE0(int a1)
{
  _BYTE *v1; // r2
  char v2; // r3

  sub_11397C(a1);
  v1 = off_113B04;
  v2 = *((_BYTE *)off_113AFC + 352);
  *(_BYTE *)off_113B00 = *((_BYTE *)off_113AFC + 326);
  *v1 = v2;
  return 1;
}

