// rf_reg_write_wait @ 0x10f010, size 70 bytes
// Doc: rf_reg_write_wait [rf]: Write RF register and wait for completion
// rf_reg_write_wait [rf]: Write RF register and wait for completion
int  rf_reg_write_wait(int a1, int a2, int a3)
{
  int *v3; // r5
  uint32_t *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10F058 = 1;
  }
  v3 = (int *)off_10F05C;
  ++*(uint32_t *)off_10F05C;
  if ( a3 )
  {
    v4 = off_10F060;
    while ( !*(uint32_t *)off_10F060 )
      ;
    result = sub_10EFAC();
    *v4 = 1;
  }
  else
  {
    result = sub_10EFAC();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(uint32_t *)off_10F058;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

