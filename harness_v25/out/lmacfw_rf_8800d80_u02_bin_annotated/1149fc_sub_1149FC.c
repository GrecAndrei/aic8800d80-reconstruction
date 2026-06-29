// fwstruct annotate: 1149fc_sub_1149FC.c
// sub_1149FC @ 0x1149fc, size 56 bytes
int __fastcall sub_1149FC(int a1)
{
  BOOL v1; // r0
  int *v2; // r4
  int (__fastcall *v3)(BOOL); // r2
  int result; // r0
  int v5; // r3
  int v6; // r2

  v1 = a1 != 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_114A34 = 1;
  }
  v2 = (int *)off_114A38;
  v3 = (int (__fastcall *)(BOOL))off_114A3C;
  ++*(_DWORD *)off_114A38;
  result = v3(v1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(_DWORD *)off_114A34;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

