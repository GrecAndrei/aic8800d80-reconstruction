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
    *(_DWORD *)(v4 + 0x4c) = 34816;
    *(_DWORD *)(v4 + 0x54) = 629;
    __dsb(0xFu);
    v4[a1 + 512] = a2;
    *(_DWORD *)(v4 + 0x40) = 0;
    *(_DWORD *)(v4 + 0x4c) = 0;
    *(_DWORD *)(v4 + 0x54) &= ~4u;
  }
  *(_DWORD *)off_113B28 = 1;
  return fw_state_check_n960(0);
}

