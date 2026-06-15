// v23 annotated: sub_1032DC @ 0x1032dc
// Original: 1032dc_sub_1032DC.c
// Primary struct: <unclustered>
//
// sub_1032DC @ 0x1032dc, size 78 bytes
unsigned int __fastcall sub_1032DC(unsigned int result)
{
  if ( result )
  {
    if ( *((_BYTE *)off_10332C + 362) )
      result = sub_1029DC(0xB5u);
    *(_DWORD *)off_103330 |= 2u;
  }
  else
  {
    if ( *((_BYTE *)off_10332C + 362) )
      result = sub_1029DC(0xC2u);
    *(_DWORD *)off_103330 &= ~2u;
  }
  return result;
}

