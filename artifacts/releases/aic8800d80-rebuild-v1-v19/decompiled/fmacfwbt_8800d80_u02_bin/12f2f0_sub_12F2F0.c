// sub_12F2F0 @ 0x12f2f0, size 12 bytes
// Doc: sub_122F2F0 [bt]: BT init helper calling patch/bt functions and loading 0x16b00c
// sub_122F2F0 [bt]: BT init helper calling patch/bt functions and loading 0x16b00c
void __noreturn sub_12F2F0()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = sub_11565C();
  mmio_lmac_init_n_ecd8(v0, v1, v2);
  while ( 1 )
    ;
}

