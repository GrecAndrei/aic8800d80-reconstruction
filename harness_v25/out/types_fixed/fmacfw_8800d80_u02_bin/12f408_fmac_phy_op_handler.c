// fmac_phy_op_handler @ 0x12f408, size 82 bytes
// Doc: fmac_phy_op_handler [mac]: PHY operation dispatcher (unknown purpose)
// fmac_phy_op_handler [mac]: PHY operation dispatcher (unknown purpose)
int __fastcall fmac_phy_op_handler(int a1, int a2, int a3)
{
  int *v4; // r4
  int v5; // r0
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12F45C = 1;
  }
  v4 = (int *)off_12F460;
  v5 = dword_12F464;
  ++*(_DWORD *)off_12F460;
  result = msg_parse(v5, a1, a2, a3 & 0xFFFFF);
  if ( *(int *)off_12F468 >= 0 )
  {
    sub_12BB20();
    result = irq_nesting_or_d104(0x80000000);
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_12F45C;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

