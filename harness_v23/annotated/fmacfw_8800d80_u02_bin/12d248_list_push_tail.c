// v23 annotated: list_push_tail @ 0x12d248
// Original: 12d248_list_push_tail.c
// Primary struct: <unclustered>
//
// list_push_tail @ 0x12d248, size 60 bytes
// Doc: list_push_tail [util]: Append node to tail of intrusive linked list if list non-empty
// list_push_tail [util]: Append node to tail of intrusive linked list if list non-empty
int __fastcall list_push_tail(int result, _DWORD *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_12D284 < 0 && !a2 )
    result = sub_12F46C(dword_12D28C, dword_12D288, 72);
  if ( *(_DWORD *)v2 )
    **(_DWORD **)(v2 + 4) = a2;
  else
    *(_DWORD *)v2 = a2;
  *(_DWORD *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

