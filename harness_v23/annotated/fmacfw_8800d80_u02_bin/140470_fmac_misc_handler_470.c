// v23 annotated: fmac_misc_handler_470 @ 0x140470
// Original: 140470_fmac_misc_handler_470.c
// Primary struct: <unclustered>
//
// fmac_misc_handler_470 @ 0x140470, size 50 bytes
// Doc: fmac_misc_handler_470 [mac]: Miscellaneous FMAC handler
// fmac_misc_handler_470 [mac]: Miscellaneous FMAC handler
int fmac_misc_handler_470()
{
  if ( msg_get_value(0xBu) == 4 )
  {
    rx_agc_init_n_4e0();
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_1404A4 < 0 )
      sub_12F49C(dword_1404AC, dword_1404A8, 129);
    return 0;
  }
}

