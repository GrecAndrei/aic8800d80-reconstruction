// sub_10CEF4 @ 0x10cef4, size 44 bytes
int sub_10CEF4()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_10CF20;
  while ( !*(_DWORD *)off_10CF20 )
    ;
  result = *(_DWORD *)(*(_DWORD *)off_10CF24 + 532);
  if ( result )
  {
    result = sub_11E7AC(*(_DWORD *)off_10CF24 + 532);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(_DWORD *)off_10CF20 = 1;
  }
  return result;
}

