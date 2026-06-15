// sub_113A08 @ 0x113a08, size 52 bytes
// Doc: rf_cmd_process_n4ca [rf]: Process RF command handler (n4ca variant)
// rf_cmd_process_n4ca [rf]: Process RF command handler (n4ca variant)
int sub_113A08()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_cmd_process_n4e4 = 1;
  }
  v0 = (int *)rf_cmd_process_3a40;
  v1 = rf_cmd_process_n4ec;
  ++*(_DWORD *)rf_cmd_process_3a40;
  result = rf_bus_mark_n100_d2d0(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)rf_cmd_process_n4e4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

