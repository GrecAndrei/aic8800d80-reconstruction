// fwstruct annotate: 10ec30_sub_10EC30.c
// sub_10EC30 @ 0x10ec30, size 70 bytes
int __fastcall sub_10EC30(int a1, int a2, int a3)
{
  int *v3; // r5
  _DWORD *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10EC78 = 1;
  }
  v3 = (int *)off_10EC7C;
  ++*(_DWORD *)off_10EC7C;
  if ( a3 )
  {
    v4 = off_10EC80;
    while ( !*(_DWORD *)off_10EC80 )
      ;
    result = sub_10EBCC();
    *v4 = 1;
  }
  else
  {
    result = sub_10EBCC();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(_DWORD *)off_10EC78;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

