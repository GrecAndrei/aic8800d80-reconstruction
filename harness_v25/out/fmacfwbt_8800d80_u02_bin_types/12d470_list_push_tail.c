// list_push_tail @ 0x12d470, size 60 bytes
// Doc: list_push_tail [util]: Append node to tail of linked list
// list_push_tail [util]: Append node to tail of linked list
int  list_push_tail(int result, uint32_t *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_12D4AC < 0 && !a2 )
    result = sub_12F694(dword_12D4B4, dword_12D4B0, 72);
  if ( *(uint32_t *)v2 )
    **(uint32_t **)(v2 + 4) = a2;
  else
    *(uint32_t *)v2 = a2;
  *(uint32_t *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

