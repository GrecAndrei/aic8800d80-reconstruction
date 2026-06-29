// sub_10DC78 @ 0x10dc78, size 48 bytes
int sub_10DC78()
{
  int result; // r0
  uint32_t *v1; // r3

  result = rf_reg_write_cb(dword_10DCA8, 1024, 15360);
  v1 = off_10DCAC;
  *((uint32_t *)off_10DCAC + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

