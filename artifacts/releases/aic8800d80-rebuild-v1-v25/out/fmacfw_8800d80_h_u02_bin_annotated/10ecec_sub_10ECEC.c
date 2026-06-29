// fwstruct annotate: 10ecec_sub_10ECEC.c
// sub_10ECEC @ 0x10ecec, size 70 bytes
int __fastcall sub_10ECEC(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  _DWORD *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10ED34 = 1;
  }
  v4 = (int *)off_10ED38;
  ++*(_DWORD *)off_10ED38;
  if ( a4 )
  {
    v5 = off_10ED3C;
    while ( !*(_DWORD *)off_10ED3C )
      ;
    result = sub_10EC3C();
    *v5 = 1;
  }
  else
  {
    result = sub_10EC3C();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_10ED34;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

