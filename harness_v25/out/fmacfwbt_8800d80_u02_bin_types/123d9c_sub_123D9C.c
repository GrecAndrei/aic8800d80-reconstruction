// sub_123D9C @ 0x123d9c, size 118 bytes
int  sub_123D9C(int a1, void ( **a2)(int), int a3)
{
  __int16 **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (__int16 **)off_123E14;
  if ( **(__int16 **)off_123E14 < 0 && sub_12D0B0(a3) == 4 )
    sub_12F694(dword_123E1C, dword_123E18, 1587);
  result = sub_12D0B0(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_12BA2C(result);
      sub_12CF5C(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_123E20 << 28 )
      sub_12F694(dword_123E24, dword_123E18, 1594);
    v7 = sub_12CF5C(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

