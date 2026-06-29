// sub_123690 @ 0x123690, size 54 bytes
int  sub_123690(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = sub_127B5C(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)sub_12C92C(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_12C98C(v10);
  }
  return 0;
}

