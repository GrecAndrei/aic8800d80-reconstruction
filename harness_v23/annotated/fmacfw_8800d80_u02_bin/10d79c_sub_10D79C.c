// v23 annotated: sub_10D79C @ 0x10d79c
// Original: 10d79c_sub_10D79C.c
// Primary struct: <unclustered>
//
// sub_10D79C @ 0x10d79c, size 14 bytes
int __fastcall sub_10D79C(int result)
{
  while ( (*(_DWORD *)off_10D7AC & 0x80000) != 0 )
    ;
  *(_DWORD *)off_10D7B0 = result;
  return result;
}

