// v23 annotated: list_push_tail @ 0x12d470
// Original: 12d470_list_push_tail.c
// Primary struct: <unclustered>
//
// list_push_tail @ 0x12d470, size 60 bytes
// Doc: list_push_tail [util]: Append node to tail of linked list
// list_push_tail [util]: Append node to tail of linked list
int __fastcall list_push_tail(int result, _DWORD *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_12D4AC < 0 && !a2 )
    result = sub_12F694(dword_12D4B4, dword_12D4B0, 72);
  if ( *(_DWORD *)v2 )
    **(_DWORD **)(v2 + 4) = a2;
  else
    *(_DWORD *)v2 = a2;
  *(_DWORD *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

