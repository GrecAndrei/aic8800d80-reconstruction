// sub_139BB4 @ 0x139bb4, size 118 bytes
int sub_139BB4()
{
  uint32_t *v0; // r6
  int v1; // r4
  int v2; // r5
  uint32_t *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (uint32_t *)(dword_139C2C + 16);
  sub_12D100((uint32_t *)dword_139C2C);
  v1 = dword_139C30;
  sub_12D100(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (uint32_t *)v1;
    v1 += 292;
    sub_12D108((int)v0, v3);
  }
  while ( v1 != v2 );
  sub_12D100((uint32_t *)dword_139C34);
  sub_12D100((uint32_t *)dword_139C38);
  sub_12D108(dword_139C34, (uint32_t *)dword_139C3C);
  sub_12D108(dword_139C34, (uint32_t *)dword_139C40);
  sub_12D108(dword_139C34, (uint32_t *)dword_139C44);
  v4 = dword_139C4C;
  result = dword_139C50;
  *((uint16_t *)off_139C48 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(uint8_t *)(v4 - 52) = 0;
    *(uint16_t *)(v4 + 8) = 0;
    *(uint32_t *)(v4 - 64) = result;
    *(uint32_t *)(v4 - 60) = v4;
    *(uint32_t *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}

