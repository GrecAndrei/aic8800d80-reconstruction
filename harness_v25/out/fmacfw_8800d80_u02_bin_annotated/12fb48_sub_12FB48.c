// fwstruct annotate: 12fb48_sub_12FB48.c
// sub_12FB48 @ 0x12fb48, size 220 bytes
int __fastcall sub_12FB48(int a1, int a2)
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

  v4 = parse_width_suffix(*(_DWORD *)a2);
  if ( v4 >= 0 )
  {
    v5 = sub_12F958(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
    v6 = sub_12F958(*(unsigned __int8 **)(a2 + 8), nullptr, 0x10u);
    if ( a1 > 3 )
    {
      v13 = sub_12F958(*(unsigned __int8 **)(a2 + 12), nullptr, 0);
      if ( !v13 )
        return 0;
      v7 = v13 - 1;
    }
    else
    {
      v7 = 0;
    }
    v8 = dword_12FC30;
    v9 = dword_12FC34;
    v10 = dword_12FC24;
    do
    {
      while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
      {
        v11 = v5 & 0xFFFFFFFC;
        sub_10DC24(dword_12FC28, v11, v6);
        --v7;
        rf_reg_ack_cb();
        v5 = v11 + v4;
        if ( v7 == -1 )
          return 0;
      }
      switch ( v4 )
      {
        case 4:
          sub_10DC24(v10, v5, v6);
          *(_DWORD *)v5 = v6;
          break;
        case 2:
          sub_10DC24(v9, v5);
          *(_WORD *)v5 = v6;
          break;
        case 1:
          sub_10DC24(v8, v5, (unsigned __int8)v6);
          *(_BYTE *)v5 = v6;
          break;
      }
      --v7;
      v5 += v4;
    }
    while ( v7 != -1 );
    return 0;
  }
  sub_10DC24(dword_12FC2C, v4);
  return -1;
}

