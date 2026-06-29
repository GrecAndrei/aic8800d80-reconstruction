// fwstruct annotate: 141520_sub_141520.c
// sub_141520 @ 0x141520, size 88 bytes
_DWORD *sub_141520()
{
  int v0; // r3
  int v1; // r0
  int v2; // r4
  _DWORD *result; // r0

  v0 = dword_141578;
  v1 = *(_DWORD *)(dword_141578 + 6480) + 1;
  *(_DWORD *)(dword_141578 + 6480) = v1;
  v2 = v0;
  do
  {
    if ( *(unsigned __int16 *)(v2 + 4) > 1u )
      *(_WORD *)(v2 + 4) = 1;
    v2 += 528;
  }
  while ( v2 != v0 + 6336 );
  if ( v1 >= *(_DWORD *)(v2 + 148) )
  {
    result = rf_bus_mark_n_3b7(0xBu, 0);
    *(_DWORD *)(v2 + 144) = -1;
  }
  else
  {
    rf_bus_mark_n_3b7(0xBu, 4);
    return (_DWORD *)message_dispatch_n84(11264, 11, 11);
  }
  return result;
}

