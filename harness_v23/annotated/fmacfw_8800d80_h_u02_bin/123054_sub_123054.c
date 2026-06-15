// v23 annotated: sub_123054 @ 0x123054
// Original: 123054_sub_123054.c
// Primary struct: <unclustered>
//
// sub_123054 @ 0x123054, size 56 bytes
int __fastcall sub_123054(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned int v5; // r0

  v4 = (_BYTE *)sub_12C7EC(133, a4, a3, 1);
  v5 = sub_10EC44(dword_12308C, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  sub_12E948(dword_123090, v5, HIWORD(v5) & 1);
  sub_12C84C(v4);
  return 0;
}

