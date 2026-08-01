// get_hook_bit_9 @ 0x114848, size 18 bytes
// Doc: rf_fault_dump_n104 [rf]: Dumps RF fault status bit and pops stack frame as tail call
// rf_fault_dump_n104 [rf]: Dumps RF fault status bit and pops stack frame as tail call
unsigned int get_hook_bit_9()
{
  return ((unsigned int)MEMD(508)(1) >> 9) & 1;
}

