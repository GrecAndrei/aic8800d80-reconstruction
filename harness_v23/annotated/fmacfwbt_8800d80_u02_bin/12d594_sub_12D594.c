// v23 annotated: sub_12D594 @ 0x12d594
// Original: 12d594_sub_12D594.c
// Primary struct: delay_timer (cluster 0, 25 funcs)
// Fields: us=0x0, ticks=0x4
//
// sub_12D594 @ 0x12d594, size 20 bytes
int __fastcall sub_12D594(_DWORD **a1)
{
  _DWORD *v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    v1 = (_DWORD *)*v1;
    ++result;
  }
  while ( v1 );
  return result;
}

