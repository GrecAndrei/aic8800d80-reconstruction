// v23 annotated: sub_118D28 @ 0x118d28
// Original: 118d28_sub_118D28.c
// Primary struct: <unclustered>
//
// sub_118D28 @ 0x118d28, size 134 bytes
_DWORD *sub_118D28()
{
  int *v0; // r8
  int *v1; // r7
  int v2; // r6
  _DWORD *v3; // r5
  _DWORD *result; // r0
  _DWORD *v5; // r4
  int v6; // r3
  int v7; // r2
  void (__fastcall *v8)(_DWORD, _DWORD); // r2

  clear_flags(0x20000);
  v0 = (int *)off_118DC0;
  v1 = (int *)off_118DB0;
  v2 = dword_118DB4;
  v3 = off_118DB8;
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = (_DWORD *)rf_bus_mark_n100_d2d0(v2);
    v5 = result;
    if ( *v0 )
    {
      v6 = *v0 - 1;
      v7 = *v1;
      *v0 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v8 = (void (__fastcall *)(_DWORD, _DWORD))result[22];
    --v3[126];
    if ( v8 && (v8(result[23], *(_DWORD *)(result[19] + 72)), *((_BYTE *)v5 + 98)) )
    {
      *((_BYTE *)v5 + 98) = 0;
    }
    else if ( !*((_BYTE *)v5 + 96) )
    {
      list_push_tail(dword_118DBC);
    }
  }
  return result;
}

