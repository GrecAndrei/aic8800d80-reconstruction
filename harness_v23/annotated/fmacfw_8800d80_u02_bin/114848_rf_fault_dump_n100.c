// v23 annotated: rf_fault_dump_n100 @ 0x114848
// Original: 114848_rf_fault_dump_n100.c
// Primary struct: <unclustered>
//
// rf_fault_dump_n100 @ 0x114848, size 18 bytes
// Doc: rf_fault_dump_n104 [rf]: Dumps RF fault status bit and pops stack frame as tail call
// rf_fault_dump_n104 [rf]: Dumps RF fault status bit and pops stack frame as tail call
unsigned int rf_fault_dump_n100()
{
  return ((unsigned int)MEMORY[0x1FC](1) >> 9) & 1;
}

