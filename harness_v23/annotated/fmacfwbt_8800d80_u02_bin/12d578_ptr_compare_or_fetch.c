// v23 annotated: ptr_compare_or_fetch @ 0x12d578
// Original: 12d578_ptr_compare_or_fetch.c
// Primary struct: delay_timer (cluster 0, 25 funcs)
// Fields: us=0x0, ticks=0x4
//
// ptr_compare_or_fetch @ 0x12d578, size 26 bytes
// Doc: ptr_compare_or_fetch [util]: Compare pointer at r0 against r1 value
// ptr_compare_or_fetch [util]: Compare pointer at r0 against r1 value
BOOL __fastcall ptr_compare_or_fetch(_DWORD **a1, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( v2 )
  {
    v2 = (_DWORD *)*v2;
    if ( a2 == v2 )
      return 1;
  }
  return a2 == nullptr;
}

