// fwstruct annotate: 11f794_sub_11F794.c
// sub_11F794 @ 0x11f794, size 38 bytes
// Doc: sub_121F794 [unknown]: Trampoline helper loading from constant pointer table
// sub_121F794 [unknown]: Trampoline helper loading from constant pointer table
int sub_11F794()
{
  _DWORD *i; // r5
  _DWORD *j; // r4
  int result; // r0

  for ( i = *((_DWORD **)off_11F7BC + 2); i; i = (_DWORD *)*i )
  {
    for ( j = (_DWORD *)i[60]; j; j = (_DWORD *)*j )
      result = sub_11F3CC((int)i, (int)j, 0);
  }
  return result;
}

