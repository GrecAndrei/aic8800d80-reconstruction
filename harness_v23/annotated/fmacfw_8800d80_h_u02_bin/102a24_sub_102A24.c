// v23 annotated: sub_102A24 @ 0x102a24
// Original: 102a24_sub_102A24.c
// Primary struct: <unclustered>
//
// sub_102A24 @ 0x102a24, size 48 bytes
int sub_102A24()
{
  int result; // r0
  int *i; // r4

  result = sub_1009A0(*((unsigned __int8 *)off_102A54 + 36), *((unsigned __int16 *)off_102A54 + 20));
  for ( i = *((int **)off_102A58 + 2); i; i = (int *)*i )
  {
    while ( !*((_BYTE *)i + 108) )
    {
      i = (int *)*i;
      if ( !i )
        return result;
    }
    result = sub_12C444(i);
  }
  return result;
}

