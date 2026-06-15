// sub_10F7FC @ 0x10f7fc, size 24 bytes
// Doc: sub_120F7FC [unknown]: Unknown helper in lmacfw RF image
// sub_120F7FC [unknown]: Unknown helper in lmacfw RF image
int sub_10F7FC()
{
  int v0; // r0

  v0 = rf_setup_dispatch(1037, 1, 4, 8);
  return sub_11DE50(v0);
}

