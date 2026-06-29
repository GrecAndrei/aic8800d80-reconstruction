// sub_12249C @ 0x12249c, size 30 bytes
int  sub_12249C(char a1, char a2)
{
  uint8_t *v4; // r0

  v4 = (uint8_t *)sub_12C7EC(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return sub_12C84C(v4);
}

