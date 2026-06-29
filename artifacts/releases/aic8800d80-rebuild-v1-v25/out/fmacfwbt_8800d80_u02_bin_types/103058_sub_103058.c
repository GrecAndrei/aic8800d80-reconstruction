// sub_103058 @ 0x103058, size 78 bytes
unsigned int  sub_103058(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_1030A8 + 362) )
      result = sub_1029F8(0xB5u);
    *(uint32_t *)off_1030AC |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_1030A8 + 362) )
      result = sub_1029F8(0xC2u);
    *(uint32_t *)off_1030AC &= ~2u;
  }
  return result;
}

