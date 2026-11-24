// rf_reg_write_wait @ 0x10edd8, size 70 bytes
// Doc: rf_reg_write_wait [rf]: Write RF register and poll/wait for completion
// rf_reg_write_wait [rf]: Write RF register and poll/wait for completion
int __fastcall rf_reg_write_wait(int a1, int a2, int a3)
{
  int *v3; // r5
  _DWORD *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10EE20 = 1;
  }
  v3 = (int *)off_10EE24;
  ++*(_DWORD *)off_10EE24;
  if ( a3 )
  {
    v4 = off_10EE28;
    while ( !*(_DWORD *)off_10EE28 )
      ;
    result = rf_reg_ack_cb();
    *v4 = 1;
  }
  else
  {
    result = rf_reg_ack_cb();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(_DWORD *)off_10EE20;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

