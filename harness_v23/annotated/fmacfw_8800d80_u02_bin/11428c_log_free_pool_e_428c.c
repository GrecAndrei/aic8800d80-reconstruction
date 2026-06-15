// v23 annotated: log_free_pool_e_428c @ 0x11428c
// Original: 11428c_log_free_pool_e_428c.c
// Primary struct: <unclustered>
//
// log_free_pool_e_428c @ 0x11428c, size 72 bytes
// Doc: rf_fault_dump_n_4aa [rf]: Dump RF fault information and increment counter
// rf_fault_dump_n_4aa [rf]: Dump RF fault information and increment counter
int log_free_pool_e_428c()
{
  int *v0; // r5
  _DWORD *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_fault_dump_n_474 = 1;
  }
  v0 = (int *)rf_fault_dump_n_470;
  v1 = rf_fault_handler;
  ++*(_DWORD *)rf_fault_dump_n_470;
  while ( !*v1 )
    ;
  result = list_push_tail(*(_DWORD *)rf_state_check_n2d6 + 628);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)rf_fault_dump_n_474;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

