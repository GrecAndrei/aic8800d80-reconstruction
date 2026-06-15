// lmac_rf_handler_1102d0 @ 0x1102d0, size 62 bytes
// Doc: lmac_rf_handler_1102d0 [rf]: LMAC RF handler stub at 0x1102d0
// lmac_rf_handler_1102d0 [rf]: LMAC RF handler stub at 0x1102d0
int lmac_rf_handler_1102d0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110310 = 1;
  }
  v0 = (int *)off_110314;
  v1 = dword_110318;
  ++*(_DWORD *)off_110314;
  result = sub_11E7AC(v1);
  if ( result )
    --*(_DWORD *)off_11031C;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110310;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

