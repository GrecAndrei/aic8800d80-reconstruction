// sub_127030 @ 0x127030, size 266 bytes
int __fastcall sub_127030(int result)
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

  v1 = off_127144;
  LODWORD(v2) = result;
  HIDWORD(v2) = *((_DWORD *)off_12713C + 4) + *(_DWORD *)(result + 20);
  if ( result != dword_127140 || (*((_BYTE *)off_127144 + 88) & 4) != 0 )
  {
    if ( *((_DWORD *)off_127144 + 10) != result )
    {
      result = sub_101944();
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
      sub_1266A0();
      result = sub_1265D4(SHIDWORD(v2), 0, 0);
      v5 = *((_DWORD *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_127158;
        v7 = dword_12715C;
        v8 = dword_127148 - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(_DWORD *)(v5 + 4);
          result = v10 - sub_101944();
          if ( result + v8 >= 0 )
            break;
          v11 = *(_DWORD *)(v5 + 4);
          v12 = v6 + 1320 * *(unsigned __int8 *)(v5 + 8);
          v9 = 102400;
          if ( *(_BYTE *)(v12 + 106) )
          {
            if ( *(_BYTE *)(v12 + 106) == 2 )
              v9 = *(unsigned __int16 *)(v12 + 222) << 10;
            result = sub_126444(v12, v11 + v9, 0);
            v5 = *((_DWORD *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = sub_126444(v12, v11 + *(_DWORD *)(v7 + 696 * *(unsigned __int8 *)(v12 + 116) + 8), 0);
            v5 = *((_DWORD *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((_DWORD *)v1 + 11) )
      {
        if ( **(__int16 **)off_12714C < 0 && (v1[88] & 0xC) == 0 )
          return sub_12F32C(dword_127154, dword_127150, 1698);
      }
      else
      {
        return sub_126F8C(v2);
      }
    }
  }
  else
  {
    *((_BYTE *)off_127144 + 88) &= ~0x40u;
  }
  return result;
}

