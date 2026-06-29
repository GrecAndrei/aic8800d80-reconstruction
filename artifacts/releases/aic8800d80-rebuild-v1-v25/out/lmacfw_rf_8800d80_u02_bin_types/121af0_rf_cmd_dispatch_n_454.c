// rf_cmd_dispatch_n_454 @ 0x121af0, size 66 bytes
// Doc: rf_cmd_dispatch_n_438 [rf]: Dispatch RF command with sub-id compare against 3
// rf_cmd_dispatch_n_438 [rf]: Dispatch RF command with sub-id compare against 3
int  rf_cmd_dispatch_n_454(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_mem_write_n_4f8 = 1;
  }
  v2 = (int *)rf_cmd_dispatch_n_40c;
  ++*(uint32_t *)rf_cmd_dispatch_n_40c;
  result = rf_lmac_log_str_n2cc();
  if ( a1 <= 3 )
    --*(uint8_t *)(dword_121B3C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(uint32_t *)rf_mem_write_n_4f8;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

