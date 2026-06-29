// sub_139CF4 @ 0x139cf4, size 118 bytes
int sub_139CF4()
{
  uint32_t *v0; // r6
  int v1; // r4
  int v2; // r5
  uint32_t *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (uint32_t *)(dword_139D6C + 16);
  sub_12D240((uint32_t *)dword_139D6C);
  v1 = dword_139D70;
  sub_12D240(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (uint32_t *)v1;
    v1 += 292;
    sub_12D248((int)v0, v3);
  }
  while ( v1 != v2 );
  sub_12D240((uint32_t *)dword_139D74);
  sub_12D240((uint32_t *)dword_139D78);
  sub_12D248(dword_139D74, (uint32_t *)dword_139D7C);
  sub_12D248(dword_139D74, (uint32_t *)dword_139D80);
  sub_12D248(dword_139D74, (uint32_t *)dword_139D84);
  v4 = dword_139D8C;
  result = dword_139D90;
  *((uint16_t *)off_139D88 + 51) = -1;
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

