// sub_12ABC8 @ 0x12abc8, size 22 bytes
int __fastcall sub_12ABC8(int result)
{
  if ( *(_BYTE *)(result + 1224) )
  {
    if ( *(_BYTE *)(result + 108) )
      *(_DWORD *)(result + 4) |= 0x40u;
  }
  return result;
}

