// sub_130DE8 @ 0x130de8, size 40 bytes
unsigned __int8 *__fastcall sub_130DE8(_BYTE *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0

  result = sub_12DB60(a1, a2);
  if ( result )
  {
    *(_WORD *)(a3 + 228) = *(_DWORD *)(result + 0x8) | (*(_DWORD *)(result + 0xc) << 8);
    *(_BYTE *)(a3 + 230) = *(_DWORD *)(result + 0x10);
  }
  else
  {
    *(_BYTE *)(a3 + 230) = 0;
    *(_WORD *)(a3 + 228) = 0;
  }
  return result;
}

