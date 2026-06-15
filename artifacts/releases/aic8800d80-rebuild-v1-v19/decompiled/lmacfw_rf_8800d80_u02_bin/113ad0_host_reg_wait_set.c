// host_reg_wait_set @ 0x113ad0, size 88 bytes
// Doc: host_reg_wait_set [mac]: Polls host register 0x40035244 until bit becomes non-zero
// host_reg_wait_set [mac]: Polls host register 0x40035244 until bit becomes non-zero
int __fastcall host_reg_wait_set(unsigned int a1, int a2)
{
  _DWORD *v4; // r3

  fw_state_check_n960(1);
  while ( !*(_DWORD *)off_113B28 )
    ;
  if ( a1 <= 0x1F )
  {
    v4 = off_113B2C;
    *((_DWORD *)off_113B2C + 16) = 1;
    v4[19] = 34816;
    v4[21] = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    v4[16] = 0;
    v4[19] = 0;
    v4[21] &= ~4u;
  }
  *(_DWORD *)off_113B28 = 1;
  return fw_state_check_n960(0);
}

