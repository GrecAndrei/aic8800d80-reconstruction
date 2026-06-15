// sub_10DB78 @ 0x10db78, size 18 bytes
int __fastcall sub_10DB78(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DB8C + 2) &= ~result;
  return result;
}

