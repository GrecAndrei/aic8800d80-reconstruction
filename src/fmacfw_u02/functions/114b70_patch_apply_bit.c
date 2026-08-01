// get_hook_bit_18 @ 0x114b70, size 18 bytes
// Doc: rf_fault_dump_n42c [rf]: Dumps RF fault state to a sink callback
// rf_fault_dump_n42c [rf]: Dumps RF fault state to a sink callback
unsigned int get_hook_bit_18()
{
  return ((unsigned int)MEMD(508)(15) >> 18) & 1;
}

