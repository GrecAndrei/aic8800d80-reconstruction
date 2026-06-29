// fwstruct annotate: 12b22c_fmacfwbt_init_n_22c.c
// fmacfwbt_init_n_22c @ 0x12b22c, size 98 bytes
// Doc: fmacfwbt_init_n_22c [util]: Initializes FMAC+BT subsystem and verifies state
// fmacfwbt_init_n_22c [util]: Initializes FMAC+BT subsystem and verifies state
int fmacfwbt_init_n_22c()
{
  int v0; // r5
  int v1; // r4
  int value; // r0
  int v3; // r2

  v0 = *(_DWORD *)off_12B290;
  v1 = *((unsigned __int8 *)off_12B290 + 10);
  if ( msg_get_value(2) != 2 )
  {
    value = msg_get_value(2);
    sub_12ECB0(dword_12B294, value, v3);
  }
  if ( **(__int16 **)off_12B298 < 0 && msg_get_value(2) != 2 )
    sub_12F694(dword_12B2A0, dword_12B29C, 163);
  if ( (*(_BYTE *)(v0 + 6 * v1 + 3) & 1) == 0 )
    sub_12B5BC();
  rf_bus_mark_n_3b7(2);
  return 0;
}

