// v23 annotated: list_count @ 0x12d36c
// Original: 12d36c_list_count.c
// Primary struct: <unclustered>
//
// list_count @ 0x12d36c, size 20 bytes
// Doc: list_count [util]: Return node count loaded from list head pointer (linked-list length helper)
// list_count [util]: Return node count loaded from list head pointer (linked-list length helper)
int __fastcall list_count(_DWORD **a1)
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

