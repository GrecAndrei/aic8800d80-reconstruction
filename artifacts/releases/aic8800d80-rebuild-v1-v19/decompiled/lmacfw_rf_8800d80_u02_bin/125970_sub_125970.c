// sub_125970 @ 0x125970, size 294 bytes
int __fastcall sub_125970(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  char v6; // r1
  int v7; // r0
  _BYTE *v9; // r7
  int v10; // r0
  unsigned __int16 *v11; // r2
  int v12; // r3
  int v13; // r4
  _BYTE *v14; // r7
  int v15; // r0
  unsigned __int16 *v16; // r2
  int v17; // r3
  int v18; // r4

  v4 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
  switch ( v4 )
  {
    case 0:
      msg_parse(dword_125AAC, *(char *)off_125A98, *((char *)off_125A98 + 1), *((char *)off_125A98 + 2));
      return 0;
    case 1:
      v9 = off_125AA0;
      ++*(_BYTE *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v10 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      v11 = (unsigned __int16 *)off_125AA4;
      v12 = *((unsigned __int8 *)off_125AA4 + 36);
      if ( v10 < -7 )
        v10 = -7;
      if ( v10 >= 7 )
        v10 = 7;
      v13 = v10;
      *(_BYTE *)off_125A98 = v10;
      if ( !v12 )
      {
        mmio_set_bit_120090C(0, v11[20]);
        ++*v9;
      }
      msg_parse(dword_125AA8, v13);
      return 0;
    case 2:
      v14 = off_125AA0;
      ++*(_BYTE *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v15 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      v16 = (unsigned __int16 *)off_125AA4;
      v17 = *((unsigned __int8 *)off_125AA4 + 36);
      if ( v15 < -7 )
        v15 = -7;
      if ( v15 >= 7 )
        v15 = 7;
      v18 = v15;
      *((_BYTE *)off_125A98 + 1) = v15;
      if ( v17 == 1 )
      {
        mmio_set_bit_120090C(1, v16[20]);
        ++*v14;
      }
      msg_parse(dword_125AB0, v18);
      return 0;
    case 3:
      if ( a1 > 2 )
      {
        v5 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
        if ( v5 < -7 )
          v5 = -7;
        v6 = v5;
        if ( v5 >= 7 )
          v6 = 7;
        v7 = dword_125A9C;
        *((_BYTE *)off_125A98 + 2) = v6;
        msg_parse(v7);
        return 0;
      }
LABEL_28:
      msg_parse(dword_125AB4);
      return -1;
    default:
      msg_parse(dword_125AB8);
      return -1;
  }
}

