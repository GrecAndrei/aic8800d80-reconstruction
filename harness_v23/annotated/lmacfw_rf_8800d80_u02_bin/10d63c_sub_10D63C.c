// v23 annotated: sub_10D63C @ 0x10d63c
// Original: 10d63c_sub_10D63C.c
// Primary struct: <unclustered>
//
// sub_10D63C @ 0x10d63c, size 14 bytes
int __fastcall sub_10D63C(int result)
{
  while ( (*(_DWORD *)off_10D64C & 0x80000) != 0 )
    ;
  *(_DWORD *)off_10D650 = result;
  return result;
}

