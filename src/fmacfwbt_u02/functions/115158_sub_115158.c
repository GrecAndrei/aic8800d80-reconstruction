// get_hw_info_field1 @ 0x115158, size 18 bytes
unsigned int get_hw_info_field1()
{
  return ((unsigned int)MEMD(508)(17) >> 3) & 7;
}

