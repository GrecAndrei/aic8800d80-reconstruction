// sub_130170 @ 0x130170, size 238 bytes
// Doc: sub_1230170_handler [unknown]: Pushes r4-r8,sb,lr; allocates 0x4c stack; handler stub
// sub_1230170_handler [unknown]: Pushes r4-r8,sb,lr; allocates 0x4c stack; handler stub
unsigned __int8 *sub_130170()
{
  int *v0; // r6
  int v1; // r0
  unsigned __int8 *result; // r0
  unsigned __int8 *v3; // r4
  int v4; // r3
  int v5; // r2
  _DWORD *v6; // r7
  int v7; // r8
  int v8; // r9
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  _DWORD *v13; // r0
  int v14; // r0
  int v15[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_130260 = 1;
  }
  v0 = (int *)off_130264;
  v1 = dword_130268;
  ++*(_DWORD *)off_130264;
  result = (unsigned __int8 *)rf_bus_mark_n100_d2d0(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(_DWORD *)off_130260;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (_DWORD *)dword_13026C;
    v7 = dword_130280;
    v8 = dword_130284;
    do
    {
      v9 = sub_12F6FC(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = sub_12F788(v15[0], v6, 7);
        if ( v13 )
        {
          if ( *((__int16 *)v13 + 5) < v9 || *((__int16 *)v13 + 4) > v9 )
          {
            sub_10DC24(v7, *v13, v13[1]);
          }
          else
          {
            v14 = ((int (__fastcall *)(int, int *))v13[3])(v9, v15);
            if ( v14 )
              sub_10DC24(v8, v14);
          }
        }
        else
        {
          sub_10DC24(dword_13027C, v15[0]);
        }
      }
      else
      {
        uart_puts((_BYTE *)dword_130270);
      }
      uart_puts((_BYTE *)dword_130274);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_130260 = 1;
      }
      v10 = dword_130278;
      ++*v0;
      list_push_tail(v10, v3);
      result = (unsigned __int8 *)rf_bus_mark_n100_d2d0(dword_130268);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(_DWORD *)off_130260;
        *v0 = v11;
        if ( !v11 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}

