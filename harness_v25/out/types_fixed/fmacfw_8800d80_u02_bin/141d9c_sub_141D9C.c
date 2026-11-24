// sub_141D9C @ 0x141d9c, size 50 bytes
int __fastcall sub_141D9C(char a1, int a2)
{
  int v4; // r0
  __int16 v5; // r2

  v4 = sub_12C92C(12290, 13, 12, 8u);
  v5 = *(_WORD *)(a2 + 8);
  *(_DWORD *)(v4 + 2) = *(_DWORD *)(a2 + 4);
  *(_WORD *)(v4 + 6) = v5;
  *(_BYTE *)(v4 + 1) = *(_BYTE *)(a2 + 46);
  *(_BYTE *)v4 = a1;
  return sub_12C98C(v4);
}

