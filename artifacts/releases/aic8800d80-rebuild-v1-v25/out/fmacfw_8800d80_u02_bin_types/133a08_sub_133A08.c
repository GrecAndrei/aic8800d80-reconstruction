// sub_133A08 @ 0x133a08, size 72 bytes
int sub_133A08()
{
  if ( msg_get_value(6u) != 5 && msg_get_value(6u) != 6 && msg_get_value(6u) != 7 && msg_get_value(6u) != 8 )
    return 0;
  if ( *((uint8_t *)off_133A50 + 34) )
  {
    *((uint8_t *)off_133A50 + 34) = 0;
    return 0;
  }
  sub_134E04(1);
  return 0;
}

