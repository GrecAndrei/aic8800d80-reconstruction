// sub_10EFBC @ 0x10efbc, size 70 bytes
int  sub_10EFBC(int a1, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10F004 = 1;
  }
  v2 = (int *)off_10F008;
  ++*(uint32_t *)off_10F008;
  if ( a2 )
  {
    v3 = off_10F00C;
    while ( !*(uint32_t *)off_10F00C )
      ;
    result = rf_reg_read_cb_efa4();
    *v3 = 1;
  }
  else
  {
    result = rf_reg_read_cb_efa4();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(uint32_t *)off_10F004;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

