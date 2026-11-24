// sub_114BB8 @ 0x114bb8, size 54 bytes
// Doc: patch_apply_n_2ce [patch]: Apply next ROM patch from patch table iterator
// patch_apply_n_2ce [patch]: Apply next ROM patch from patch table iterator
int sub_114BB8()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_fault_dump_bf0 = 1;
  }
  v0 = (int *)off_114BF4;
  ++*(_DWORD *)off_114BF4;
  result = MEMORY[0x1C8]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)rf_fault_dump_bf0;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

