// sub_1110CC @ 0x1110cc, size 118 bytes
int  sub_1110CC(char a1, int a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = sub_10FE14(4);
  if ( !v6 )
    return sub_10DA7C(dword_11114C);
  v7 = v6;
  v8 = (uint32_t *)sub_110114();
  if ( v8 )
  {
    *(uint8_t *)v7 = a3;
    *((uint8_t *)v7 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v7 + 2) = a1;
    *((uint8_t *)v7 + 3) = 0;
    sub_14380C(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_111144;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (unsigned __int16)(a3 + 4) | v10 & v9 | 0x80000000;
    return sub_110FB8((int)v8);
  }
  else
  {
    sub_10DA7C(dword_111148);
    return sub_10FE60(v7);
  }
}

