// sub_10EC98 @ 0x10ec98, size 70 bytes
int __fastcall sub_10EC98(int a1, int a2, int a3)
{
  int *v3; // r5
  _DWORD *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10ECE0 = 1;
  }
  v3 = (int *)off_10ECE4;
  ++*(_DWORD *)off_10ECE4;
  if ( a3 )
  {
    v4 = off_10ECE8;
    while ( !*(_DWORD *)off_10ECE8 )
      ;
    result = sub_10EC34();
    *v4 = 1;
  }
  else
  {
    result = sub_10EC34();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(_DWORD *)off_10ECE0;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

