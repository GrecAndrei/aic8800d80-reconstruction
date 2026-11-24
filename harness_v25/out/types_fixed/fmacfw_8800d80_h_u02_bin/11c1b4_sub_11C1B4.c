// sub_11C1B4 @ 0x11c1b4, size 24 bytes
void __fastcall sub_11C1B4(int a1)
{
  _BYTE *v1; // r4

  v1 = off_11C1CC;
  *(_BYTE *)off_11C1CC = 1;
  sub_11EABC(a1);
  *v1 = 0;
  sub_11B898();
}

