// rf_fault_dump_n_1df @ 0x114568, size 6 bytes
// Doc: rf_fault_dump_n_1df [rf]: Dump RF fault state from shared trace buffer
// rf_fault_dump_n_1df [rf]: Dump RF fault state from shared trace buffer
int  rf_fault_dump_n_1df(int a1, int a2, int a3)
{
  return msg_parse(rf_fault_dump_n_1d8, a2, a3);
}

