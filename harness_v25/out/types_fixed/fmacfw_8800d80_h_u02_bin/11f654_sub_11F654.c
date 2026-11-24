// sub_11F654 @ 0x11f654, size 38 bytes
int sub_11F654()
{
  _DWORD *i; // r5
  _DWORD *j; // r4
  int result; // r0

  for ( i = *((_DWORD **)off_11F67C + 2); i; i = (_DWORD *)*i )
  {
    for ( j = (_DWORD *)i[60]; j; j = (_DWORD *)*j )
      result = sub_11F28C((int)i, (int)j, 0);
  }
  return result;
}

