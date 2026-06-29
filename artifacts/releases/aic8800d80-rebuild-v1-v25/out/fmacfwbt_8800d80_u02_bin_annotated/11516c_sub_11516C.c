// fwstruct annotate: 11516c_sub_11516C.c
// sub_11516C @ 0x11516c, size 18 bytes
// Doc: patch_apply_n_370 [patch]: Apply patch entry 370, pops saved regs and branches via return
// patch_apply_n_370 [patch]: Apply patch entry 370, pops saved regs and branches via return
unsigned int sub_11516C()
{
  return ((unsigned int)MEMORY[0x1FC](17) >> 6) & 7;
}

