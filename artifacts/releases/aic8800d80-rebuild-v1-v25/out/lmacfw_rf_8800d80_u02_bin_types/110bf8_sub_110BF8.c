// sub_110BF8 @ 0x110bf8, size 118 bytes
int  sub_110BF8(char a1, int a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = sub_10FEAC(4);
  if ( !v6 )
    return sub_10DA6C(dword_110C78);
  v7 = v6;
  v8 = (uint32_t *)sub_1101AC();
  if ( v8 )
  {
    *(uint8_t *)v7 = a3;
    *((uint8_t *)v7 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v7 + 2) = a1;
    *((uint8_t *)v7 + 3) = 0;
    sub_1282E8(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_110C70;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (unsigned __int16)(a3 + 4) | v10 & v9 | 0x80000000;
    return sub_110B64((int)v8);
  }
  else
  {
    sub_10DA6C(dword_110C74);
    return sub_10FEF8(v7);
  }
}

