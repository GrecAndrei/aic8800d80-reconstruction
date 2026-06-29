// rf_msg_forward_n_1f4 @ 0x12f5f4, size 78 bytes
// Doc: rf_msg_forward_n_1f4 [rf]: RF message forward/relay handler
// rf_msg_forward_n_1f4 [rf]: RF message forward/relay handler
int  rf_msg_forward_n_1f4(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12F644 = 1;
  }
  v2 = (int *)off_12F648;
  ++*(uint32_t *)off_12F648;
  result = lookup_table_get();
  if ( a1 <= 4 )
    --*(uint8_t *)(dword_12F64C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(uint32_t *)off_12F644;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  --*((uint32_t *)off_12F650 + 126);
  return result;
}

