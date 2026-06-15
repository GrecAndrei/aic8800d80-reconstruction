// v23 annotated: sub_12202C @ 0x12202c
// Original: 12202c_sub_12202C.c
// Primary struct: <unclustered>
//
// sub_12202C @ 0x12202c, size 220 bytes
// Doc: rf_cmd_dispatch_n146 [rf]: Dispatch queued RF command to handler
// rf_cmd_dispatch_n146 [rf]: Dispatch queued RF command to handler
int __fastcall sub_12202C(int a1, int a2)
{
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r7
  unsigned int v11; // r4
  int v13; // r0

  v4 = rf_cmd_dispatch_n_34(*(_DWORD *)a2);
  if ( v4 >= 0 )
  {
    v5 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
    v6 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
    if ( a1 > 3 )
    {
      v13 = parse_int(*(unsigned __int8 **)(a2 + 12), nullptr, 0);
      if ( !v13 )
        return 0;
      v7 = v13 - 1;
    }
    else
    {
      v7 = 0;
    }
    v8 = dword_122114;
    v9 = dword_122118;
    v10 = dword_122108;
    do
    {
      while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
      {
        v11 = v5 & 0xFFFFFFFC;
        sub_10DA6C(dword_12210C, v11, v6);
        --v7;
        sub_10EFAC();
        v5 = v11 + v4;
        if ( v7 == -1 )
          return 0;
      }
      switch ( v4 )
      {
        case 4:
          sub_10DA6C(v10, v5, v6);
          *(_DWORD *)v5 = v6;
          break;
        case 2:
          sub_10DA6C(v9, v5);
          *(_WORD *)v5 = v6;
          break;
        case 1:
          sub_10DA6C(v8, v5, (unsigned __int8)v6);
          *(_BYTE *)v5 = v6;
          break;
      }
      --v7;
      v5 += v4;
    }
    while ( v7 != -1 );
    return 0;
  }
  sub_10DA6C(dword_122110, v4);
  return -1;
}

