// sub_10DC78 @ 0x10dc78, size 48 bytes
int sub_10DC78()
{
  int result; // r0
  _DWORD *v1; // r3

  result = rf_reg_write_cb(dword_10DCA8, 1024, 15360);
  v1 = off_10DCAC;
  *((_DWORD *)off_10DCAC + 2) |= 0xFu;
  *(_DWORD *)(v1 + 0x8) |= 0x10000000u;
  *(_DWORD *)(v1 + 0xc) &= 0xFFFFF7FE;
  return result;
}

