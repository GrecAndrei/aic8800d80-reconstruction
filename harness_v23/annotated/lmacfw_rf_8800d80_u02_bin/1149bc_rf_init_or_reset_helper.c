// v23 annotated: rf_init_or_reset_helper @ 0x1149bc
// Original: 1149bc_rf_init_or_reset_helper.c
// Primary struct: <unclustered>
//
// rf_init_or_reset_helper @ 0x1149bc, size 52 bytes
// Doc: rf_init_or_reset_helper [rf]: RF subsystem initialization or reset helper
// rf_init_or_reset_helper [rf]: RF subsystem initialization or reset helper
int rf_init_or_reset_helper()
{
  int *v0; // r4
  int (__fastcall *v1)(int); // r2
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1149F0 = 1;
  }
  v0 = (int *)off_1149F4;
  v1 = (int (__fastcall *)(int))off_1149F8;
  ++*(_DWORD *)off_1149F4;
  result = v1(2);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1149F0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

