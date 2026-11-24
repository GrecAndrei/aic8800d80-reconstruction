// sub_1053C0 @ 0x1053c0, size 190 bytes
int __fastcall sub_1053C0(unsigned int a1, _DWORD *a2)
{
  int v4; // r1
  int result; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r7
  int v9; // r9
  int v10; // r8
  int v11; // r5
  int v12; // r3
  int v13; // r3
  int v14; // r2
  unsigned int v15; // r0
  int v16; // r3
  int v17; // r2

  *(_DWORD *)(a2 + 0x38) = 0;
  *(_DWORD *)(a2 + 0x3c) = 15;
  v4 = dword_105480;
  *(_DWORD *)(a2 + 0x40) = 8;
  result = sub_11F74C(1, v4, a1, 8);
  if ( a1 )
  {
    v8 = dword_105484;
    v9 = dword_10548C;
    v10 = dword_105490;
    v11 = 20;
    while ( 1 )
    {
      while ( ((1 << v11) & a1) >> v11 != 1 )
      {
LABEL_3:
        if ( ++v11 == 28 )
          return result;
      }
      v12 = *(_DWORD *)(a2 + 0x38) + 10;
      a2[v12] = v11 - 12;
      sub_11F74C(1, v8, v11 - 12, v12);
      v13 = *(_DWORD *)(a2 + 0x38) + 10;
      v14 = a2[v13];
      if ( v14 <= 7 )
      {
        result = sub_11F74C(((1 << v11) & a1) >> v11, v9, v14, v13);
        if ( !*(_DWORD *)(a2 + 0x38) )
          *(_DWORD *)(a2 + 0x40) = *(_DWORD *)(a2 + 0x28);
        goto LABEL_3;
      }
      v15 = ((1 << v11) & a1) >> v11;
      if ( v14 > 15 )
      {
        result = sub_11F74C(v15, v9, v14, v13);
        if ( !*(_DWORD *)(a2 + 0x38) )
          *(_DWORD *)(a2 + 0x3c) = *(_DWORD *)(a2 + 0x28);
        goto LABEL_3;
      }
      result = sub_11F74C(v15, v10, v14, v13);
      v16 = *(_DWORD *)(a2 + 0x38);
      ++v11;
      v17 = a2[v16 + 10];
      *(_DWORD *)(a2 + 0x38) = v16 + 1;
      *(_DWORD *)(a2 + 0x3c) = v17;
      if ( v11 == 28 )
        return result;
    }
  }
  return sub_11F74C(1, dword_105488, v6, v7);
}

