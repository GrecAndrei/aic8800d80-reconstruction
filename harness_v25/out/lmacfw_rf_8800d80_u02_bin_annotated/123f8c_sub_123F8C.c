// fwstruct annotate: 123f8c_sub_123F8C.c
// sub_123F8C @ 0x123f8c, size 16 bytes
int __fastcall sub_123F8C(int result)
{
  *(_DWORD *)off_123F9C = *(_DWORD *)off_123F9C & 0xFFDFFFFF | (result << 21);
  return result;
}

