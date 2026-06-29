// mmio_field_set_l2h2 @ 0x124178, size 26 bytes
// Doc: mmio_field_set_l2h2 [mmio]: Clear/set 0x40000 bitfield in control register and trigger handler
// mmio_field_set_l2h2 [mmio]: Clear/set 0x40000 bitfield in control register and trigger handler
int  mmio_field_set_l2h2(int a1)
{
  unsigned int v1; // r1
  int v2; // r0

  v1 = *(uint32_t *)off_124194 & 0xFFFBFFFF | (a1 << 18);
  v2 = dword_124198;
  *(uint32_t *)off_124194 = v1;
  msg_parse(v2);
  return 0;
}

