// sub_10EC84 @ 0x10ec84, size 70 bytes
int __fastcall sub_10EC84(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  _DWORD *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10ECCC = 1;
  }
  v4 = (int *)off_10ECD0;
  ++*(_DWORD *)off_10ECD0;
  if ( a4 )
  {
    v5 = off_10ECD4;
    while ( !*(_DWORD *)off_10ECD4 )
      ;
    result = sub_10EBD4();
    *v5 = 1;
  }
  else
  {
    result = sub_10EBD4();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_10ECCC;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

