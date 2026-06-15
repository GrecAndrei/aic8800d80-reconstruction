// v23 annotated: sub_116E24 @ 0x116e24
// Original: 116e24_sub_116E24.c
// Primary struct: <unclustered>
//
// sub_116E24 @ 0x116e24, size 144 bytes
int sub_116E24()
{
  int *v0; // r6
  int v1; // r4
  int result; // r0
  _WORD *v3; // r5
  int *v4; // r8
  int *v5; // r9
  char v6; // r2
  void (__fastcall *v7)(_DWORD); // r3
  int v8; // r3
  int v9; // r2

  v0 = (int *)off_116EB4;
  v1 = *(_DWORD *)off_116EB4;
  result = sub_11E628(0x800000);
  if ( v1 )
  {
    v3 = off_116EB8;
    if ( *(_WORD *)off_116EB8 )
    {
      v4 = (int *)off_116EBC;
      v5 = (int *)off_116EC0;
      do
      {
        if ( (*(_BYTE *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        sub_11E7AC(v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(_BYTE *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void (__fastcall **)(_DWORD))(v1 + 4);
        *(_BYTE *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(_DWORD *)(v1 + 8));
        result = *(_DWORD *)(v1 + 12);
        if ( result )
          result = sub_1174EC();
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
    }
  }
  return result;
}

