// sub_138890 @ 0x138890, size 136 bytes
_DWORD *__fastcall sub_138890(int a1, __int16 a2, int a3)
{
  _BYTE *v3; // r5
  int v4; // r4
  int v5; // r3
  _DWORD *v6; // r6
  int v7; // r7
  int v8; // r12
  int v9; // r3

  v3 = off_13891C;
  v4 = *((unsigned __int8 *)off_13891C + 68);
  v5 = dword_138920;
  v6 = (_DWORD *)(dword_138920 + 80 * v4);
  if ( **(__int16 **)off_138918 < 0 )
  {
    v7 = 4 * v4;
    if ( *(_WORD *)(dword_138920 + 80 * v4 + 76) )
    {
      sub_12F2C8(dword_138930, dword_13892C, 175);
      return nullptr;
    }
  }
  else
  {
    v7 = 4 * v4;
  }
  v8 = dword_138920 + 16 * (v7 + v4);
  *(_DWORD *)(v8 + 12) = a1;
  if ( a1 )
    *(_BYTE *)(v8 + 16) = *(_BYTE *)(a1 + 16);
  v9 = v5 + 16 * (v4 + v7);
  *(_DWORD *)(v9 + 68) = a3;
  *(_WORD *)(v9 + 76) = a2;
  sub_12D108(dword_138924, v6);
  v3[68] = v3[68]
         + 1
         - -64
         * ((unsigned int)(((unsigned int)dword_138928 * (unsigned __int64)((unsigned int)(unsigned __int8)v3[68] + 1)) >> 32) >> 7);
  return v6;
}

