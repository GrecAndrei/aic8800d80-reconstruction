// sub_133C24 @ 0x133c24, size 72 bytes
int sub_133C24()
{
  if ( msg_get_value(6u) != 5 && msg_get_value(6u) != 6 && msg_get_value(6u) != 7 && msg_get_value(6u) != 8 )
    return 0;
  if ( *((_BYTE *)off_133C6C + 34) )
  {
    *((_BYTE *)off_133C6C + 34) = 0;
    return 0;
  }
  sub_135020(1);
  return 0;
}

