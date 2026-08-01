// send_event_42c @ 0x12efb0, size 22 bytes
// Doc: send_event_42c [util]: Copy firmware config block via 0x42c message
// send_event_42c [util]: Copy firmware config block via 0x42c message
void __noreturn send_event_42c()
{
  alloc_tx_event(dword_12EFC8);
  invalid_handler_12c5fc(1068, 1);
  event_sync();
}

