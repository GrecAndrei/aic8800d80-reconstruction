// fwstruct annotate: 113864_sub_113864.c
// sub_113864 @ 0x113864, size 52 bytes
// Doc: sub_1213864 [unknown]: Pushes r4/lr; unrecognized instruction pattern with lsls r3,r3,0x1f
// sub_1213864 [unknown]: Pushes r4/lr; unrecognized instruction pattern with lsls r3,r3,0x1f
int sub_113864()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113898 = 1;
  }
  v0 = (int *)off_11389C;
  v1 = dword_1138A0;
  ++*(_DWORD *)off_11389C;
  result = sub_12D4F8(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_113898;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

