// sub_123B80 @ 0x123b80, size 106 bytes
int __fastcall sub_123B80(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  _DWORD *v5; // r5
  int v6; // r6
  __int64 v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r3
  int v12; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_123BEC = 1;
  }
  v4 = (int *)off_123BF0;
  v5 = off_123BF4;
  v6 = *(_DWORD *)off_123BF4;
  ++*(_DWORD *)off_123BF0;
  v7 = sub_12BAD0();
  v9 = sub_10184C(v7, SHIDWORD(v7), v8);
  v10 = message_dispatch_n_b4_cb00(v9);
  sub_1323E4(v10);
  bt_scan_channel_parse();
  sub_120A58();
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    --v11;
    v12 = *(_DWORD *)off_123BEC;
    *v4 = v11;
    if ( !v11 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  message_dispatch_n84(1, a4, a3, v11);
  rf_bus_mark_n_3b7(0);
  return 0;
}

