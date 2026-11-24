// sub_1058D0 @ 0x1058d0, size 190 bytes
int __fastcall sub_1058D0(unsigned int a1, _DWORD *a2)
{
  int v4; // r1
  int result; // r0
  int v6; // r7
  int v7; // r9
  int v8; // r8
  int v9; // r5
  int v10; // r2
  unsigned int v11; // r0
  int v12; // r3
  int v13; // r2

  *(_DWORD *)(a2 + 0x38) = 0;
  *(_DWORD *)(a2 + 0x3c) = 15;
  v4 = dword_105990;
  *(_DWORD *)(a2 + 0x40) = 8;
  result = sub_12EB90(1, v4);
  if ( a1 )
  {
    v6 = dword_105994;
    v7 = dword_10599C;
    v8 = dword_1059A0;
    v9 = 20;
    while ( 1 )
    {
      while ( ((1 << v9) & a1) >> v9 != 1 )
      {
LABEL_3:
        if ( ++v9 == 28 )
          return result;
      }
      a2[*(_DWORD *)(a2 + 0x38) + 10] = v9 - 12;
      sub_12EB90(1, v6);
      v10 = a2[*(_DWORD *)(a2 + 0x38) + 10];
      if ( v10 <= 7 )
      {
        result = sub_12EB90(((1 << v9) & a1) >> v9, v7);
        if ( !*(_DWORD *)(a2 + 0x38) )
          *(_DWORD *)(a2 + 0x40) = *(_DWORD *)(a2 + 0x28);
        goto LABEL_3;
      }
      v11 = ((1 << v9) & a1) >> v9;
      if ( v10 > 15 )
      {
        result = sub_12EB90(v11, v7);
        if ( !*(_DWORD *)(a2 + 0x38) )
          *(_DWORD *)(a2 + 0x3c) = *(_DWORD *)(a2 + 0x28);
        goto LABEL_3;
      }
      result = sub_12EB90(v11, v8);
      v12 = *(_DWORD *)(a2 + 0x38);
      ++v9;
      v13 = a2[v12 + 10];
      *(_DWORD *)(a2 + 0x38) = v12 + 1;
      *(_DWORD *)(a2 + 0x3c) = v13;
      if ( v9 == 28 )
        return result;
    }
  }
  return sub_12EB90(1, dword_105998);
}

