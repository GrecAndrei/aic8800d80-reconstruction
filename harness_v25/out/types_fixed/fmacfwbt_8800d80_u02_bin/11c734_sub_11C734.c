// sub_11C734 @ 0x11c734, size 24 bytes
void __fastcall sub_11C734(int a1)
{
  _BYTE *v1; // r4

  v1 = off_11C74C;
  *(_BYTE *)off_11C74C = 1;
  sub_11F03C(a1);
  *v1 = 0;
  sub_11BE18();
}

