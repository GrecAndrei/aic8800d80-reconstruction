// fwstruct annotate: 1132c0_sub_1132C0.c
// sub_1132C0 @ 0x1132c0, size 52 bytes
// Doc: sub_12132C0 [unknown]: Thin wrapper routine (push r4,lr; small arithmetic tail)
// sub_12132C0 [unknown]: Thin wrapper routine (push r4,lr; small arithmetic tail)
int sub_1132C0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1132F4 = 1;
  }
  v0 = (int *)off_1132F8;
  v1 = dword_1132FC;
  ++*(_DWORD *)off_1132F8;
  result = sub_11E7AC(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1132F4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

