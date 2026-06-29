// fwstruct annotate: 10c9cc_sub_10C9CC.c
// sub_10C9CC @ 0x10c9cc, size 236 bytes
int __fastcall sub_10C9CC(char a1)
{
  int v1; // r5
  unsigned __int8 *v2; // r11
  int v3; // r8
  int *v4; // r7
  _DWORD *v5; // r10
  unsigned int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  int *v9; // r9
  int v10; // r0
  int v11; // r1
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int result; // r0

  clear_flags(2048);
  v1 = *(_DWORD *)off_10CAB8;
  if ( *(_DWORD *)(*(_DWORD *)off_10CAB8 + 636) )
  {
    v2 = (unsigned __int8 *)off_10CAD0;
    v3 = dword_10CAD4;
    v4 = (int *)off_10CABC;
    v5 = off_10CAD8;
    while ( 1 )
    {
      v6 = v2[1621];
      v7 = v2[1622];
      if ( v6 >= v7 )
        break;
      v8 = v2[1620]
         + 1
         - 81 * ((unsigned int)(((unsigned int)v3 * (unsigned __int64)((unsigned int)v2[1620] + 1)) >> 32) >> 6);
      v2[1621] = v6 + 1;
      v2[1620] = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v9 = (int *)off_10CADC;
      ++*(_DWORD *)off_10CADC;
      while ( !*v5 )
        ;
      v10 = rf_bus_mark_n100_d2d0(v1 + 636);
      v11 = *v9;
      *v5 = 1;
      v12 = v10;
      if ( v11 )
      {
        v13 = v11 - 1;
        v14 = *v4;
        *v9 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      v15 = dword_10CAC4;
      *(_DWORD *)&v2[20 * v8 + 4] = v12 + *(_DWORD *)off_10CAC0;
      list_push_tail(v15);
      if ( !*(_DWORD *)(v1 + 636) )
        goto LABEL_13;
    }
    sub_10DC24(dword_10CACC, v6, v7);
  }
LABEL_13:
  result = irq_nesting_or_d104(256);
  *(_DWORD *)off_10CAC8 = (1 << (a1 + 8)) & 0x1F00;
  return result;
}

