// sub_118800 @ 0x118800, size 172 bytes
int __fastcall sub_118800(int a1, int a2, int a3)
{
  __int16 **v3; // r8
  int v4; // r10
  int v5; // r9
  int v9; // r4
  int v10; // r1

  v3 = (__int16 **)off_1188AC;
  v4 = dword_1188B0;
  v5 = dword_1188B4;
  while ( 1 )
  {
    v9 = sub_12D190(a2);
    if ( !v9 )
      break;
    while ( 1 )
    {
      v10 = *(_DWORD *)(v9 + 76);
      if ( *(_DWORD *)(v9 + 68) )
      {
        *(_DWORD *)(v10 + 4) = 2080374784;
      }
      else if ( *(int *)(v10 + 4) >= 0 )
      {
        *(_DWORD *)(v10 + 4) = 0x40000000;
      }
      if ( *(_WORD *)(v9 + 4) )
        break;
      sub_118BA0(v9);
      v9 = sub_12D190(a2);
      if ( !v9 )
        return sub_118BE8();
    }
    *(_DWORD *)(v10 + 4) |= 0x800000u;
    sub_117BF0(v9, (_DWORD *)(v10 + 4));
    sub_115F4C(v9);
    if ( sub_13AE40(v9, 1) )
    {
      if ( **v3 < 0 && !a3 )
        sub_12F32C(v5, v4, 1105);
      sub_12D108(a3);
    }
    else
    {
      sub_12F4B4(a1, v9);
    }
  }
  return sub_118BE8();
}

