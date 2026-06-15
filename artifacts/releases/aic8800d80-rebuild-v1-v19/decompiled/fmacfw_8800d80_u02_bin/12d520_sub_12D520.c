// sub_12D520 @ 0x12d520, size 110 bytes
int __fastcall sub_12D520(int a1)
{
  int v1; // r5
  __int64 v3; // r0
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  unsigned int v7; // r0
  _DWORD v9[32]; // [sp+0h] [bp-104h] BYREF
  _BYTE v10[132]; // [sp+80h] [bp-84h] BYREF

  v1 = dword_12D598;
  sub_143770(v9, dword_12D598, 128);
  sub_143770(v10, v1 + 128, 128);
  v3 = sub_1429F8(a1);
  v4 = sub_142AA8(v3, HIDWORD(v3), dword_12D590, dword_12D594);
  v5 = sub_142AA8(v4, HIDWORD(v4), 0, dword_12D59C);
  v6 = sub_14273C(v5, HIDWORD(v5), 0, dword_12D5A0);
  v7 = sub_142FDC(v6, HIDWORD(v6));
  return v7 & 0x7F800000
       | ((((v7 & 0x7FFFFF) * (__int64)(int)v9[(v7 >> 18) & 0x1F]) >> 23) + *(_DWORD *)&v10[4 * ((v7 >> 18) & 0x1F)]);
}

