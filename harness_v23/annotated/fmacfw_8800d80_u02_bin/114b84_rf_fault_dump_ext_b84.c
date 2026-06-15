// v23 annotated: rf_fault_dump_ext_b84 @ 0x114b84
// Original: 114b84_rf_fault_dump_ext_b84.c
// Primary struct: <unclustered>
//
// rf_fault_dump_ext_b84 @ 0x114b84, size 18 bytes
// Doc: rf_fault_dump_n44d [rf]: Read RF fault status register and extract flag bit
// rf_fault_dump_n44d [rf]: Read RF fault status register and extract flag bit
unsigned int rf_fault_dump_ext_b84()
{
  return ((unsigned int)MEMORY[0x1FC](15) >> 19) & 1;
}

