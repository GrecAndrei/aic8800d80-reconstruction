// fwstruct annotate: 130030_sub_130030.c
// sub_130030 @ 0x130030, size 238 bytes
unsigned __int8 *sub_130030()
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
    *(_DWORD *)off_130120 = 1;
  }
  v0 = (int *)off_130124;
  v1 = dword_130128;
  ++*(_DWORD *)off_130124;
  result = (unsigned __int8 *)sub_12D190(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(_DWORD *)off_130120;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (_DWORD *)dword_13012C;
    v7 = dword_130140;
    v8 = dword_130144;
    do
    {
      v9 = sub_12F5BC(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = sub_12F648(v15[0], v6, 7);
        if ( v13 )
        {
          if ( *((__int16 *)v13 + 5) < v9 || *((__int16 *)v13 + 4) > v9 )
          {
            sub_10DAE4(v7, *v13, v13[1]);
          }
          else
          {
            v14 = ((int (__fastcall *)(int, int *))v13[3])(v9, v15);
            if ( v14 )
              sub_10DAE4(v8, v14);
          }
        }
        else
        {
          sub_10DAE4(dword_13013C, v15[0]);
        }
      }
      else
      {
        sub_10D674((_BYTE *)dword_130130);
      }
      sub_10D674((_BYTE *)dword_130134);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_130120 = 1;
      }
      v10 = dword_130138;
      ++*v0;
      sub_12D108(v10, v3);
      result = (unsigned __int8 *)sub_12D190(dword_130128);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(_DWORD *)off_130120;
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

