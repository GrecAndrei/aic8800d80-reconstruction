// sub_103200 @ 0x103200, size 78 bytes
unsigned int  sub_103200(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_103250 + 362) )
      result = sub_102B80(0xB5u);
    *(uint32_t *)off_103254 |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_103250 + 362) )
      result = sub_102B80(0xC2u);
    *(uint32_t *)off_103254 &= ~2u;
  }
  return result;
}

