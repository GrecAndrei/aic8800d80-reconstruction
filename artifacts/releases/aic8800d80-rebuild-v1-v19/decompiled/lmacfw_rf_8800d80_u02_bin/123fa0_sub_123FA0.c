// sub_123FA0 @ 0x123fa0, size 14 bytes
int __fastcall sub_123FA0(int result)
{
  *(_DWORD *)off_123FB0 = *(_DWORD *)off_123FB0 & 0xFFFFFFFE | result;
  return result;
}

