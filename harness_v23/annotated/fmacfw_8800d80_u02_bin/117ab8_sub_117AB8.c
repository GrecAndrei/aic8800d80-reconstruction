// v23 annotated: sub_117AB8 @ 0x117ab8
// Original: 117ab8_sub_117AB8.c
// Primary struct: <unclustered>
//
// sub_117AB8 @ 0x117ab8, size 222 bytes
// Doc: sub_1217AB8 [util]: Stack-heavy helper with prologue saving many registers
// sub_1217AB8 [util]: Stack-heavy helper with prologue saving many registers
int sub_117AB8()
{
  int *v0; // r7
  _BYTE *v1; // r5
  _DWORD *v2; // r8
  _DWORD *v3; // r11
  int v4; // r10
  int *v5; // r9
  _DWORD *v6; // r6
  int i; // r4
  int v8; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r3
  int *v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117B98 = 1;
  }
  v0 = (int *)off_117B9C;
  v1 = off_117BA0;
  v2 = off_117BAC;
  v3 = off_117BB0;
  v4 = dword_117BB4;
  v5 = (int *)off_117BB8;
  ++*(_DWORD *)off_117B9C;
  v1[511] = 0;
  v6 = v2;
  for ( i = 4; i != -1; --i )
  {
    v8 = (unsigned __int8)i;
    if ( !*((_BYTE *)v6 + 158) && ((v2[52] & 1) == 0 || *((unsigned __int8 *)v2 + 190) != (unsigned __int8)i) )
    {
      if ( *((_DWORD *)v1 + 84) )
      {
        sub_1162BC((unsigned __int8)i);
        *(_DWORD *)(dword_117BA4 + 4 * i) = *v3 + *(_DWORD *)(v4 + 4 * i);
        *(_DWORD *)off_117BA8 = 1 << i;
        v8 = (unsigned __int8)i;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(_DWORD *)off_117B98 = 1;
        }
        v9 = *v0;
        v10 = *v0 + 1;
        v11 = (1 << i) | *v5;
        *v0 = v10;
        *v5 = v11;
        if ( v10 )
        {
          v12 = (int *)off_117B98;
          *v0 = v9;
          v13 = *v12;
          if ( !v9 )
          {
            if ( v13 )
              __enable_irq();
          }
        }
      }
      sub_11A7E8(v8);
    }
    v6 -= 7;
    v1 -= 84;
  }
  if ( *v0 )
  {
    v14 = *v0 - 1;
    v15 = *(_DWORD *)off_117B98;
    *v0 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return irq_nesting_or_d104(512);
}

