// sub_12F0C8 @ 0x12f0c8, size 12 bytes
void __noreturn sub_12F0C8()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = rf_bus_reset_n4a7();
  sub_10EE80(v0, v1, v2);
  while ( 1 )
    ;
}

