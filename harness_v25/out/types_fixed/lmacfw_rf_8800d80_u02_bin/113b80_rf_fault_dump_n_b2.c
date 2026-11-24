// rf_fault_dump_n_b2 @ 0x113b80, size 8 bytes
// Doc: rf_fault_dump_n_b2 [rf]: Dump RF fault state, iterating up to 0x5c entries
// rf_fault_dump_n_b2 [rf]: Dump RF fault state, iterating up to 0x5c entries
int __fastcall rf_fault_dump_n_b2(int a1)
{
  return host_reg_wait_set(2u, a1);
}

