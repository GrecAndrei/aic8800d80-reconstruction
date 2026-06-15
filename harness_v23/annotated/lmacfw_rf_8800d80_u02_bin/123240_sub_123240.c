// v23 annotated: sub_123240 @ 0x123240
// Original: 123240_sub_123240.c
// Primary struct: <unclustered>
//
// sub_123240 @ 0x123240, size 238 bytes
// Doc: sub_1223240 [unknown]: Helper routine with large stack frame and shifted operand
// sub_1223240 [unknown]: Helper routine with large stack frame and shifted operand
unsigned __int8 *sub_123240()
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
    *(_DWORD *)off_123330 = 1;
  }
  v0 = (int *)off_123334;
  v1 = dword_123338;
  ++*(_DWORD *)off_123334;
  result = (unsigned __int8 *)sub_11E7AC(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(_DWORD *)off_123330;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (_DWORD *)dword_12333C;
    v7 = dword_123350;
    v8 = dword_123354;
    do
    {
      v9 = sub_121BE0(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = sub_121C6C(v15[0], v6, 55);
        if ( v13 )
        {
          if ( *((__int16 *)v13 + 5) < v9 || *((__int16 *)v13 + 4) > v9 )
          {
            sub_10DA6C(v7, *v13, v13[1]);
          }
          else
          {
            v14 = ((int (__fastcall *)(int, int *))v13[3])(v9, v15);
            if ( v14 )
              sub_10DA6C(v8, v14);
          }
        }
        else
        {
          sub_10DA6C(dword_12334C, v15[0]);
        }
      }
      else
      {
        uart_puts((_BYTE *)dword_123340);
      }
      uart_puts((_BYTE *)dword_123344);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_123330 = 1;
      }
      v10 = dword_123348;
      ++*v0;
      list_push_tail(v10, v3);
      result = (unsigned __int8 *)sub_11E7AC(dword_123338);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(_DWORD *)off_123330;
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

