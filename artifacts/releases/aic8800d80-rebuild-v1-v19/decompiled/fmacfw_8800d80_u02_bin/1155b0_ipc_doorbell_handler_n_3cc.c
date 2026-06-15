// ipc_doorbell_handler_n_3cc @ 0x1155b0, size 118 bytes
// Doc: ipc_doorbell_handler_n_3be [ipc]: IPC doorbell interrupt handler reading masked status register
// ipc_doorbell_handler_n_3be [ipc]: IPC doorbell interrupt handler reading masked status register
int __fastcall ipc_doorbell_handler_n_3cc(int a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = off_115628;
  v3 = *((_DWORD *)off_115628 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto ipc_doorbell_handler_n_3a0;
  v5 = *(_DWORD *)ipc_doorbell_handler_n_34f;
  if ( (ipc_doorbell_handler_n_34b & *(_DWORD *)ipc_doorbell_handler_n_34f) == 0 )
  {
    v6 = ipc_doorbell_handler_n_347 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = rf_bus_reset_n_32e(0);
      v10 = rf_state_check_n268;
      *(_DWORD *)rf_state_check_n268 = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        rf_fault_dump_n_1ec(v9, 0x40000000, (int)v10);
      goto ipc_doorbell_handler_n_3a0;
    }
    if ( v6 < 0 )
    {
      rf_fault_dump_n_1ec(0, a2, v4);
      if ( !*((_BYTE *)ipc_doorbell_handler_638 + 3) )
      {
ipc_doorbell_handler_n_3a0:
        for ( i = 0; ; ++i )
        {
          result = *(_DWORD *)(4 * i - 536813056) & *(_DWORD *)(4 * i - 536813312);
          if ( i == 1 )
          {
            if ( (result & 0xFFFFFFEF) != 0 )
              return 1;
          }
          else
          {
            if ( result )
              return 1;
            if ( i == 2 )
              return result;
          }
        }
      }
    }
  }
  return 1;
}

