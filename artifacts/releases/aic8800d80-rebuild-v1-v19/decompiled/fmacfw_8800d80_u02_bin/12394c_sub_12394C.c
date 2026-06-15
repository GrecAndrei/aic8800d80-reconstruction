// sub_12394C @ 0x12394c, size 106 bytes
int __fastcall sub_12394C(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  _DWORD *v5; // r5
  int v6; // r6
  __int64 v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1239B8 = 1;
  }
  v4 = (int *)off_1239BC;
  v5 = off_1239C0;
  v6 = *(_DWORD *)off_1239C0;
  ++*(_DWORD *)off_1239BC;
  v7 = mmio_set_reset_vector_n_b8();
  v9 = sub_1019D0(v7, SHIDWORD(v7), v8);
  v10 = message_dispatch_n_b4(v9);
  sub_1321C8(v10);
  fw_init_umac_subsystem();
  mac_phy_init();
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(_DWORD *)off_1239B8;
    *v4 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  sub_12CA10(1, a4, a3);
  sub_12CD34(0);
  return 0;
}

