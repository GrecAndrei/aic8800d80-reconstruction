// sub_123FC8 @ 0x123fc8, size 16 bytes
int __fastcall sub_123FC8(int result)
{
  *(_DWORD *)off_123FD8 = *(_DWORD *)off_123FD8 & 0xFFFEFFFF | (result << 16);
  return result;
}

