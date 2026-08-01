// call_patch_1fc_check @ 0x114708, size 18 bytes
unsigned int call_patch_1fc_check()
{
  return ((unsigned int)MEMD(508)(1) >> 9) & 1;
}

