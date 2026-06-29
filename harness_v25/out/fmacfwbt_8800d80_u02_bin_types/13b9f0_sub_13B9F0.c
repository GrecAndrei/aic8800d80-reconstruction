// sub_13B9F0 @ 0x13b9f0, size 24 bytes
int  sub_13B9F0(int a1, __int16 a2, char a3)
{
  int result; // r0

  result = (*(int ( **)(int, int))a1)(a1, (a2 - *(uint16_t *)(a1 + 4)) & 0xFFF) + a1;
  *(uint8_t *)(result + 6) = a3;
  return result;
}

