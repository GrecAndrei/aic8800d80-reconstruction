// v23 annotated: sub_133A08 @ 0x133a08
// Original: 133a08_sub_133A08.c
// Primary struct: <unclustered>
//
// sub_133A08 @ 0x133a08, size 72 bytes
int sub_133A08()
{
  if ( msg_get_value(6u) != 5 && msg_get_value(6u) != 6 && msg_get_value(6u) != 7 && msg_get_value(6u) != 8 )
    return 0;
  if ( *((_BYTE *)off_133A50 + 34) )
  {
    *((_BYTE *)off_133A50 + 34) = 0;
    return 0;
  }
  sub_134E04(1);
  return 0;
}

