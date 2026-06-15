// sub_1409A4 @ 0x1409a4, size 130 bytes
int __fastcall sub_1409A4(int result, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  int v4; // r7
  int v5; // r3
  int v7; // r0
  int v8; // r4

  v2 = dword_140A28;
  v3 = *(unsigned __int8 *)(dword_140A28 + 6489);
  if ( v3 <= 3 && *(unsigned __int8 *)(dword_140A28 + 6488) <= 0x1Fu )
  {
    v4 = result;
    v5 = *(_DWORD *)(dword_140A2C + 1320 * v3 + 72);
    v7 = v5 ? *(unsigned __int8 *)(v5 + 4) : *((unsigned __int8 *)off_140A34 + 36);
    result = sub_118B04(v7 != 0, 512);
    v8 = result;
    if ( result )
    {
      *(_BYTE *)(result + 28) = *(_BYTE *)(v2 + 6489);
      *(_BYTE *)(result + 29) = *(_BYTE *)(v2 + 6488);
      *(_BYTE *)(result + 51) = 0;
      *(_BYTE *)(result + 53) = 0;
      if ( !a2 )
      {
        *(_DWORD *)(result + 88) = dword_140A30;
        *(_DWORD *)(result + 92) = result;
      }
      sub_140400(result, 1, a2, v4);
      return sub_118B34(v8, 3);
    }
  }
  return result;
}

