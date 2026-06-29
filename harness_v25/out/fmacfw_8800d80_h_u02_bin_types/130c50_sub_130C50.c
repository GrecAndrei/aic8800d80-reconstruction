// sub_130C50 @ 0x130c50, size 38 bytes
int  sub_130C50(int a1, int a2, __int16 a3)
{
  __int16 v3; // r3
  int v4; // r1
  __int16 v5; // r3

  *(uint8_t *)a1 = 3;
  *(uint8_t *)(a1 + 1) = 2;
  v3 = *(unsigned __int8 *)(a2 + 22);
  v4 = *(unsigned __int8 *)(a2 + 17);
  *(uint16_t *)(a1 + 4) = a3;
  v5 = v3 << 12;
  if ( v4 == 1 )
    v5 |= 0x800u;
  *(uint16_t *)(a1 + 2) = v5;
  return 6;
}

