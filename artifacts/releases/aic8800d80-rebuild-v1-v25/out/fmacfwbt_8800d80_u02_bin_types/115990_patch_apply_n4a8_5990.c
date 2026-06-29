// patch_apply_n4a8_5990 @ 0x115990, size 50 bytes
// Doc: patch_apply_n4c2 [patch]: Apply firmware patch at given address
// patch_apply_n4c2 [patch]: Apply firmware patch at given address
void __noreturn patch_apply_n4a8_5990()
{
  int u8; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r1
  int v4; // r2

  log_printf(patch_apply_n4dc);
  if ( *(uint8_t *)(*(uint32_t *)off_1159C8 + 6) == 2 )
  {
    v2 = sub_11565C();
    mmio_lmac_init_n_ecd8(v2, v3, v4);
  }
  while ( 1 )
  {
    while ( !sub_10D650() )
      ;
    u8 = mmio_read_u8();
    v1 = sub_130234(u8);
    sub_13038C(v1);
  }
}

