// sub_12B540 @ 0x12b540, size 72 bytes
// Doc: sub_122B540 [unknown]: Compares signed halfword from global state to zero
// sub_122B540 [unknown]: Compares signed halfword from global state to zero
int sub_12B540()
{
  uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(__int16 **)off_12B588 < 0 && *(uint32_t *)off_12B594 << 28 )
    return fmac_phy_op_handler(dword_12B59C, dword_12B598, 105, *(uint32_t *)off_12B594);
  if ( (*(uint32_t *)off_12B58C & 0x80) != 0 )
  {
    v0 = off_12B590;
    v1 = *((uint32_t *)off_12B590 + 1) & 0xFFFFFFFB;
    *(uint32_t *)off_12B58C &= ~0x80u;
    v0[1] = v1;
    return irq_nesting_or_d104(0x2000000);
  }
  return result;
}

