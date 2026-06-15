// v23 annotated: sub_1138C8 @ 0x1138c8
// Original: 1138c8_sub_1138C8.c
// Primary struct: <unclustered>
//
// sub_1138C8 @ 0x1138c8, size 52 bytes
int sub_1138C8()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1138FC = 1;
  }
  v0 = (int *)off_113900;
  v1 = dword_113904;
  ++*(_DWORD *)off_113900;
  result = sub_12D190(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1138FC;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

