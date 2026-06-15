// sub_140AE4 @ 0x140ae4, size 130 bytes
// Doc: sub_1240AE4 [util]: Check firmware state flag against value 3
// sub_1240AE4 [util]: Check firmware state flag against value 3
int __fastcall sub_140AE4(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140B68;
  v3 = *(unsigned __int8 *)(dword_140B68 + 6489);
  if ( v3 <= 3 && *(unsigned __int8 *)(dword_140B68 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(_DWORD *)(dword_140B6C + 1320 * v3 + 72);
    v7 = v5 ? *(unsigned __int8 *)(v5 + 4) : *((unsigned __int8 *)off_140B74 + 36);
    result = sub_118C44(v7 != 0, 512);
    v8 = result;
    if ( result )
    {
      *(_BYTE *)(result + 28) = *(_BYTE *)(v2 + 6489);
      *(_BYTE *)(result + 29) = *(_BYTE *)(v2 + 6488);
      *(_BYTE *)(result + 51) = 0;
      *(_BYTE *)(result + 53) = 0;
      if ( !a2 )
      {
        *(_DWORD *)(result + 88) = dword_140B70;
        *(_DWORD *)(result + 92) = result;
      }
      sub_140540(result, 1, a2, v4);
      return rf_param_get_status(v8, 3);
    }
  }
  return result;
}

