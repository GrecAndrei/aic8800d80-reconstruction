// sub_136700 @ 0x136700, size 42 bytes
uint32_t *sub_136700()
{
  uint8_t *v0; // r4
  int v1; // r3

  v0 = off_13672C;
  sub_100200((int *)off_13672C, 0, 0x24u);
  v1 = dword_136730;
  v0[15] = 3;
  *((uint32_t *)v0 + 4) = 20000;
  *((uint32_t *)v0 + 6) = v1;
  v0[12] = 0;
  return sub_12CD34(7u, 0);
}

