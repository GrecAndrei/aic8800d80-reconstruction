// fwstruct annotate: 10cc50_sub_10CC50.c
// sub_10CC50 @ 0x10cc50, size 44 bytes
int sub_10CC50()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_10CC7C;
  while ( !*(_DWORD *)off_10CC7C )
    ;
  result = *(_DWORD *)(*(_DWORD *)off_10CC80 + 596);
  if ( result )
  {
    result = rf_bus_mark_n100_d2d0(*(_DWORD *)off_10CC80 + 596);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(_DWORD *)off_10CC7C = 1;
  }
  return result;
}

