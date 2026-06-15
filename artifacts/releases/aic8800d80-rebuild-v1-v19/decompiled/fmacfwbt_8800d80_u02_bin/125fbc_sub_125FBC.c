// sub_125FBC @ 0x125fbc, size 42 bytes
int __fastcall sub_125FBC(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r2

  v2 = (_BYTE *)sub_12CB54(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(_BYTE *)(a1 + 24);
  v3 = off_125FE8;
  *v2 = *(_BYTE *)(a1 + 26);
  *v3 &= ~4u;
  return sub_12CBB4(v2);
}

