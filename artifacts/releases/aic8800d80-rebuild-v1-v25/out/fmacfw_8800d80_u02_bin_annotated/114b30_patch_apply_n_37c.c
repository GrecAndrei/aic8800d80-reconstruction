// fwstruct annotate: 114b30_patch_apply_n_37c.c
// patch_apply_n_37c @ 0x114b30, size 18 bytes
// Doc: rf_fault_dump_n3ec [rf]: Dump RF fault status byte via callback
// rf_fault_dump_n3ec [rf]: Dump RF fault status byte via callback
unsigned int patch_apply_n_37c()
{
  return ((unsigned int)MEMORY[0x1FC](17) >> 6) & 7;
}

