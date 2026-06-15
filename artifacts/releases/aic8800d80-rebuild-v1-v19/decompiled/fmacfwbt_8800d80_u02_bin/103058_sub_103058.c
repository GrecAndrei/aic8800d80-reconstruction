// sub_103058 @ 0x103058, size 78 bytes
unsigned int __fastcall sub_103058(unsigned int result)
{
  if ( result )
  {
    if ( *((_BYTE *)off_1030A8 + 362) )
      result = sub_1029F8(0xB5u);
    *(_DWORD *)off_1030AC |= 2u;
  }
  else
  {
    if ( *((_BYTE *)off_1030A8 + 362) )
      result = sub_1029F8(0xC2u);
    *(_DWORD *)off_1030AC &= ~2u;
  }
  return result;
}

