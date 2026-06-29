// sub_1342F4 @ 0x1342f4, size 54 bytes
uint32_t *sub_1342F4()
{
  uint32_t *v0; // r4
  uint16_t *v1; // r3
  int v2; // r0

  v0 = off_13432C;
  v1 = off_134330;
  v2 = *((uint32_t *)off_13432C + 4);
  *((uint8_t *)off_134330 + 13) = 0;
  v1[7] = 0;
  *((uint8_t *)v1 + 3) = 0;
  if ( v2 )
  {
    sub_12C8F8(v2 - 12);
    sub_12C8F8(v0[5] - 12);
  }
  sub_100200((int *)off_13432C, 0, 0x2Cu);
  return sub_12CBF4(6u, 0);
}

