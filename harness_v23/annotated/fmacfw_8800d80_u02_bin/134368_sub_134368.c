// v23 annotated: sub_134368 @ 0x134368
// Original: 134368_sub_134368.c
// Primary struct: <unclustered>
//
// sub_134368 @ 0x134368, size 26 bytes
int sub_134368()
{
  int result; // r0

  msg_parse(dword_134384);
  result = event_queue_push(6155, 6);
  *((_BYTE *)off_134388 + 15) = 0;
  return result;
}

