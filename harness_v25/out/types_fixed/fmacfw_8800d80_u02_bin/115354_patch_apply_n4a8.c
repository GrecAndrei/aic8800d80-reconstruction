// patch_apply_n4a8 @ 0x115354, size 50 bytes
// Doc: patch_apply_5380 [patch]: Apply firmware patch entry processing character '\'
// patch_apply_5380 [patch]: Apply firmware patch entry processing character '\'
void __noreturn patch_apply_n4a8()
{
  int byte_uart; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r1
  int v4; // r2

  sub_10DC24(dword_115388);
  if ( *(_BYTE *)(*(_DWORD *)off_11538C + 6) == 2 )
  {
    v2 = rf_bus_reset_n4a7();
    sub_10EE80(v2, v3, v4);
  }
  while ( 1 )
  {
    while ( !sub_10D7F8() )
      ;
    byte_uart = mmio_read_byte_uart();
    v1 = sub_130018(byte_uart);
    sub_130170(v1);
  }
}

