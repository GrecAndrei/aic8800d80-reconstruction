// sub_1119BC @ 0x1119bc, size 88 bytes
int  sub_1119BC(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  uint32_t *v6; // r2

  v2 = (int *)off_111A18;
  v3 = *(uint32_t *)off_111A14;
  v4 = *(uint32_t *)off_111A18;
  *((uint16_t *)off_111A1C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(uint32_t *)v4 = -1073741824;
  *(uint32_t *)(v4 + 4) = v3;
  *(uint8_t *)(v4 + 3) = v5;
  *(uint16_t *)v4 = a2;
  if ( result && a2 )
  {
    result = sub_143630(v3, result, a2);
    v4 = *v2;
  }
  v6 = off_111A20;
  *(uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

