// sub_116DBC @ 0x116dbc, size 52 bytes
BOOL  sub_116DBC(int a1)
{
  if ( *((uint8_t *)off_116DF0 + 510) )
    return 0;
  if ( !sub_1283E0() )
    return 0;
  if ( *(uint8_t *)(a1 + 1224) )
    return sub_129FEC(*(unsigned __int8 *)(a1 + 1225)) != 0;
  return 1;
}

