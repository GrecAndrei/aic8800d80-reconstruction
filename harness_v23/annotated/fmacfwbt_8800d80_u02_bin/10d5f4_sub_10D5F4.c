// v23 annotated: sub_10D5F4 @ 0x10d5f4
// Original: 10d5f4_sub_10D5F4.c
// Primary struct: <unclustered>
//
// sub_10D5F4 @ 0x10d5f4, size 14 bytes
int __fastcall sub_10D5F4(int result)
{
  while ( (*(_DWORD *)off_10D604 & 0x80000) != 0 )
    ;
  *(_DWORD *)off_10D608 = result;
  return result;
}

