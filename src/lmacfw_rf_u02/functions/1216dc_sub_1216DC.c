// process_event_lock @ 0x1216dc, size 12 bytes
void __noreturn process_event_lock()
{
  dispatch_event_handler(dword_1216E8);
  schedule_callbacks();
}

