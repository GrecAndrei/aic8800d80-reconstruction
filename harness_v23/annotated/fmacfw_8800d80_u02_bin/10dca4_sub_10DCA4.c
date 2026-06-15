// v23 annotated: sub_10DCA4 @ 0x10dca4
// Original: 10dca4_sub_10DCA4.c
// Primary struct: <unclustered>
//
// sub_10DCA4 @ 0x10dca4, size 42 bytes
int __fastcall sub_10DCA4(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DCD0;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

