// get_hw_info_bit9 @ 0x114e84, size 18 bytes
// Doc: get_hw_info_bit9 [bt]: Bluetooth power-save control handler
// get_hw_info_bit9 [bt]: Bluetooth power-save control handler
unsigned int get_hw_info_bit9()
{
  return ((unsigned int)MEMD(508)(1) >> 9) & 1;
}

