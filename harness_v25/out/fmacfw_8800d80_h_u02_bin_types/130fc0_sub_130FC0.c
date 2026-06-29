// sub_130FC0 @ 0x130fc0, size 72 bytes
int  sub_130FC0(uint8_t *a1, int a2, int a3)
{
  int result; // r0
  int v5; // r3
  __int16 v6; // r3
  __int16 v7; // r2

  result = (int)sub_12DBC8(a1, a2);
  if ( result )
  {
    *(uint16_t *)a3 = *(unsigned __int8 *)(result + 2) | (*(unsigned __int8 *)(result + 3) << 8);
    *(uint8_t *)(a3 + 2) = *(uint8_t *)(result + 4);
    v5 = a3 + 2;
    do
    {
      *(uint8_t *)(v5 + 1) = *(uint8_t *)(result + v5 + 3 - a3);
      ++v5;
    }
    while ( v5 != a3 + 18 );
    v6 = *(unsigned __int8 *)(result + 21);
    v7 = *(unsigned __int8 *)(result + 22);
    *(uint32_t *)(a3 + 24) = *(unsigned __int16 *)(result + 23);
    *(uint16_t *)(a3 + 20) = v6 | (v7 << 8);
    *(uint8_t *)(a3 + 28) = *(uint8_t *)(result + 27);
    return 1;
  }
  return result;
}

