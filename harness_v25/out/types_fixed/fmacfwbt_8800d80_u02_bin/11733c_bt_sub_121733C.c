// bt_sub_121733C @ 0x11733c, size 52 bytes
// Doc: sub_1217348 [util]: Wrapper that forwards to handler at 0x128744
// sub_1217348 [util]: Wrapper that forwards to handler at 0x128744
BOOL __fastcall bt_sub_121733C(int a1)
{
  if ( *((_BYTE *)off_117370 + 510) )
    return 0;
  if ( !sub_128744() )
    return 0;
  if ( *(_BYTE *)(a1 + 1224) )
    return mac_txq_flag_get(*(unsigned __int8 *)(a1 + 1225)) != 0;
  return 1;
}

