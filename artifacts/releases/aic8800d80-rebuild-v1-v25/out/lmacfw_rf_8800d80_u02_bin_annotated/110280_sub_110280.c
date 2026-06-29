// fwstruct annotate: 110280_sub_110280.c
// sub_110280 @ 0x110280, size 62 bytes
// Doc: sub_1210280 [rf]: LMAC RF helper performing shift-based bit manipulation
// sub_1210280 [rf]: LMAC RF helper performing shift-based bit manipulation
int sub_110280()
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
    *(_DWORD *)off_1102C0 = 1;
  }
  v0 = (int *)off_1102C4;
  v1 = dword_1102C8;
  ++*(_DWORD *)off_1102C4;
  result = list_push_tail(v1);
  v3 = *v0;
  ++*(_DWORD *)off_1102CC;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_1102C0;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

