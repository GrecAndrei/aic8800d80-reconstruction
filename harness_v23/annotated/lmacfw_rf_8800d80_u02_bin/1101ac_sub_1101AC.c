// v23 annotated: sub_1101AC @ 0x1101ac
// Original: 1101ac_sub_1101AC.c
// Primary struct: <unclustered>
//
// sub_1101AC @ 0x1101ac, size 52 bytes
int sub_1101AC()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1101E0 = 1;
  }
  v0 = (int *)off_1101E4;
  v1 = dword_1101E8;
  ++*(_DWORD *)off_1101E4;
  result = sub_11E7AC(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1101E0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

