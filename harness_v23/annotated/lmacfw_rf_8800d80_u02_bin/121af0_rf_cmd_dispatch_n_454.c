// v23 annotated: rf_cmd_dispatch_n_454 @ 0x121af0
// Original: 121af0_rf_cmd_dispatch_n_454.c
// Primary struct: <unclustered>
//
// rf_cmd_dispatch_n_454 @ 0x121af0, size 66 bytes
// Doc: rf_cmd_dispatch_n_438 [rf]: Dispatch RF command with sub-id compare against 3
// rf_cmd_dispatch_n_438 [rf]: Dispatch RF command with sub-id compare against 3
int __fastcall rf_cmd_dispatch_n_454(unsigned int a1)
{
  int *v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_mem_write_n_4f8 = 1;
  }
  v2 = (int *)rf_cmd_dispatch_n_40c;
  ++*(_DWORD *)rf_cmd_dispatch_n_40c;
  result = rf_lmac_log_str_n2cc();
  if ( a1 <= 3 )
    --*(_BYTE *)(dword_121B3C + a1);
  if ( *v2 )
  {
    v4 = *v2 - 1;
    v5 = *(_DWORD *)rf_mem_write_n_4f8;
    *v2 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

