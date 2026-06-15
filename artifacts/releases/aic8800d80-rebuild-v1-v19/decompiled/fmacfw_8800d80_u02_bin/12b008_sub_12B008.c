// sub_12B008 @ 0x12b008, size 98 bytes
int sub_12B008()
{
  int v0; // r5
  int v1; // r4
  int value; // r0
  int v3; // r2

  v0 = *(_DWORD *)off_12B06C;
  v1 = *((unsigned __int8 *)off_12B06C + 10);
  if ( msg_get_value(2) != 2 )
  {
    value = msg_get_value(2);
    msg_parse(dword_12B070, value, v3);
  }
  if ( **(__int16 **)off_12B074 < 0 && msg_get_value(2) != 2 )
    sub_12F46C(dword_12B07C, dword_12B078, 163);
  if ( (*(_BYTE *)(v0 + 6 * v1 + 3) & 1) == 0 )
    fmac_rx_buff_check();
  sub_12CD34(2);
  return 0;
}

