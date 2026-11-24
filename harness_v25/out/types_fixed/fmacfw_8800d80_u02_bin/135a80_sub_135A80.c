// sub_135A80 @ 0x135a80, size 44 bytes
int __fastcall sub_135A80(int a1)
{
  _DWORD *v1; // r5

  v1 = off_135AAC;
  event_queue_push(6154, 6);
  sub_143770(a1, *(_DWORD *)(v1 + 0x10), 54);
  sub_12CA38(*(_DWORD *)(v1 + 0x10) - 12);
  *(_DWORD *)(v1 + 0x10) = a1;
  return queue_pending_check();
}

