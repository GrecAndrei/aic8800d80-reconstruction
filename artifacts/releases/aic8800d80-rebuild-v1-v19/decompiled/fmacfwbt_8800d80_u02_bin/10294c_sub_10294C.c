// sub_10294C @ 0x10294c, size 48 bytes
int sub_10294C()
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
    result = sub_12C7AC(i);
  }
  return result;
}

