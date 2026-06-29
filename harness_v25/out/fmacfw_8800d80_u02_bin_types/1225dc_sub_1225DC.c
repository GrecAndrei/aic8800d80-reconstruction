// sub_1225DC @ 0x1225dc, size 30 bytes
int  sub_1225DC(char a1, char a2)
{
  uint8_t *v4; // r0

  v4 = (uint8_t *)sub_12C92C(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return sub_12C98C(v4);
}

