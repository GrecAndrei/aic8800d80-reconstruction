// rf_fault_dump_n_1ec @ 0x11455c, size 6 bytes
// Doc: rf_fault_dump_n_1ec [rf]: RF fault dump entry referencing fault table
// rf_fault_dump_n_1ec [rf]: RF fault dump entry referencing fault table
int  rf_fault_dump_n_1ec(int a1, int a2, int a3)
{
  return msg_parse(rf_fault_dump_564, a2, a3);
}

