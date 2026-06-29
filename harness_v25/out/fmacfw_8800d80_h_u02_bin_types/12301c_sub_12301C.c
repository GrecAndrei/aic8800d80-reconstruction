// sub_12301C @ 0x12301c, size 50 bytes
int  sub_12301C(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (uint8_t *)sub_12C7EC(129, a4, a3, 64);
  v5 = dword_123050;
  *v4 = 0;
  sub_143630(v4 + 1, v5, 36);
  v6 = (unsigned __int8)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  sub_12C84C(v4);
  return 0;
}

