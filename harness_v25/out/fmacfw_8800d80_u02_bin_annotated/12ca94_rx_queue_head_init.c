// fwstruct annotate: 12ca94_rx_queue_head_init.c
// rx_queue_head_init @ 0x12ca94, size 64 bytes
// Doc: message_dispatch_n140 [ipc]: Message dispatch handler variant 140
// message_dispatch_n140 [ipc]: Message dispatch handler variant 140
_DWORD *rx_queue_head_init()
{
  _DWORD *result; // r0
  _DWORD *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  result = (_DWORD *)(message_dispatch_n148 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)message_dispatch_n14c = 1;
  }
  v1 = off_12CADC;
  v2 = *(_DWORD *)off_12CADC;
  v3 = *(_DWORD *)off_12CADC + 1;
  v4 = (message_dispatch_n154 & 0xFFFFFFFC) - (_DWORD)result;
  *(_DWORD *)off_12CADC = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (int *)message_dispatch_n14c;
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

