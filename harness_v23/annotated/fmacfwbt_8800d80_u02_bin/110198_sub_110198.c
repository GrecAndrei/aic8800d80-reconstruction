// v23 annotated: sub_110198 @ 0x110198
// Original: 110198_sub_110198.c
// Primary struct: <unclustered>
//
// sub_110198 @ 0x110198, size 62 bytes
int sub_110198()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1101D8 = 1;
  }
  v0 = (int *)off_1101DC;
  v1 = dword_1101E0;
  ++*(_DWORD *)off_1101DC;
  result = sub_12D4F8(v1);
  if ( result )
    --*(_DWORD *)off_1101E4;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1101D8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

