// v23 annotated: list_count_d594 @ 0x12d594
// Original: 12d594_list_count_d594.c
// Primary struct: <unclustered>
//
// list_count_d594 @ 0x12d594, size 20 bytes
// Doc: list_count_d594 [util]: Count elements in a linked list
// list_count_d594 [util]: Count elements in a linked list
int __fastcall list_count_d594(_DWORD **a1)
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

