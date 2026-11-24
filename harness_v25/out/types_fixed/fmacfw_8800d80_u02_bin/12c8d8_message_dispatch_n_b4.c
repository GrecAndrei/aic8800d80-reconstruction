// message_dispatch_n_b4 @ 0x12c8d8, size 72 bytes
// Doc: message_dispatch_n_7c [ipc]: Dispatch IPC message by indexing into message table
// message_dispatch_n_7c [ipc]: Dispatch IPC message by indexing into message table
int message_dispatch_n_b4()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)message_dispatch_n_6c_c920 = 1;
  }
  v0 = (int *)off_12C924;
  v1 = dword_12C928;
  ++*(_DWORD *)off_12C924;
  clear_flags(0x10000000);
  while ( 1 )
  {
    result = rf_bus_mark_n100_d2d0(v1);
    if ( !result )
      break;
    sub_12CBC8(result);
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)message_dispatch_n_6c_c920;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

