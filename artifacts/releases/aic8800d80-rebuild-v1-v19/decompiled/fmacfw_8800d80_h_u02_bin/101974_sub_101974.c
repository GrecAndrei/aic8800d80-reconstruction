// sub_101974 @ 0x101974, size 20 bytes
unsigned int __fastcall sub_101974(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_101988 & 0xFFFFFFF7;
  *(_DWORD *)off_101988 = result;
  return result;
}

