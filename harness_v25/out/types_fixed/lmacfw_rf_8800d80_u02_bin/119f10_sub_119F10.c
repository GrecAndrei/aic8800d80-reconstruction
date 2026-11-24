// sub_119F10 @ 0x119f10, size 118 bytes
int __fastcall sub_119F10(int a1, void (__fastcall **a2)(int), int a3)
{
  __int16 **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (__int16 **)off_119F88;
  if ( **(__int16 **)off_119F88 < 0 && sub_11E34C(a3) == 4 )
    sub_1219C4(dword_119F90, dword_119F8C, 1587);
  result = sub_11E34C(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_11D01C();
      sub_11E1E4(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(_DWORD *)off_119F94 << 28 )
      sub_1219C4(dword_119F98, dword_119F8C, 1594);
    v7 = sub_11E1E4(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

