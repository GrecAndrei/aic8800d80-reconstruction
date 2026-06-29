// sub_12C8E0 @ 0x12c8e0, size 22 bytes
int  sub_12C8E0(int a1, __int16 a2, __int16 a3, __int16 a4)
{
  *(uint16_t *)(a1 - 8) = a2;
  *(uint16_t *)(a1 - 6) = a3;
  *(uint16_t *)(a1 - 4) = a4;
  return sub_12C84C(a1);
}

