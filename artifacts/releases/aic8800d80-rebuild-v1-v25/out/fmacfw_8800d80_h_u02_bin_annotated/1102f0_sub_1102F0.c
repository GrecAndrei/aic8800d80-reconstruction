// fwstruct annotate: 1102f0_sub_1102F0.c
// sub_1102F0 @ 0x1102f0, size 62 bytes
int sub_1102F0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110330 = 1;
  }
  v0 = (int *)off_110334;
  v1 = dword_110338;
  ++*(_DWORD *)off_110334;
  result = sub_12D108(v1);
  v3 = *v0;
  ++*(_DWORD *)off_11033C;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_110330;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

