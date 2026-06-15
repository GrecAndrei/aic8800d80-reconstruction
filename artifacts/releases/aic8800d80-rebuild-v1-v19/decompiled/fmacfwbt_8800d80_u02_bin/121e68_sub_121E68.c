// sub_121E68 @ 0x121e68, size 148 bytes
int sub_121E68()
{
  int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(__int16 **)off_121EFC < 0 && (sub_12D0B0(0) == 3 || !sub_12D0B0(0)) )
    sub_12F694(dword_121F18, dword_121F14, 1862);
  if ( sub_12D0B0(0) == 2 )
  {
    *(_DWORD *)off_121F00 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_121F04 = 1;
    }
    v1 = (int *)off_121F08;
    ++*(_DWORD *)off_121F08;
    sub_12D374(0x2000000);
    if ( (*(_DWORD *)off_121F0C & 4) != 0 )
      *(_DWORD *)off_121F10 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(_DWORD *)off_121F04;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return sub_12CF5C(0);
}

