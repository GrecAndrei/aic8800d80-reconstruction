// fwstruct annotate: 10cb10_sub_10CB10.c
// sub_10CB10 @ 0x10cb10, size 44 bytes
int sub_10CB10()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_10CB3C;
  while ( !*(_DWORD *)off_10CB3C )
    ;
  result = *(_DWORD *)(*(_DWORD *)off_10CB40 + 596);
  if ( result )
  {
    result = sub_12D190(*(_DWORD *)off_10CB40 + 596);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(_DWORD *)off_10CB3C = 1;
  }
  return result;
}

