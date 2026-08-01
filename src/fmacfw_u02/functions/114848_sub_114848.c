// get_hook_bit_9 @ 0x114848, size 18 bytes
unsigned int get_hook_bit_9()
{
  return ((unsigned int)MEMD(508)(1) >> 9) & 1;
}

