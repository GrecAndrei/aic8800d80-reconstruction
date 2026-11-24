// sub_10DB94 @ 0x10db94, size 18 bytes
int __fastcall sub_10DB94(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DBA8 + 2) &= ~result;
  return result;
}

