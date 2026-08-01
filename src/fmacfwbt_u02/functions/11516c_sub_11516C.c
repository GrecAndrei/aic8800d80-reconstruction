// get_hw_info_field2 @ 0x11516c, size 18 bytes
// Doc: patch_apply_n_370 [patch]: Apply patch entry 370, pops saved regs and branches via return
// patch_apply_n_370 [patch]: Apply patch entry 370, pops saved regs and branches via return
unsigned int get_hw_info_field2()
{
  return ((unsigned int)MEMD(508)(17) >> 6) & 7;
}

