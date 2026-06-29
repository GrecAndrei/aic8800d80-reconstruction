// sub_136E10 @ 0x136e10, size 48 bytes
int  sub_136E10(int a1, int a2, int a3, __int16 a4)
{
  uint8_t *v5; // r4

  v5 = (uint8_t *)sub_12C7EC(4104, a4, 4, 2u);
  sub_12EB90(8, dword_136E40);
  *v5 = 1;
  v5[1] = *(uint8_t *)(a2 + 2);
  sub_12C84C((int)v5);
  return 0;
}

