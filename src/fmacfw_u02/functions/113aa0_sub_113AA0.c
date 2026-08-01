// bt_init @ 0x113aa0, size 18 bytes
int bt_init()
{
  int v0; // r1
  int v1; // r2

  irq_state_load(dword_113AB4);
  event_dispatch(dword_113AB8, v0, v1);
  return 1;
}

