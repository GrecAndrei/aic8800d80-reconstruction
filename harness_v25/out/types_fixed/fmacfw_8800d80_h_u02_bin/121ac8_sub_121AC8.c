// sub_121AC8 @ 0x121ac8, size 148 bytes
int sub_121AC8()
{
  int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(__int16 **)off_121B5C < 0 && (sub_12CD48(0) == 3 || !sub_12CD48(0)) )
    sub_12F32C(dword_121B78, dword_121B74, 1862);
  if ( sub_12CD48(0) == 2 )
  {
    *(_DWORD *)off_121B60 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_121B64 = 1;
    }
    v1 = (int *)off_121B68;
    ++*(_DWORD *)off_121B68;
    sub_12D00C(0x2000000);
    if ( (*(_DWORD *)off_121B6C & 4) != 0 )
      *(_DWORD *)off_121B70 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(_DWORD *)off_121B64;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return sub_12CBF4(0);
}

