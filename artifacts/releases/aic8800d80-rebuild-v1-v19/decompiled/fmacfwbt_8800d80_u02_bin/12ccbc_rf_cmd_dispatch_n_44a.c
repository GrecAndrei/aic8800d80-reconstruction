// rf_cmd_dispatch_n_44a @ 0x12ccbc, size 64 bytes
// Doc: message_dispatch_n12e [ipc]: Message dispatch entry storing zeroed pair into out struct
// message_dispatch_n12e [ipc]: Message dispatch entry storing zeroed pair into out struct
_DWORD *rf_cmd_dispatch_n_44a()
{
  _DWORD *result; // r0
  _DWORD *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  result = (_DWORD *)(dword_12CCFC & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12CD00 = 1;
  }
  v1 = message_dispatch_n150;
  v2 = *(_DWORD *)message_dispatch_n150;
  v3 = *(_DWORD *)message_dispatch_n150 + 1;
  v4 = (message_dispatch_n154 & 0xFFFFFFFC) - (_DWORD)result;
  *(_DWORD *)message_dispatch_n150 = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (int *)off_12CD00;
    *v1 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

