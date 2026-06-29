// fwstruct annotate: 114b70_patch_apply_bit.c
// patch_apply_bit @ 0x114b70, size 18 bytes
// Doc: rf_fault_dump_n42c [rf]: Dumps RF fault state to a sink callback
// rf_fault_dump_n42c [rf]: Dumps RF fault state to a sink callback
unsigned int patch_apply_bit()
{
  return ((unsigned int)MEMORY[0x1FC](15) >> 18) & 1;
}

