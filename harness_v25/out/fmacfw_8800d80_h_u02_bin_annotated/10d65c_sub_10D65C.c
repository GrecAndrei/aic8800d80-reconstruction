// fwstruct annotate: 10d65c_sub_10D65C.c
// sub_10D65C @ 0x10d65c, size 14 bytes
int __fastcall sub_10D65C(int result)
{
  while ( (*(_DWORD *)off_10D66C & 0x80000) != 0 )
    ;
  *(_DWORD *)off_10D670 = result;
  return result;
}

