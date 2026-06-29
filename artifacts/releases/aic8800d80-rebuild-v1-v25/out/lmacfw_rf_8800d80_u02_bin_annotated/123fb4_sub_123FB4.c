// fwstruct annotate: 123fb4_sub_123FB4.c
// sub_123FB4 @ 0x123fb4, size 16 bytes
int __fastcall sub_123FB4(int result)
{
  *(_DWORD *)off_123FC4 = *(_DWORD *)off_123FC4 & 0xF0FFFFFF | (result << 24);
  return result;
}

