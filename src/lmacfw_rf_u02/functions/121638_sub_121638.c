// send_event_42c @ 0x121638, size 22 bytes
void __noreturn send_event_42c()
{
  dispatch_event_handler(dword_121650);
  ke_int_lock(1068, 1);
  schedule_callbacks();
}

