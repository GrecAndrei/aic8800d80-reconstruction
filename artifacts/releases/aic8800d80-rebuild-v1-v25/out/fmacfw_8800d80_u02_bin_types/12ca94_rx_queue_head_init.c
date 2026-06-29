// rx_queue_head_init @ 0x12ca94, size 64 bytes
// Doc: message_dispatch_n140 [ipc]: Message dispatch handler variant 140
// message_dispatch_n140 [ipc]: Message dispatch handler variant 140
uint32_t *rx_queue_head_init()
{
  uint32_t *result; // r0
  uint32_t *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  int *v5; // r3
  int v6; // r3

  result = (uint32_t *)(message_dispatch_n148 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n14c = 1;
  }
  v1 = off_12CADC;
  v2 = *(uint32_t *)off_12CADC;
  v3 = *(uint32_t *)off_12CADC + 1;
  v4 = (message_dispatch_n154 & 0xFFFFFFFC) - (uint32_t)result;
  *(uint32_t *)off_12CADC = v3;
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

