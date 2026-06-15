// v23 annotated: sub_141EF8 @ 0x141ef8
// Original: 141ef8_sub_141EF8.c
// Primary struct: <unclustered>
//
// sub_141EF8 @ 0x141ef8, size 30 bytes
int __fastcall sub_141EF8(int a1)
{
  int result; // r0
  _BYTE *v3; // r2
  char v4; // r3

  result = sub_141D94(a1);
  v3 = off_141F18;
  *(_WORD *)a1 &= ~1u;
  v4 = *v3 - 1;
  *(_BYTE *)(a1 + 2) = 0;
  *v3 = v4;
  return result;
}

