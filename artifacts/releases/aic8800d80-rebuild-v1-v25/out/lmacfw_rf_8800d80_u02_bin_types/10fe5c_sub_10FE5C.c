// sub_10FE5C @ 0x10fe5c, size 66 bytes
int  sub_10FE5C(int a1, int a2, int a3)
{
  uint32_t *v3; // r3
  uint32_t *v4; // r3

  v3 = off_10FEA0;
  *((uint32_t *)off_10FEA0 + 3) = dword_10FEA4;
  *v3 = a2;
  v3[1] = a3;
  *((uint8_t *)v3 + 8) = 4;
  sub_10F814(v3, a1, 0x20u);
  v4 = off_10FEA8;
  *((uint32_t *)off_10FEA8 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((uint16_t *)v4 + 14) = 0;
  return 0x40000;
}

