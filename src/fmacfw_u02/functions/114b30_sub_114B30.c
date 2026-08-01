// get_hook_bits_6_8 @ 0x114b30, size 18 bytes
unsigned int get_hook_bits_6_8()
{
  return ((unsigned int)MEMD(508)(17) >> 6) & 7;
}

