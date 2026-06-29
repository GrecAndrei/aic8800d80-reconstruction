// sub_12917C @ 0x12917c, size 34 bytes
int  sub_12917C(int a1, __int16 a2)
{
  uint8_t *v2; // r2
  uint8_t *v3; // r3
  bool v4; // zf
  int (*v5)(void); // r3

  v2 = off_1291A4;
  v3 = *(uint8_t **)off_1291A0;
  *((uint16_t *)off_1291A4 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int (*)(void))off_1291A8;
  if ( !v4 && a1 )
    v5 = (int (*)(void))off_1291AC;
  v2[8] = 0;
  return v5();
}

