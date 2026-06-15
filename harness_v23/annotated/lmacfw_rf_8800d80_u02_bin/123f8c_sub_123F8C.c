// v23 annotated: sub_123F8C @ 0x123f8c
// Original: 123f8c_sub_123F8C.c
// Primary struct: <unclustered>
//
// sub_123F8C @ 0x123f8c, size 16 bytes
int __fastcall sub_123F8C(int result)
{
  *(_DWORD *)off_123F9C = *(_DWORD *)off_123F9C & 0xFFDFFFFF | (result << 21);
  return result;
}

