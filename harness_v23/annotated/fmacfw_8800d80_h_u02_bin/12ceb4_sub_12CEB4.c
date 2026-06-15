// v23 annotated: sub_12CEB4 @ 0x12ceb4
// Original: 12ceb4_sub_12CEB4.c
// Primary struct: <unclustered>
//
// sub_12CEB4 @ 0x12ceb4, size 222 bytes
int sub_12CEB4()
{
  int *v0; // r5
  int v1; // r0
  int result; // r0
  unsigned __int16 *v3; // r4
  int v4; // r3
  int v5; // r2
  int (__fastcall *v6)(_DWORD, unsigned __int16 *, _DWORD, _DWORD); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12CF94 = 1;
  }
  v0 = (int *)off_12CF98;
  v1 = dword_12CF9C;
  ++*(_DWORD *)off_12CF98;
  result = sub_12D190(v1);
  v3 = (unsigned __int16 *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(_DWORD *)off_12CF94;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int (__fastcall *)(_DWORD, unsigned __int16 *, _DWORD, _DWORD))sub_12CDEC(
                                                                           *(unsigned __int16 *)(result + 4),
                                                                           *(unsigned __int16 *)(result + 6));
    sub_12E948(dword_12CFA0, v3[2], v3[4]);
    if ( v6 )
    {
      result = v6(v3[2], v3 + 6, v3[3], v3[4]);
      if ( result == 1 )
        goto LABEL_12;
      if ( result == 2 )
      {
        result = sub_12D108(dword_12CFB0);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(__int16 **)off_12CFA4 < 0 )
          result = sub_12F32C(dword_12CFB8, dword_12CFB4, 360);
        goto LABEL_12;
      }
    }
    else
    {
      sub_12E948(dword_12CFAC, v3[2], v3[4]);
    }
    result = sub_12C8F8((int)v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12CF94 = 1;
  }
  v7 = *((_DWORD *)off_12CFA8 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = sub_12D00C(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(_DWORD *)off_12CF94;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

