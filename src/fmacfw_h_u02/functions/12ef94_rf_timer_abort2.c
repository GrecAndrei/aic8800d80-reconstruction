// send_event_42d @ 0x12ef94, size 22 bytes
// Doc: send_event_42d [rf]: Duplicate entry: abort RF timer and send 0x42d control message
// send_event_42d [rf]: Duplicate entry: abort RF timer and send 0x42d control message
void __noreturn send_event_42d()
{
  alloc_tx_event(dword_12EFAC);
  invalid_handler_12c5fc(1069, 1);
  event_sync();
}

