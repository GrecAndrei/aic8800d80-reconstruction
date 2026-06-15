// sub_103200 @ 0x103200, size 78 bytes
unsigned int __fastcall sub_103200(unsigned int result)
{
  if ( result )
  {
    if ( *((_BYTE *)off_103250 + 362) )
      result = sub_102B80(0xB5u);
    *(_DWORD *)off_103254 |= 2u;
  }
  else
  {
    if ( *((_BYTE *)off_103250 + 362) )
      result = sub_102B80(0xC2u);
    *(_DWORD *)off_103254 &= ~2u;
  }
  return result;
}

