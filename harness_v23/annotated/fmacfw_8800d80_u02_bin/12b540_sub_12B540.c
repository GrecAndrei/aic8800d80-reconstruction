// v23 annotated: sub_12B540 @ 0x12b540
// Original: 12b540_sub_12B540.c
// Primary struct: group_27 (cluster 27)
//
// sub_12B540 @ 0x12b540, size 72 bytes
// Doc: sub_122B540 [unknown]: Compares signed halfword from global state to zero
// sub_122B540 [unknown]: Compares signed halfword from global state to zero
int sub_12B540()
{
  _DWORD *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(__int16 **)off_12B588 < 0 && *(_DWORD *)off_12B594 << 28 )
    return fmac_phy_op_handler(dword_12B59C, dword_12B598, 105, *(_DWORD *)off_12B594);
  if ( (*(_DWORD *)off_12B58C & 0x80) != 0 )
  {
    v0 = off_12B590;
    v1 = *((_DWORD *)off_12B590 + 1) & 0xFFFFFFFB;
    *(_DWORD *)off_12B58C &= ~0x80u;
    v0[1] = v1;
    return irq_nesting_or_d104(0x2000000);
  }
  return result;
}

