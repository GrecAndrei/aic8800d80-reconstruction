// sub_10ED84 @ 0x10ed84, size 70 bytes
int __fastcall sub_10ED84(int a1, int a2)
{
  int *v2; // r5
  _DWORD *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10EDCC = 1;
  }
  v2 = (int *)off_10EDD0;
  ++*(_DWORD *)off_10EDD0;
  if ( a2 )
  {
    v3 = off_10EDD4;
    while ( !*(_DWORD *)off_10EDD4 )
      ;
    result = rf_reg_read_cb();
    *v3 = 1;
  }
  else
  {
    result = rf_reg_read_cb();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(_DWORD *)off_10EDCC;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

