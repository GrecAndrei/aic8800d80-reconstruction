// get_hook_bits_6_8 @ 0x114b30, size 18 bytes
// Doc: rf_fault_dump_n3ec [rf]: Dump RF fault status byte via callback
// rf_fault_dump_n3ec [rf]: Dump RF fault status byte via callback
unsigned int get_hook_bits_6_8()
{
  return ((unsigned int)MEMD(508)(17) >> 6) & 7;
}

