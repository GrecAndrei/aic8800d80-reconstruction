// sub_12513C @ 0x12513c, size 328 bytes
int __fastcall sub_12513C(int a1, unsigned __int8 **a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r3
  int v8; // r6
  unsigned int v9; // r3
  int v10; // r9
  int v11; // r1
  int v12; // r2
  char v13; // r10
  int v14; // r4
  int v15; // r3
  int v16; // r7

  if ( a1 <= 2 )
  {
    msg_parse(dword_125290);
    return 1;
  }
  else
  {
    v4 = (unsigned __int16)parse_int(a2[1], nullptr, 0xAu);
    if ( a1 == 3 )
    {
      v5 = v4;
      v6 = parse_int(a2[2], nullptr, 0x10u);
    }
    else
    {
      v5 = (unsigned __int16)parse_int(a2[2], nullptr, 0xAu);
      v6 = parse_int(a2[3], nullptr, 0x10u);
    }
    v7 = *(_DWORD *)off_125288 & 0x7F;
    if ( *((_BYTE *)off_125284 + 36) == 1 )
    {
      v8 = (*(_DWORD *)off_125288 >> 11) & 6;
      if ( v8 )
      {
        v8 = *(_DWORD *)off_125288 & 0x78;
        if ( v8 )
        {
          v8 = *((unsigned __int8 *)off_125284 + 36);
        }
        else if ( v7 <= 2 )
        {
          v8 = 2;
        }
      }
      else if ( (*(_DWORD *)off_125288 & 0x78) == 0 )
      {
        v8 = 2;
      }
    }
    else if ( ((*(_DWORD *)off_125288 >> 11) & 6) != 0 )
    {
      v8 = v7 <= 4;
    }
    else
    {
      v8 = v7 <= 9;
    }
    if ( v5 > v4 )
    {
      v9 = v4;
      v4 = v5;
      v5 = v9;
    }
    v10 = (unsigned __int8)(v4 >> 5);
    v11 = (unsigned __int8)(v5 >> 5);
    if ( v10 == v11 )
    {
      sub_12419C(v8, v10, v5 & 0x1F, (1 << (v4 - v5 + 1)) - 1, v6 & ((1 << (v4 - v5 + 1)) - 1));
      goto LABEL_13;
    }
    v12 = v5 & 0x1F;
    if ( (v5 & 0x1F) != 0 )
    {
      v13 = 32 - v12;
      v14 = v4 & 0x1F;
      sub_12419C(v8, v11, v12, (1 << (32 - v12)) - 1, v6 & ((1 << (32 - v12)) - 1));
      v15 = (1 << (v14 + 1)) - 1;
      v16 = (v6 >> v13) & v15;
      if ( v14 != 31 )
      {
        sub_12419C(v8, v10, 0, v15, v16);
LABEL_13:
        msg_parse(dword_12528C);
        return 0;
      }
      msg_parse(dword_125298);
      return 1;
    }
    else
    {
      msg_parse(dword_125294);
      return 1;
    }
  }
}

