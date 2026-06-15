// sub_11E4C0 @ 0x11e4c0, size 44 bytes
unsigned int __fastcall sub_11E4C0(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_11E4F0;
  *(_DWORD *)off_11E4EC = (a1 << 10) & 0x400 | *(_DWORD *)off_11E4EC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

