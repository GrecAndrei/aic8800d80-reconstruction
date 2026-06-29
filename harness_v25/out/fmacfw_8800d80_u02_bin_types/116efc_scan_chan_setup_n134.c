// scan_chan_setup_n134 @ 0x116efc, size 52 bytes
// Doc: lmac_handler_xyz [util]: Wrapper that invokes lmac sub-routine at 0x128520
// lmac_handler_xyz [util]: Wrapper that invokes lmac sub-routine at 0x128520
BOOL  scan_chan_setup_n134(int a1)
{
  if ( *((uint8_t *)off_116F30 + 510) )
    return 0;
  if ( !sub_128520() )
    return 0;
  if ( *(uint8_t *)(a1 + 1224) )
    return sub_12A12C(*(unsigned __int8 *)(a1 + 1225)) != 0;
  return 1;
}

