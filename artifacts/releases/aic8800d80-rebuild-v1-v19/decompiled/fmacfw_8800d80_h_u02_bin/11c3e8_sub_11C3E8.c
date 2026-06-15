// sub_11C3E8 @ 0x11c3e8, size 26 bytes
int __fastcall sub_11C3E8(int a1)
{
  _DWORD *v1; // r3
  int v2; // r1

  v1 = off_11C408;
  v2 = *((_DWORD *)off_11C404 + 4);
  *((_DWORD *)off_11C408 + 1) = dword_11C40C;
  v1[2] = a1;
  return sub_124BFC(v1, v2 + 5000);
}

