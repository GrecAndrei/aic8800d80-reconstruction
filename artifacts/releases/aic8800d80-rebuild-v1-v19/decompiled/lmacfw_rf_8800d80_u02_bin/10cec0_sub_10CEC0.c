// sub_10CEC0 @ 0x10cec0, size 34 bytes
int sub_10CEC0()
{
  int v0; // r3
  int result; // r0

  v0 = *(_DWORD *)off_10CEE8 + 4 * (*((unsigned __int8 *)off_10CEE4 + 16) + 136);
  *(_DWORD *)off_10CEEC = 32;
  result = *(_DWORD *)(v0 + 4);
  if ( result )
    return 1;
  *(_DWORD *)off_10CEF0 = 32;
  return result;
}

