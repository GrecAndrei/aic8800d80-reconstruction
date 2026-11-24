// sub_1035E8 @ 0x1035e8, size 66 bytes
int __fastcall sub_1035E8(int a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r0
  _DWORD *v6; // r1
  _DWORD *v7; // r2
  int v8; // r2
  int v9; // r3

  v5 = off_103630;
  v6 = off_103634;
  v7 = off_103638;
  *(_DWORD *)off_10362C &= 0xFFFFFA53;
  *v5 &= ~0x20000u;
  *v6 &= ~0x1000000u;
  *v7 &= 0xFFE7FFFF;
  delay_us(10);
  return sub_11F74C(0x2000, dword_10363C, v8, v9, a5);
}

