// v23 annotated: sub_1182F4 @ 0x1182f4
// Original: 1182f4_sub_1182F4.c
// Primary struct: <unclustered>
//
// sub_1182F4 @ 0x1182f4, size 22 bytes
int sub_1182F4()
{
  _DWORD *i; // r4
  int result; // r0

  for ( i = *((_DWORD **)off_11830C + 2); i; i = (_DWORD *)*i )
    result = sub_1182C8((int)i);
  return result;
}

