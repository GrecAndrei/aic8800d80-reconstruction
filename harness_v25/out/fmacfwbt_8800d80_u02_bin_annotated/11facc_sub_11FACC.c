// fwstruct annotate: 11facc_sub_11FACC.c
// sub_11FACC @ 0x11facc, size 38 bytes
int sub_11FACC()
{
  _DWORD *i; // r5
  _DWORD *j; // r4
  int result; // r0

  for ( i = *((_DWORD **)off_11FAF4 + 2); i; i = (_DWORD *)*i )
  {
    for ( j = (_DWORD *)i[60]; j; j = (_DWORD *)*j )
      result = sub_11F704((int)i, (int)j, 0);
  }
  return result;
}

