// sub_116AC0 @ 0x116ac0, size 48 bytes
int  sub_116AC0(uint8_t *a1, char a2)
{
  int v2; // r6
  int v4; // r5

  v2 = dword_116AF0;
  v4 = 696 * (unsigned __int8)a1[29];
  a1[27] = a2;
  a1[97] = 1;
  sub_12D470(v4 + 572 + v2);
  return sub_136C94(a1, v2 + v4);
}

