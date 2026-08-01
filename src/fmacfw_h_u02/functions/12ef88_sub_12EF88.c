// event_sync @ 0x12ef88, size 12 bytes
void __noreturn event_sync()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = get_phy_state();
  rf_set_frequency(v0, v1, v2);
  while ( 1 )
    ;
}

