// fwstruct annotate: 10d054_sub_10D054.c
// sub_10D054 @ 0x10d054, size 26 bytes
// Doc: sub_120D054 [mmio]: Store context pointer and initialize MMIO register base
// sub_120D054 [mmio]: Store context pointer and initialize MMIO register base
int __fastcall sub_10D054(int a1, int a2, int a3)
{
  int result; // r0
  _DWORD *v5; // r3

  result = sub_12ECB0(dword_10D070, a1, a3);
  v5 = off_10D078;
  *(_DWORD *)off_10D074 = a1;
  *v5 = 0x1000000;
  return result;
}

