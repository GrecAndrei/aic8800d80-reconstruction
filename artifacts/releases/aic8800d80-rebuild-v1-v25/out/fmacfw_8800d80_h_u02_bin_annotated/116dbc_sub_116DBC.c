// fwstruct annotate: 116dbc_sub_116DBC.c
// sub_116DBC @ 0x116dbc, size 52 bytes
BOOL __fastcall sub_116DBC(int a1)
{
  if ( *((_BYTE *)off_116DF0 + 510) )
    return 0;
  if ( !sub_1283E0() )
    return 0;
  if ( *(_BYTE *)(a1 + 1224) )
    return sub_129FEC(*(unsigned __int8 *)(a1 + 1225)) != 0;
  return 1;
}

