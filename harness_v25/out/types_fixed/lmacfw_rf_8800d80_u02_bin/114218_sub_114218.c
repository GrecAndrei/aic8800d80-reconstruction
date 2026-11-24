// sub_114218 @ 0x114218, size 54 bytes
// Doc: sub_1214218 [unknown]: Stub helper, shifted mask op after register save
// sub_1214218 [unknown]: Stub helper, shifted mask op after register save
int sub_114218()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_114250 = 1;
  }
  v0 = (int *)off_114254;
  ++*(_DWORD *)off_114254;
  result = MEMORY[0x1C8]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_114250;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

