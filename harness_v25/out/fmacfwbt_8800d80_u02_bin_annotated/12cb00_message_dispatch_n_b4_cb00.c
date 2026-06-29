// fwstruct annotate: 12cb00_message_dispatch_n_b4_cb00.c
// message_dispatch_n_b4_cb00 @ 0x12cb00, size 72 bytes
// Doc: message_dispatch_n_82_cb32 [ipc]: Dispatch incoming message by ID
// message_dispatch_n_82_cb32 [ipc]: Dispatch incoming message by ID
int message_dispatch_n_b4_cb00()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12CB48 = 1;
  }
  v0 = (int *)message_dispatch_n_68;
  v1 = dword_12CB50;
  ++*(_DWORD *)message_dispatch_n_68;
  sub_12D374(0x10000000);
  while ( 1 )
  {
    result = sub_12D4F8(v1);
    if ( !result )
      break;
    buffer_pool_get(result);
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_12CB48;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

