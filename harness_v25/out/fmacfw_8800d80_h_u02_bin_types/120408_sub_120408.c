// sub_120408 @ 0x120408, size 82 bytes
int sub_120408()
{
  uint8_t *v0; // r4
  int v1; // r3
  __int16 *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = off_12045C;
  sub_100200((int *)off_12045C, 0, 0x34u);
  v1 = dword_120464;
  v2 = *(__int16 **)off_120460;
  *(uint32_t *)v0 = dword_120464;
  v0[31] = 1;
  *((uint16_t *)v0 + 9) = 0;
  v3 = *v2;
  *((uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(uint32_t *)off_120470 << 28 )
  {
    sub_12F35C(dword_120478, dword_120474, 472);
    v1 = *(uint32_t *)v0 | *((uint32_t *)v0 + 1);
  }
  *(uint32_t *)off_120468 = v1;
  result = sub_120368();
  *((uint32_t *)v0 + 9) = dword_12046C;
  return result;
}

