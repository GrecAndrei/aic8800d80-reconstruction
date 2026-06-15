// v23 annotated: sub_1256E0 @ 0x1256e0
// Original: 1256e0_sub_1256E0.c
// Primary struct: <unclustered>
//
// sub_1256E0 @ 0x1256e0, size 592 bytes
int __fastcall sub_1256E0(int a1, unsigned __int8 **a2)
{
  int v4; // r0
  int v5; // r5
  _BYTE *v6; // r7
  int v7; // r5
  int v8; // r0
  int v9; // r6
  unsigned __int8 *v10; // r0
  unsigned __int16 *v11; // r4
  int v12; // r0
  int v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r2
  _BYTE *v17; // r7
  int v18; // r5
  int v19; // r0
  int v20; // r6
  unsigned __int8 *v21; // r0
  _BYTE *v22; // r4
  int v23; // r0
  int v24; // r3
  unsigned int v25; // r1
  int v26; // r2
  _DWORD *v28; // r8
  int v29; // r7
  int i; // r4
  int v31; // r1
  _DWORD *v32; // r7
  int v33; // r9
  int v34; // r6
  int j; // r8
  int k; // r4
  int v37; // r1

  v4 = parse_int(a2[1], nullptr, 0);
  v5 = v4;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v17 = off_125930;
      ++*(_BYTE *)off_125930;
      if ( a1 <= 4 )
      {
LABEL_50:
        msg_parse(dword_125968);
        return -1;
      }
      v18 = parse_int(a2[2], nullptr, 0);
      v19 = parse_int(a2[3], nullptr, 0);
      v20 = v19;
      if ( v18 > 2 || v19 > 2 )
      {
LABEL_49:
        msg_parse(dword_125964);
        return -1;
      }
      v21 = a2[4];
      v22 = off_125934;
      v23 = parse_int(v21, nullptr, 0);
      v24 = -7;
      if ( v23 > -7 )
        v24 = v23;
      if ( v24 >= 7 )
        LOBYTE(v24) = 7;
      *(_BYTE *)(3 * v18 + *(_DWORD *)off_12593C + v20) = v24;
      v25 = *((unsigned __int16 *)v22 + 20);
      if ( v25 > 0x97B )
      {
        if ( v25 > 0x994 )
          v26 = 2;
        else
          v26 = 1;
      }
      else
      {
        v26 = 0;
      }
      if ( !v22[36] && v26 == v20 )
      {
        mmio_set_bit_120090C(0, v25);
        ++*v17;
      }
      msg_parse(dword_125940, v18, v20);
      return 0;
    }
    else
    {
      if ( v4 == 2 )
      {
        v6 = off_125930;
        ++*(_BYTE *)off_125930;
        if ( a1 > 4 )
        {
          v7 = parse_int(a2[2], nullptr, 0);
          v8 = parse_int(a2[3], nullptr, 0);
          v9 = v8;
          if ( v7 <= 2 && v8 <= 5 )
          {
            v10 = a2[4];
            v11 = (unsigned __int16 *)off_125934;
            v12 = parse_int(v10, nullptr, 0);
            v13 = -7;
            if ( v12 > -7 )
              v13 = v12;
            if ( v13 >= 7 )
              LOBYTE(v13) = 7;
            *(_BYTE *)(*(_DWORD *)off_125938 + 6 * v7 + v9) = v13;
            v14 = v11[20];
            v15 = *((unsigned __int8 *)v11 + 36);
            if ( v14 > 0x1666 )
            {
              v16 = 5;
            }
            else
            {
              if ( v14 > 0x1616 )
              {
                v16 = 4;
                if ( v15 != 1 )
                  goto LABEL_40;
                goto LABEL_45;
              }
              if ( v14 > 0x15C6 )
              {
                v16 = 3;
              }
              else if ( v14 <= 0x1571 )
              {
                v16 = v14 > 0x1486;
              }
              else
              {
                v16 = 2;
              }
            }
            if ( v15 != 1 )
            {
LABEL_40:
              msg_parse(dword_125960, v7, v9);
              return 0;
            }
LABEL_45:
            if ( v16 == v9 )
            {
              mmio_set_bit_120090C(v15, v14);
              ++*v6;
            }
            goto LABEL_40;
          }
          goto LABEL_49;
        }
        goto LABEL_50;
      }
      msg_parse(dword_12596C);
      return -1;
    }
  }
  else
  {
    v28 = off_12593C;
    v29 = dword_125948;
    msg_parse(dword_125944);
    msg_parse(dword_12594C);
    do
    {
      msg_parse(dword_125950, v5);
      for ( i = 0; i != 3; ++i )
      {
        v31 = *(char *)(*v28 + 3 * v5 + i);
        msg_parse(v29, v31);
      }
      ++v5;
    }
    while ( v5 != 3 );
    v32 = off_125938;
    v33 = dword_125950;
    v34 = dword_125948;
    msg_parse(dword_125954);
    msg_parse(dword_125958);
    for ( j = 0; j != 3; ++j )
    {
      msg_parse(v33, j);
      for ( k = 0; k != 6; ++k )
      {
        v37 = *(char *)(*v32 + 6 * j + k);
        msg_parse(v34, v37);
      }
    }
    msg_parse(dword_12595C);
    return 0;
  }
}

