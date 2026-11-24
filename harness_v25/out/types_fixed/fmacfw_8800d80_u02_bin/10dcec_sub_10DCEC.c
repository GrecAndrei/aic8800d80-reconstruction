// sub_10DCEC @ 0x10dcec, size 16 bytes
int __fastcall sub_10DCEC(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DCFC + 2);
  *((_DWORD *)off_10DCFC + 2) = result;
  return result;
}

