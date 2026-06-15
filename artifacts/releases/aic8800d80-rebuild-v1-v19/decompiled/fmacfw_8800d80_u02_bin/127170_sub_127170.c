// sub_127170 @ 0x127170, size 266 bytes
int __fastcall sub_127170(int result)
{
  _BYTE *v1; // r5
  __int64 v2; // r6
  int v3; // r4
  char v4; // r3
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r3
  int v10; // r11
  int v11; // r1
  int v12; // r0

  v1 = off_127284;
  LODWORD(v2) = result;
  HIDWORD(v2) = *((_DWORD *)off_12727C + 4) + *(_DWORD *)(result + 20);
  if ( result != dword_127280 || (*((_BYTE *)off_127284 + 88) & 4) != 0 )
  {
    if ( *((_DWORD *)off_127284 + 10) != result )
    {
      result = sub_1019F0();
      HIDWORD(v2) += 4000 + result;
    }
    v3 = (unsigned __int8)v1[91];
    v4 = v1[88];
    *((_QWORD *)v1 + 10) = v2;
    if ( v3 )
    {
      v1[88] = v4 | 0x40;
    }
    else
    {
      v1[88] = v4 & 0xBF;
      bt_event_handler();
      result = sub_126714(SHIDWORD(v2), 0, 0);
      v5 = *((_DWORD *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_127298;
        v7 = dword_12729C;
        v8 = dword_127288 - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(_DWORD *)(v5 + 4);
          result = v10 - sub_1019F0();
          if ( result + v8 >= 0 )
            break;
          v11 = *(_DWORD *)(v5 + 4);
          v12 = v6 + 1320 * *(unsigned __int8 *)(v5 + 8);
          v9 = 102400;
          if ( *(_BYTE *)(v12 + 106) )
          {
            if ( *(_BYTE *)(v12 + 106) == 2 )
              v9 = *(unsigned __int16 *)(v12 + 222) << 10;
            result = sub_126584(v12, v11 + v9, 0);
            v5 = *((_DWORD *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = sub_126584(v12, v11 + *(_DWORD *)(v7 + 696 * *(unsigned __int8 *)(v12 + 116) + 8), 0);
            v5 = *((_DWORD *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((_DWORD *)v1 + 11) )
      {
        if ( **(__int16 **)off_12728C < 0 && (v1[88] & 0xC) == 0 )
          return sub_12F46C(dword_127294, dword_127290, 1698);
      }
      else
      {
        return sub_1270CC(v2);
      }
    }
  }
  else
  {
    *((_BYTE *)off_127284 + 88) &= ~0x40u;
  }
  return result;
}

