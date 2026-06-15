// sub_10CAA8 @ 0x10caa8, size 44 bytes
int sub_10CAA8()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_10CAD4;
  while ( !*(_DWORD *)off_10CAD4 )
    ;
  result = *(_DWORD *)(*(_DWORD *)off_10CAD8 + 532);
  if ( result )
  {
    result = sub_12D4F8(*(_DWORD *)off_10CAD8 + 532);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(_DWORD *)off_10CAD4 = 1;
  }
  return result;
}

