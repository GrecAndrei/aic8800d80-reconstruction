// sub_136F8C @ 0x136f8c, size 82 bytes
int  sub_136F8C(int a1, int a2, int a3, int a4)
{
  uint16_t *v4; // r2
  uint64_t v6; // r0
  uint8_t *v8; // r0
  int v9; // r0

  v4 = off_136FE0;
  *((uint16_t *)off_136FE0 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(QWORD *)(a2 + 352);
  *(uint32_t *)v4 = a2;
  *((uint32_t *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    sub_138528(v6);
    return 1;
  }
  else
  {
    v8 = (uint8_t *)sub_12C7EC(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(uint8_t *)(a2 + 366);
    v9 = sub_12C84C((int)v8);
    sub_138528(v9);
    return 1;
  }
}

