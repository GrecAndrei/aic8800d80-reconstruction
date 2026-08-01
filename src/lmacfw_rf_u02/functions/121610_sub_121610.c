// schedule_callbacks @ 0x121610, size 12 bytes
void __noreturn schedule_callbacks()
{
  int v0; // r0

  v0 = wait_hw_ready();
  ke_event_set(v0);
  while ( 1 )
    ;
}

