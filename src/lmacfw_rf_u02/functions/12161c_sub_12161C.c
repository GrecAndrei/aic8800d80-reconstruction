// send_event_42d @ 0x12161c, size 22 bytes
void __noreturn send_event_42d()
{
  dispatch_event_handler(dword_121634);
  ke_int_lock(1069, 1);
  schedule_callbacks();
}

