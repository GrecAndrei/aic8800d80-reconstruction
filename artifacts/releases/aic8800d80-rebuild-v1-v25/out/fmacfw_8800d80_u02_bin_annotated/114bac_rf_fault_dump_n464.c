// fwstruct annotate: 114bac_rf_fault_dump_n464.c
// rf_fault_dump_n464 @ 0x114bac, size 10 bytes
// Doc: rf_fault_dump_n464 [rf]: Dump RF fault state via vectored call
// rf_fault_dump_n464 [rf]: Dump RF fault state via vectored call
int rf_fault_dump_n464()
{
  return MEMORY[0x1FC](27);
}

