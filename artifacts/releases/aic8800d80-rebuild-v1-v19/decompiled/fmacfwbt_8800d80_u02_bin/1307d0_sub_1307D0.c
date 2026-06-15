// sub_1307D0 @ 0x1307d0, size 88 bytes
int sub_1307D0()
{
  _BYTE *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_130828;
  *((_BYTE *)off_130828 + 1) = 1;
  result = message_dispatch_n_d8(1070, 1);
  if ( !result )
  {
    rf_hw_timer_init();
    v0[6] = mmio_read_bitfield_7000101c();
    sub_1306CC();
    v2 = (unsigned __int8)v0[5];
    if ( (unsigned __int8)v0[6] != v2 )
    {
      sub_10ED90(v2);
      v3 = (unsigned __int8)v0[5];
      v4 = dword_130830;
      v0[6] = v3;
      sub_12ECB0(v4, v3);
    }
    return rf_level_apply_80c(1070, 1, 1000 * *((_DWORD *)off_13082C + 91));
  }
  return result;
}

