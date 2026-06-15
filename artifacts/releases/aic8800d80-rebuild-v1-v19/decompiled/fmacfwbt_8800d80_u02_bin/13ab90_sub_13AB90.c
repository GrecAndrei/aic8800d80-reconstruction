// sub_13AB90 @ 0x13ab90, size 106 bytes
int __fastcall sub_13AB90(int a1, int a2, int a3)
{
  int v6; // r3
  int v7; // r1
  int *v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2

  feature_guard_sdio(
    32,
    dword_13ABFC,
    *(unsigned __int16 *)(a1 + 32),
    *(unsigned __int16 *)(a1 + 30),
    *(unsigned __int8 *)(a1 + 27));
  v6 = *(unsigned __int16 *)(a1 + 30);
  v7 = v6 << 31;
  if ( (v6 & 1) != 0 || (sub_117ACC(), (*(_WORD *)(a1 + 30) & 1) != 0) )
    sub_12ECB0(dword_13AC00, v7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_13AC04 = 1;
  }
  v8 = (int *)off_13AC08;
  ++*(_DWORD *)off_13AC08;
  result = sub_118358(a1, a3, a2);
  if ( *v8 )
  {
    v10 = *v8 - 1;
    v11 = *(_DWORD *)off_13AC04;
    *v8 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

