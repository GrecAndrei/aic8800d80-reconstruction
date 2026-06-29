// sub_12D748 @ 0x12d748, size 110 bytes
// Doc: sub_122D748 [util]: Initialize 256-byte buffer from ROM constant and call helper
// sub_122D748 [util]: Initialize 256-byte buffer from ROM constant and call helper
int  sub_12D748(int a1)
{
  int v1; // r5
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  unsigned int v7; // r0
  uint32_t v9[32]; // [sp+0h] [bp-104h] BYREF
  uint8_t v10[132]; // [sp+80h] [bp-84h] BYREF

  v1 = dword_12D7C0;
  sub_14380C(v9, dword_12D7C0, 128);
  sub_14380C(v10, v1 + 128, 128);
  v3 = sub_142A94(a1);
  v4 = sub_142B44(v3, HIDWORD(v3), dword_12D7B8, dword_12D7BC);
  v5 = sub_142B44(v4, HIDWORD(v4), 0, dword_12D7C4);
  v6 = sub_1427D8(v5, HIDWORD(v5), 0, dword_12D7C8);
  v7 = sub_143078(v6, HIDWORD(v6));
  return v7 & 0x7F800000
       | ((((v7 & 0x7FFFFF) * (uint64_t)(int)v9[(v7 >> 18) & 0x1F]) >> 23) + *(uint32_t *)&v10[4 * ((v7 >> 18) & 0x1F)]);
}

