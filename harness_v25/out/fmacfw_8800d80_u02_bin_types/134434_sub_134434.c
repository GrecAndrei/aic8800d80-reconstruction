// sub_134434 @ 0x134434, size 54 bytes
// Doc: sub_1234434 [util]: Reset/clear a control structure's status fields and byte flags
// sub_1234434 [util]: Reset/clear a control structure's status fields and byte flags
uint32_t *sub_134434()
{
  uint32_t *v0; // r4
  uint16_t *v1; // r3
  int v2; // r0

  v0 = off_13446C;
  v1 = off_134470;
  v2 = *((uint32_t *)off_13446C + 4);
  *((uint8_t *)off_134470 + 13) = 0;
  v1[7] = 0;
  *((uint8_t *)v1 + 3) = 0;
  if ( v2 )
  {
    sub_12CA38(v2 - 12);
    sub_12CA38(v0[5] - 12);
  }
  memset_thunk((int *)off_13446C, 0, 0x2Cu);
  return sub_12CD34(6u, 0);
}

