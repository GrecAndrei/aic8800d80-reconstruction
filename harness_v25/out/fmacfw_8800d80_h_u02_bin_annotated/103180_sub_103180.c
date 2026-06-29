// fwstruct annotate: 103180_sub_103180.c
// sub_103180 @ 0x103180, size 78 bytes
unsigned int __fastcall sub_103180(unsigned int result)
{
  if ( result )
  {
    if ( *((_BYTE *)off_1031D0 + 362) )
      result = sub_102AD0(0xB5u);
    *(_DWORD *)off_1031D4 |= 2u;
  }
  else
  {
    if ( *((_BYTE *)off_1031D0 + 362) )
      result = sub_102AD0(0xC2u);
    *(_DWORD *)off_1031D4 &= ~2u;
  }
  return result;
}

