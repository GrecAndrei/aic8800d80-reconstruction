// sub_116D10 @ 0x116d10, size 30 bytes
int __fastcall sub_116D10(int result)
{
  int v1; // r4

  if ( *(_WORD *)(result + 4) )
  {
    v1 = result;
    result = *(_DWORD *)(result + 72);
    if ( result )
    {
      if ( (*(_DWORD *)(v1 + 36) & 0x200000) == 0 )
      {
        result = sub_10FEC8((_DWORD *)result);
        *(_DWORD *)(v1 + 72) = 0;
      }
    }
  }
  return result;
}

