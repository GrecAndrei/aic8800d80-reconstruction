// v23 annotated: sub_105494 @ 0x105494
// Original: 105494_sub_105494.c
// Primary struct: <unclustered>
//
// sub_105494 @ 0x105494, size 206 bytes
int __fastcall sub_105494(unsigned int a1, int a2, int a3, int a4)
{
  int v6; // r5
  int v7; // r8
  int v8; // r10
  int v9; // r7
  int v10; // r9
  int result; // r0
  int v12; // r1
  int v13; // r3
  int v14; // r3
  unsigned int v15; // r0
  int v16; // r2
  int v17; // r2

  v6 = 0;
  *(_QWORD *)(a2 + 628) = 0x40000000FLL;
  *(_DWORD *)(a2 + 624) = 0;
  v7 = dword_105570;
  v8 = dword_105574;
  if ( a3 )
    v9 = 7;
  else
    v9 = 4;
  if ( a3 )
    v10 = 15;
  else
    v10 = 13;
  result = sub_11F74C(1, dword_105564, a1, a4);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v6) & a1) >> v6 == 1 )
      {
        *(_DWORD *)(a2 + 4 * (*(_DWORD *)(a2 + 624) + 148)) = v6;
        sub_11F74C(1, v7, v6, v13);
        v15 = ((1 << v6) & a1) >> v6;
        v16 = *(_DWORD *)(a2 + 4 * (*(_DWORD *)(a2 + 624) + 148));
        if ( v16 < v9 )
        {
          result = sub_11F74C(v15, v8, v16, v14);
          if ( !*(_DWORD *)(a2 + 624) )
            *(_DWORD *)(a2 + 632) = *(_DWORD *)(a2 + 592);
        }
        else if ( v16 > v10 )
        {
          result = sub_11F74C(v15, v8, v16, v14);
          if ( !*(_DWORD *)(a2 + 624) )
            *(_DWORD *)(a2 + 628) = *(_DWORD *)(a2 + 592);
        }
        else
        {
          result = sub_11F74C(v15, dword_10556C, v16, v14);
          v17 = *(_DWORD *)(a2 + 624);
          v12 = *(_DWORD *)(a2 + 4 * (v17 + 148));
          *(_DWORD *)(a2 + 624) = v17 + 1;
          *(_DWORD *)(a2 + 628) = v12;
        }
      }
    }
    else
    {
      result = msg_parse(dword_105568, v12);
    }
    ++v6;
  }
  while ( v6 != 16 );
  return result;
}

