// fwstruct annotate: 114b08_rf_fault_dump_n3c0.c
// rf_fault_dump_n3c0 @ 0x114b08, size 18 bytes
// Doc: rf_fault_dump_n3d0 [rf]: RF fault status dump via indirect call
// rf_fault_dump_n3d0 [rf]: RF fault status dump via indirect call
int rf_fault_dump_n3c0()
{
  return MEMORY[0x1FC](17) & 7;
}

