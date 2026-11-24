// sub_13B8E4 @ 0x13b8e4, size 76 bytes
unsigned __int8 *__fastcall sub_13B8E4(int a1)
{
  unsigned __int8 *result; // r0
  int v2; // r1
  int v3; // r3

  result = (unsigned __int8 *)(dword_13B930 + 32 * a1);
  v2 = *(_DWORD *)(result + 0x40);
  v3 = *(_DWORD *)(result + 0x58);
  if ( *(_DWORD *)(result + 0x44) )
  {
    if ( *(_DWORD *)(result + 0x44) == 1 )
      *(_BYTE *)(696 * v2 + 12 * v3 + dword_13B934 + 453) = 33;
  }
  else
  {
    *(_BYTE *)(696 * v2 + 12 * v3 + dword_13B934 + 452) = 33;
  }
  return result;
}

