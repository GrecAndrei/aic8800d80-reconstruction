// fmac_tx_dispatch @ 0x10cbe4, size 86 bytes
// Doc: fmac_tx_dispatch [tx]: FMAC transmit path dispatcher
// fmac_tx_dispatch [tx]: FMAC transmit path dispatcher
int fmac_tx_dispatch()
{
  uint32_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = off_10CC3C;
  while ( !*(uint32_t *)off_10CC3C )
    ;
  if ( *(uint32_t *)(*(uint32_t *)off_10CC40 + 612) )
  {
    v1 = rf_bus_mark_n100_d2d0(*(uint32_t *)off_10CC40 + 612);
    v2 = **(__int16 **)off_10CC44;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(__int16 **)off_10CC44;
    *(uint32_t *)off_10CC3C = 1;
    if ( v4 >= 0 )
      return 20;
  }
  sub_12F46C(dword_10CC4C, dword_10CC48, 1101);
  return 20;
}

