// sub_116540 @ 0x116540, size 48 bytes
int __fastcall sub_116540(_BYTE *a1, char a2)
{
  int v2; // r6
  int v4; // r5

  v2 = dword_116570;
  v4 = 696 * (unsigned __int8)*(_DWORD *)(a1 + 0x74);
  *(_DWORD *)(a1 + 0x6c) = a2;
  *(_DWORD *)(a1 + 0x184) = 1;
  sub_12D108(v4 + 572 + v2);
  return sub_136A28(a1, v2 + v4);
}

