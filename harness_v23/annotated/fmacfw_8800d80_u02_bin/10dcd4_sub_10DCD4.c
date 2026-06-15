// v23 annotated: sub_10DCD4 @ 0x10dcd4
// Original: 10dcd4_sub_10DCD4.c
// Primary struct: <unclustered>
//
// sub_10DCD4 @ 0x10dcd4, size 18 bytes
int __fastcall sub_10DCD4(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DCE8 + 2) &= ~result;
  return result;
}

