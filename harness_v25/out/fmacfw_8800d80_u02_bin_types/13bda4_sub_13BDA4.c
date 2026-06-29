// sub_13BDA4 @ 0x13bda4, size 96 bytes
int  sub_13BDA4(bool a1, int a2)
{
  unsigned int v2; // r5
  bool *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (unsigned __int16)((uint16_t)a2 << 8) | 8;
  v5 = (bool *)sub_12C92C(42, 0, ((uint16_t)a2 << 8) | 8, 3u);
  if ( **(__int16 **)off_13BE04 < 0 && sub_12CE88(v2) != 4 )
    sub_12F46C(dword_13BE10, dword_13BE0C, 891);
  v6 = dword_13BE08 + 32 * a2;
  v7 = *(unsigned __int8 *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(uint8_t *)(v6 + 22);
  return sub_12C98C((int)v5);
}

