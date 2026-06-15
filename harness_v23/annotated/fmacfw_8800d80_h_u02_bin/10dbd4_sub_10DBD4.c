// v23 annotated: sub_10DBD4 @ 0x10dbd4
// Original: 10dbd4_sub_10DBD4.c
// Primary struct: <unclustered>
//
// sub_10DBD4 @ 0x10dbd4, size 18 bytes
int __fastcall sub_10DBD4(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DBE8 &= ~result;
  return result;
}

