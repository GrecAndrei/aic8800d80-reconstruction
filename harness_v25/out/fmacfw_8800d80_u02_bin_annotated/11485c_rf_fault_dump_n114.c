// fwstruct annotate: 11485c_rf_fault_dump_n114.c
// rf_fault_dump_n114 @ 0x11485c, size 10 bytes
// Doc: rf_fault_dump_n116 [rf]: RF fault dump with indirect call dispatch
// rf_fault_dump_n116 [rf]: RF fault dump with indirect call dispatch
int rf_fault_dump_n114()
{
  return MEMORY[0x1FC](2);
}

