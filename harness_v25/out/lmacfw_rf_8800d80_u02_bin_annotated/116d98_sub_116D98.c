// fwstruct annotate: 116d98_sub_116D98.c
// sub_116D98 @ 0x116d98, size 126 bytes
int sub_116D98()
{
  int *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r8
  int *v4; // r9
  int v5; // r7
  void (__fastcall *v6)(_DWORD); // r2
  int v7; // r3
  int v8; // r2

  v0 = (int *)off_116E18;
  v1 = *(_DWORD *)off_116E18;
  result = sub_11E628(0x800000);
  if ( v1 )
  {
    v3 = (int *)off_116E1C;
    v4 = (int *)off_116E20;
    v5 = 0;
    do
    {
      if ( (*(_BYTE *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          return result;
        v5 = 1;
      }
      sub_11E7AC(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v3 = 1;
      }
      v6 = *(void (__fastcall **)(_DWORD))(v1 + 4);
      ++*v4;
      *(_BYTE *)(v1 + 16) = 0;
      if ( v6 )
        v6(*(_DWORD *)(v1 + 8));
      result = *(_DWORD *)(v1 + 12);
      if ( result )
        result = sub_1174EC();
      if ( *v4 )
      {
        v7 = *v4 - 1;
        v8 = *v3;
        *v4 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
      v1 = *v0;
    }
    while ( *v0 );
  }
  return result;
}

