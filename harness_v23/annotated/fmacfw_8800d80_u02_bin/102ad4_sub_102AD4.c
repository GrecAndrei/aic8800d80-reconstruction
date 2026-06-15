// v23 annotated: sub_102AD4 @ 0x102ad4
// Original: 102ad4_sub_102AD4.c
// Primary struct: <unclustered>
//
// sub_102AD4 @ 0x102ad4, size 48 bytes
int sub_102AD4()
{
  int result; // r0
  int *i; // r4

  result = sub_1009A0(*((unsigned __int8 *)off_102B04 + 36), *((unsigned __int16 *)off_102B04 + 20));
  for ( i = *((int **)off_102B08 + 2); i; i = (int *)*i )
  {
    while ( !*((_BYTE *)i + 108) )
    {
      i = (int *)*i;
      if ( !i )
        return result;
    }
    result = message_dispatch_408(i);
  }
  return result;
}

