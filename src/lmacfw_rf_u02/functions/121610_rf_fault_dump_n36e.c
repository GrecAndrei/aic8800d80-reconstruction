// schedule_callbacks @ 0x121610, size 12 bytes
// Doc: schedule_callbacks [rf]: Dump RF fault state with shifted/scaled byte output
// schedule_callbacks [rf]: Dump RF fault state with shifted/scaled byte output
void __noreturn schedule_callbacks()
{
  int v0; // r0

  v0 = wait_hw_ready();
  ke_event_set(v0);
  while ( 1 )
    ;
}

