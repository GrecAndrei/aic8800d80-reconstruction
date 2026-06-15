// v23 annotated: sub_135A80 @ 0x135a80
// Original: 135a80_sub_135A80.c
// Primary struct: <unclustered>
//
// sub_135A80 @ 0x135a80, size 44 bytes
int __fastcall sub_135A80(int a1)
{
  _DWORD *v1; // r5

  v1 = off_135AAC;
  event_queue_push(6154, 6);
  sub_143770(a1, v1[4], 54);
  sub_12CA38(v1[4] - 12);
  v1[4] = a1;
  return queue_pending_check();
}

