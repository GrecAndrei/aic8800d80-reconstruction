// v23 annotated: sub_11D864 @ 0x11d864
// Original: 11d864_sub_11D864.c
// Primary struct: <unclustered>
//
// sub_11D864 @ 0x11d864, size 180 bytes
int sub_11D864()
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
  _BYTE *v10; // r4

  v0 = (int *)off_11D918;
  v1 = *(_DWORD *)off_11D918;
  result = sub_12D00C(0x200000);
  if ( v1 )
  {
    v3 = off_11D91C;
    if ( *(_WORD *)off_11D91C )
    {
      v4 = (int *)off_11D928;
      v5 = (int *)off_11D92C;
      do
      {
        if ( (*(_BYTE *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        sub_12D190(v0);
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
          result = sub_11DF74();
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
      v10 = off_11D920;
      if ( *((_BYTE *)off_11D920 + 69) )
      {
        sub_12CFC4(0x80000);
        result = sub_12EB90(1024, dword_11D924);
        v10[69] = 0;
      }
    }
  }
  return result;
}

