// get_hook_bit_19 @ 0x114b84, size 18 bytes
// Doc: rf_fault_dump_n44d [rf]: Read RF fault status register and extract flag bit
// rf_fault_dump_n44d [rf]: Read RF fault status register and extract flag bit
unsigned int get_hook_bit_19()
{
  return ((unsigned int)MEMD(508)(15) >> 19) & 1;
}

