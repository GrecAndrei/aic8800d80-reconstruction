// sub_12D3E0 @ 0x12d3e0, size 110 bytes
int  sub_12D3E0(int a1)
{
  int v1; // r5
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  unsigned int v7; // r0
  uint32_t v9[32]; // [sp+0h] [bp-104h] BYREF
  uint8_t v10[132]; // [sp+80h] [bp-84h] BYREF

  v1 = dword_12D458;
  sub_143630(v9, dword_12D458, 128);
  sub_143630(v10, v1 + 128, 128);
  v3 = sub_1428B8(a1);
  v4 = sub_142968(v3, HIDWORD(v3), dword_12D450, dword_12D454);
  v5 = sub_142968(v4, HIDWORD(v4), 0, dword_12D45C);
  v6 = sub_1425FC(v5, HIDWORD(v5), 0, dword_12D460);
  v7 = sub_142E9C(v6, HIDWORD(v6));
  return v7 & 0x7F800000
       | ((((v7 & 0x7FFFFF) * (uint64_t)(int)v9[(v7 >> 18) & 0x1F]) >> 23) + *(uint32_t *)&v10[4 * ((v7 >> 18) & 0x1F)]);
}

