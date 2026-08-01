// get_hook_bits_0_2 @ 0x114b08, size 18 bytes
// Doc: rf_fault_dump_n3d0 [rf]: RF fault status dump via indirect call
// rf_fault_dump_n3d0 [rf]: RF fault status dump via indirect call
int get_hook_bits_0_2()
{
  return MEMD(508)(17) & 7;
}

