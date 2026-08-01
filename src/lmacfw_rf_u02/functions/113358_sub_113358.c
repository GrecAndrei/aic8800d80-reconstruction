// init_driver_states @ 0x113358, size 18 bytes
int init_driver_states()
{
  int v0; // r1

  wait_rf_ready(dword_11336C);
  dispatch_event_handler(dword_113370, v0);
  return 1;
}

