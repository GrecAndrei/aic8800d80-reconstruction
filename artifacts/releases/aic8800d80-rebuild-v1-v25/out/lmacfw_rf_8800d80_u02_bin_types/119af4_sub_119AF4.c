// sub_119AF4 @ 0x119af4, size 54 bytes
int  sub_119AF4(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = sub_11BBA4(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)sub_11DDF0(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_11DE50(v10);
  }
  return 0;
}

