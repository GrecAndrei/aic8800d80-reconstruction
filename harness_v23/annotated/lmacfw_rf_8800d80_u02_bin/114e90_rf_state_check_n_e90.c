// v23 annotated: rf_state_check_n_e90 @ 0x114e90
// Original: 114e90_rf_state_check_n_e90.c
// Primary struct: <unclustered>
//
// rf_state_check_n_e90 @ 0x114e90, size 50 bytes
// Doc: rf_state_check_n_e90 [util]: Check RF state byte against expected value 2
// rf_state_check_n_e90 [util]: Check RF state byte against expected value 2
void __noreturn rf_state_check_n_e90()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0

  sub_10DA6C(dword_114EC4);
  if ( *(_BYTE *)(*(_DWORD *)off_114EC8 + 6) == 2 )
  {
    v2 = rf_mode_check();
    rf_state_check_n2ae(v2);
  }
  while ( 1 )
  {
    while ( !mmio_reg_bit0_read() )
      ;
    v0 = sub_10D680();
    v1 = rf_init_or_reset(v0);
    sub_123240(v1);
  }
}

