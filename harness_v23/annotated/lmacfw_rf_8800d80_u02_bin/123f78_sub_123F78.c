// v23 annotated: sub_123F78 @ 0x123f78
// Original: 123f78_sub_123F78.c
// Primary struct: <unclustered>
//
// sub_123F78 @ 0x123f78, size 16 bytes
int __fastcall sub_123F78(int result)
{
  *(_DWORD *)off_123F88 = *(_DWORD *)off_123F88 & 0xFFEFFFFF | (result << 20);
  return result;
}

