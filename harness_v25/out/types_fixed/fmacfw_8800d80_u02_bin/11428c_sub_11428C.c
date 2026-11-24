// sub_11428C @ 0x11428c, size 72 bytes
// Doc: rf_fault_dump_n [rf]: Dumps the n-th RF fault state (field at offset 0x274 in the global RF state struct), increments the fault counter, and sets the handled flag.
// rf_fault_dump_n [rf]: Dumps the n-th RF fault state (field at offset 0x274 in the global RF state struct), increments the fault counter, and sets the handled flag.
int sub_11428C()
{
  int *v0; // r5
  _DWORD *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1142D4 = 1;
  }
  v0 = (int *)off_1142D8;
  v1 = off_1142DC;
  ++*(_DWORD *)off_1142D8;
  while ( !*v1 )
    ;
  result = sub_12D248(*(_DWORD *)off_1142E0 + 628);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1142D4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

