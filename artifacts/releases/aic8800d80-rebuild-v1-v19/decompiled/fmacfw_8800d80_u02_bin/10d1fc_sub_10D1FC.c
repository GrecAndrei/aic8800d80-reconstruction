// sub_10D1FC @ 0x10d1fc, size 26 bytes
int __fastcall sub_10D1FC(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v5; // r3

  result = sub_12EA88(dword_10D218, a1, a3);
  v5 = off_10D220;
  *(_DWORD *)off_10D21C = a1;
  *v5 = 0x1000000;
  return result;
}

