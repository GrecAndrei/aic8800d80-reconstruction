// sub_132810 @ 0x132810, size 26 bytes
int __fastcall sub_132810(unsigned __int8 *a1)
{
  if ( *(_DWORD *)(a1 + 0xc) )
    return 3;
  if ( *(_DWORD *)(a1 + 0x8) )
    return 2;
  return *(_DWORD *)(a1 + 0x4) != 0;
}

