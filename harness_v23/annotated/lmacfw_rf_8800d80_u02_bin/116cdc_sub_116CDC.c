// v23 annotated: sub_116CDC @ 0x116cdc
// Original: 116cdc_sub_116CDC.c
// Primary struct: rf_calib_tbl (cluster 10, 5 funcs)
// Fields: base=0x0, idx=0xa, count=0xb
//
// sub_116CDC @ 0x116cdc, size 158 bytes
int sub_116CDC()
{
  _WORD *v0; // r5
  int v1; // r4
  int result; // r0
  int *v3; // r9
  int *v4; // r7
  void (__fastcall *v5)(_DWORD); // r2
  int v6; // r3
  int v7; // r2
  _DWORD *v8; // r1
  _DWORD *v9; // r2

  v0 = off_116D7C;
  v1 = *(_DWORD *)off_116D7C;
  result = sub_11E628(0x800000);
  if ( v1 )
  {
    v3 = (int *)off_116D94;
    v4 = (int *)off_116D80;
    do
    {
      if ( (*(_BYTE *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      sub_11E7AC(v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v5 = *(void (__fastcall **)(_DWORD))(v1 + 4);
      ++*v3;
      *(_BYTE *)(v1 + 16) = 0;
      if ( v5 )
        v5(*(_DWORD *)(v1 + 8));
      result = *(_DWORD *)(v1 + 12);
      if ( result )
        result = sub_1174EC();
      if ( *v3 )
      {
        v6 = *v3 - 1;
        v7 = *v4;
        *v3 = v6;
        if ( !v6 )
        {
          if ( v7 )
            __enable_irq();
        }
      }
      v1 = *(_DWORD *)v0;
    }
    while ( *(_DWORD *)v0 );
  }
  if ( *((unsigned __int8 *)v0 + 10) != *((unsigned __int8 *)v0 + 11) )
  {
    v8 = off_116D8C;
    v9 = off_116D90;
    *(_DWORD *)off_116D88 = *((_DWORD *)off_116D84 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}

