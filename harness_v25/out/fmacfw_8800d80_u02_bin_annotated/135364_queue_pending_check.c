// fwstruct annotate: 135364_queue_pending_check.c
// queue_pending_check @ 0x135364, size 44 bytes
// Doc: queue_pending_check [mac]: Check whether transmit/receive queue has pending entries
// queue_pending_check [mac]: Check whether transmit/receive queue has pending entries
int queue_pending_check()
{
  int v0; // r0

  v0 = feature_guard_check(256, dword_13553C, dword_135538);
  return sub_135390(v0);
}

