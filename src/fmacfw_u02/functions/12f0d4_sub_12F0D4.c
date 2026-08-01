// log_event_1069 @ 0x12f0d4, size 22 bytes
void __noreturn log_event_1069()
{
  event_dispatch(dword_12F0EC);
  ke_int_lock(1069, 1);
  read_state_flag();
}

