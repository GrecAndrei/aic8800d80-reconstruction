// rf_msg_handler_n_13a @ 0x10294c, size 48 bytes
// Doc: rf_msg_handler_n_13a [rf]: Handle incoming RF message and clear flag
// rf_msg_handler_n_13a [rf]: Handle incoming RF message and clear flag
int rf_msg_handler_n_13a()
{
  int result; // r0
  int *i; // r4

  result = sub_1009A0(*((unsigned __int8 *)off_10297C + 36), *((unsigned __int16 *)off_10297C + 20));
  for ( i = *((int **)off_102980 + 2); i; i = (int *)*i )
  {
    while ( !*((_BYTE *)i + 108) )
    {
      i = (int *)*i;
      if ( !i )
        return result;
    }
    result = message_dispatch_c7ac(i);
  }
  return result;
}

