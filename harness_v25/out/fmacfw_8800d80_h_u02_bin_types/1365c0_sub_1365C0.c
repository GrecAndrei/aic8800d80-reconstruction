// sub_1365C0 @ 0x1365c0, size 42 bytes
uint32_t *sub_1365C0()
{
  uint8_t *v0; // r4
  int v1; // r3

  v0 = off_1365EC;
  sub_100200((int *)off_1365EC, 0, 0x24u);
  v1 = dword_1365F0;
  v0[15] = 3;
  *((uint32_t *)v0 + 4) = 20000;
  *((uint32_t *)v0 + 6) = v1;
  v0[12] = 0;
  return sub_12CBF4(7u, 0);
}

