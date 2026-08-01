// read_state_flag @ 0x12f0c8, size 12 bytes
void __noreturn read_state_flag()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = patch_get_state();
  rf_set_channel(v0, v1, v2);
  while ( 1 )
    ;
}

