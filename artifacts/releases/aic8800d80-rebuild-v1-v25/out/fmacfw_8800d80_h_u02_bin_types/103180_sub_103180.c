// sub_103180 @ 0x103180, size 78 bytes
unsigned int  sub_103180(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_1031D0 + 362) )
      result = sub_102AD0(0xB5u);
    *(uint32_t *)off_1031D4 |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_1031D0 + 362) )
      result = sub_102AD0(0xC2u);
    *(uint32_t *)off_1031D4 &= ~2u;
  }
  return result;
}

