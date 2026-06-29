// sub_10DE08 @ 0x10de08, size 18 bytes
int sub_10DE08()
{
  if ( *((uint8_t *)off_10DE1C + 369) )
    return rf_mem_read_n47e(2);
  else
    return sub_10DD14(2);
}

