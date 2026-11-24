// sub_1324B4 @ 0x1324b4, size 26 bytes
int __fastcall sub_1324B4(unsigned __int8 *a1)
{
  if ( *(_DWORD *)(a1 + 0xc) )
    return 3;
  if ( *(_DWORD *)(a1 + 0x8) )
    return 2;
  return *(_DWORD *)(a1 + 0x4) != 0;
}

