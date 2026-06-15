// v23 annotated: fw_init_vif_struct @ 0x105abc
// Original: 105abc_fw_init_vif_struct.c
// Primary struct: <unclustered>
//
// fw_init_vif_struct @ 0x105abc, size 206 bytes
// Doc: fw_init_vif_struct [mac]: Initialize VIF control struct at offset 0x274
// fw_init_vif_struct [mac]: Initialize VIF control struct at offset 0x274
int __fastcall fw_init_vif_struct(unsigned int a1, int a2, int a3)
{
  int v5; // r5
  int v6; // r8
  int v7; // r10
  int v8; // r7
  int v9; // r9
  int result; // r0
  int v11; // r1
  int v12; // r2
  unsigned int v13; // r0
  int v14; // r2
  int v15; // r2
  int v16; // r1

  v5 = 0;
  *(_QWORD *)(a2 + 628) = 0x40000000FLL;
  *(_DWORD *)(a2 + 624) = 0;
  v6 = dword_105B98;
  v7 = dword_105B9C;
  if ( a3 )
    v8 = 7;
  else
    v8 = 4;
  if ( a3 )
    v9 = 15;
  else
    v9 = 13;
  result = feature_guard_check(1, dword_105B8C);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v5) & a1) >> v5 == 1 )
      {
        *(_DWORD *)(a2 + 4 * (*(_DWORD *)(a2 + 624) + 148)) = v5;
        feature_guard_check(1, v6);
        v13 = ((1 << v5) & a1) >> v5;
        v14 = *(_DWORD *)(a2 + 4 * (*(_DWORD *)(a2 + 624) + 148));
        if ( v14 < v8 )
        {
          result = feature_guard_check(v13, v7);
          v12 = *(_DWORD *)(a2 + 624);
          if ( !v12 )
          {
            v12 = *(_DWORD *)(a2 + 592);
            *(_DWORD *)(a2 + 632) = v12;
          }
        }
        else if ( v14 > v9 )
        {
          result = feature_guard_check(v13, v7);
          v12 = *(_DWORD *)(a2 + 624);
          if ( !v12 )
          {
            v12 = *(_DWORD *)(a2 + 592);
            *(_DWORD *)(a2 + 628) = v12;
          }
        }
        else
        {
          result = feature_guard_check(v13, dword_105B94);
          v15 = *(_DWORD *)(a2 + 624);
          v16 = v15 + 148;
          v12 = v15 + 1;
          v11 = *(_DWORD *)(a2 + 4 * v16);
          *(_DWORD *)(a2 + 624) = v12;
          *(_DWORD *)(a2 + 628) = v11;
        }
      }
    }
    else
    {
      result = msg_parse(dword_105B90, v11, v12);
    }
    ++v5;
  }
  while ( v5 != 16 );
  return result;
}

