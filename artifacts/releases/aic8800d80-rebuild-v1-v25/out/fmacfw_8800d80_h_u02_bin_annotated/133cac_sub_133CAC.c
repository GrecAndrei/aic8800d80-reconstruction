// fwstruct annotate: 133cac_sub_133CAC.c
// sub_133CAC @ 0x133cac, size 154 bytes
int __fastcall sub_133CAC(int a1, unsigned __int16 *a2)
{
  int v3; // r6
  int *v4; // r4
  int v5; // r0
  int v6; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2

  v3 = *((unsigned __int8 *)a2 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_133D48 = 1;
  }
  v4 = (int *)off_133D4C;
  ++*(_DWORD *)off_133D4C;
  if ( sub_12CD48(6u) || *((_BYTE *)off_133D50 + 14) && sub_12C774(6155, 6) )
  {
    if ( *v4 )
    {
      v10 = *v4 - 1;
      v11 = *(_DWORD *)off_133D48;
      *v4 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    return 2;
  }
  else
  {
    if ( *v4 )
    {
      v8 = *v4 - 1;
      v9 = *(_DWORD *)off_133D48;
      *v4 = v8;
      if ( !v8 )
      {
        if ( v9 )
          __enable_irq();
      }
    }
    v5 = dword_133D54 + 1320 * v3;
    v6 = *(unsigned __int8 *)(v5 + 106);
    if ( !*(_BYTE *)(v5 + 106) && *(_BYTE *)(v5 + 108) )
    {
      sub_134C4C(v5, *a2, 1);
      return v6;
    }
    else
    {
      sub_12C8D0(6148, 13, 6);
      return 0;
    }
  }
}

