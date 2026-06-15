// v23 annotated: rf_fault_dump_n36e @ 0x121610
// Original: 121610_rf_fault_dump_n36e.c
// Primary struct: <unclustered>
//
// rf_fault_dump_n36e @ 0x121610, size 12 bytes
// Doc: rf_fault_dump_n36e [rf]: Dump RF fault state with shifted/scaled byte output
// rf_fault_dump_n36e [rf]: Dump RF fault state with shifted/scaled byte output
void __noreturn rf_fault_dump_n36e()
{
  int v0; // r0

  v0 = rf_mode_check();
  rf_state_check_n2ae(v0);
  while ( 1 )
    ;
}

