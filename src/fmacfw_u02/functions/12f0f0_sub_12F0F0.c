// log_event_1068 @ 0x12f0f0, size 22 bytes
void __noreturn log_event_1068()
{
  event_dispatch(dword_12F108);
  ke_int_lock(1068, 1);
  read_state_flag();
}

