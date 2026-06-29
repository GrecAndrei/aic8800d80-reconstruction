// log_free_pool_d_3a48 @ 0x113a48, size 54 bytes
// Doc: rf_cmd_process_n4f6 [rf]: Process incoming RF control command
// rf_cmd_process_n4f6 [rf]: Process incoming RF control command
int log_free_pool_d_3a48()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_msg_process_body_n_1c8 = 1;
  }
  v0 = (int *)rf_msg_process_body_n_1c4;
  v1 = rf_msg_process_body_n_1c0;
  ++*(uint32_t *)rf_msg_process_body_n_1c4;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)rf_msg_process_body_n_1c8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

