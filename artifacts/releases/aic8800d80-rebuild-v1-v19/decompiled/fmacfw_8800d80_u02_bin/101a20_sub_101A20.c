// sub_101A20 @ 0x101a20, size 20 bytes
unsigned int __fastcall sub_101A20(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_101A34 & 0xFFFFFFF7;
  *(_DWORD *)off_101A34 = result;
  return result;
}

